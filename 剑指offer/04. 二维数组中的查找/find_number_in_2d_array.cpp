//
//  find_number_in_2d_array.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/4.
//

#include "find_number_in_2d_array.hpp"
#include <vector>

using namespace std;

bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    if (n == 0) return false;
    int m = matrix[0].size();
    if (m == 0) return false;
    // 从右上角开始，向左下方遍历
    int row = 0, col = m - 1;
    while (row >= 0 && row < n && col >= 0 && col < m) {
        int cur = matrix[row][col];
        if (cur == target) return true;
        if (cur < target) {
            // 向下遍历
            row++;
        } else {
            // 向左遍历
            col--;
        }
    }
    // 出界了
    return false;
}
