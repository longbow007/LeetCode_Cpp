//
//  DuoZhuaYu.cpp
//  algorithm-cpp
//
//  Created by Xiaojian Duan on 2022/1/7.
//

#include "DuoZhuaYu.hpp"

using namespace std;

int depthFirstSearch(int** grid, int row, int column, int maxRow, int maxCol, int currentValue, int *tempGrid) {
    if (row < 0 || row >= maxRow) {
        return 0;
    }
    if (column < 0 || column >= maxCol) {
        return 0;
    }
    int index = row * maxCol + column;
    // 这个值已经访问过
    if (tempGrid[index] > 0) {
        return 0;
    }
    int *list = grid[row];
    int newValue = list[column];
    int result = 0;
    if (newValue == currentValue) {
        result = 1;
    }
    // 新遍历的点存起来
    tempGrid[index] = newValue;
    // 递归遍历上下左右4个点
    result += depthFirstSearch(grid, row - 1, column, maxRow, maxCol, newValue, tempGrid) +
              depthFirstSearch(grid, row + 1, column, maxRow, maxCol, newValue, tempGrid) +
              depthFirstSearch(grid, row, column - 1, maxRow, maxCol, newValue, tempGrid) +
              depthFirstSearch(grid, row, column + 1, maxRow, maxCol, newValue, tempGrid);
    return result;
}

int depthFirstSearchCpp(vector<vector<int>> vect, int row, int column, int maxRow, int maxCol, int currentValue, vector<vector<int>> tempVect) {
    if (row < 0 || row >= maxRow) {
        return 0;
    }
    if (column < 0 || column >= maxCol) {
        return 0;
    }
    // 这个值已经访问过
    if (tempVect[row][column] > 0) {
        return 0;
    }
    int newValue = vect[row][column];
    int result = 0;
    if (newValue == currentValue) {
        result = 1;
    } else {
        return result;
    }
    cout << "current: " << currentValue << " new: " << newValue << " " << row << ", " << column << endl;
    tempVect[row][column] = newValue;
    result += depthFirstSearchCpp(vect, row - 1, column, maxRow, maxCol, newValue, tempVect) +
              depthFirstSearchCpp(vect, row + 1, column, maxRow, maxCol, newValue, tempVect) +
              depthFirstSearchCpp(vect, row, column - 1, maxRow, maxCol, newValue, tempVect) +
              depthFirstSearchCpp(vect, row, column + 1, maxRow, maxCol, newValue, tempVect);
    cout << "temp result: " << result << endl;
    return result;
}

int categoryOfMaxWarehouseAreaCpp(vector<vector<int>> vect, int m, int n) {
    // 每次遍历过的点存在 tempVect 里面
    vector<vector<int>> tempVect(m, vector<int>(n));
    cout << "matrix:\n";
    for (int i = 0; i < tempVect.size(); i++) {
        for (int j = 0; j < tempVect[i].size(); j++) {
            cout << tempVect[i][j] << " ";
        }
        cout << "\n";
    }
    int result = 0;
    for (int i = 0; i < vect.size(); i++) {
        for (int j = 0; j < vect[i].size(); j++) {
            int curValue = vect[i][j];
            int tempResult = depthFirstSearchCpp(vect, i, j, m, n, curValue, tempVect);
            if (tempResult > result) {
                result = tempResult;
            }
        }
    }
    return result;
}

int categoryOfMaxWarehouseArea(int** grid, int gridRowLen, int* gridColLen ) {
    
    // 每次遍历过的点存在 tempGrid 里面
    int count = gridRowLen * *gridColLen;
    int *tempGrid = (int *)malloc(sizeof(int) * count);
    memset(tempGrid, 0, sizeof(tempGrid) * count);
    printf("matrix:\n");
    for (int i = 0; i < count; i++) {
        printf("%d, ", tempGrid[i]);
        if ((i + 1) % *gridColLen == 0) {
            printf("\n");
        }
    }
    int result = 0;
    for (int i = 0; i < gridRowLen; i++) {
        for (int j = 0; j < *gridColLen; j++) {
            int *list = grid[i];
            int curValue = list[j];
            int tempResult = depthFirstSearch(grid, i, j, gridRowLen, *gridColLen, curValue, tempGrid);
            if (tempResult > result) {
                result = tempResult;
            }
        }
    }
    free(tempGrid);
    return result;
}


int visit(int dim, int rowMin, int colMin, int rowMax, int colMax, int currentValue, int *array) {
    int row = rowMin, col = colMin;
    int value = currentValue;
    int index = dim * row + col;
    
    while (array[index] == 0) {
        array[index] = value;
        value++;
        if (col == colMin) {
            // col 不变，row++，向下移动
            if (row >= rowMax) {
                // 碰到底部，改为向右上方移动
                row--;
                col++;
            } else {
                row++;
            }
        } else if (row < rowMax && row > rowMin && col < colMax && col > colMin) {
            // row--, col++，向右上方移动
            if (col >= colMax) {
                // 碰到右边缘，改为向左移动
                row = rowMin;
                col--;
            } else {
                row--;
                col++;
            }
        } else if (row == rowMin) {
            // row 不变，col--，向左移动
            if (col <= colMin) {
                // 碰到左边缘，开始下一个循环
                break;
            } else {
                col--;
            }
        } else {
            printf("error：不该有这种情况");
        }
        index = dim * row + col;
    }
    return value;
}

int* numberOfShelves(int N, int* returnSize ) {
    if (N <= 0) {
        return NULL;
    }
    *returnSize = (1 + N) * N * 0.5;
    int *result = (int *)malloc(sizeof(int) * *returnSize);
    if (N == 1) {
        result[0] = 1;
        return result;
    }
    int rowMin = 0, colMin = 0, rowMax = N - 1, colMax = N - 1;
    // 初始化矩阵
    int arraySize = N * N;
    int *array = (int *)malloc(sizeof(int) * arraySize);
    memset(array, 0, sizeof(array) * arraySize);
    // 遍历最外层的三角形
    int currentValue = visit(N, rowMin, colMin, rowMax, colMax, 1, array);
//    printf("matrix:\n");
//    for (int i = 0; i < N * N; i++) {
//        printf("%d, ", array[i]);
//        if ((i + 1) % N == 0) {
//            printf("\n");
//        }
//    }
    while (rowMin < rowMax && colMin < colMax) {
        rowMin++;
        colMin++;
        // 最大行列 -2 是因为从下往右上方移动过程中遍历了等腰三角形的底，下次循环前如果只 -1 的话会导致底重复访问
        rowMax -= 2;
        colMax -= 2;
        if (rowMax < rowMin || colMax < colMin) {
            break;
        }
        // 遍历内层三角形
        currentValue = visit(N, rowMin, colMin, rowMax, colMax, currentValue, array);
    }
    // 遍历矩阵，把每一行的值保存在 result 中
    int idx = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int value = array[i * N + j];
            if (value > 0) {
                result[idx] = value;
                idx++;
            }
        }
    }
    printf("matrix:\n");
    for (idx = 0; idx < N * N; idx++) {
        printf("%d, ", array[idx]);
        if ((idx + 1) % N == 0) {
            printf("\n");
        }
    }
    return result;
}
