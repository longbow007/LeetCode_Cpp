//
//  RangeSumQuery2DImmutable.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/12/27.
//

#include "RangeSumQuery2DImmutable.hpp"
#include <vector>

using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(); // 行数
        int n = matrix[0].size(); // 列数
        preSum = vector<vector<int>>(m+1, vector<int>(n+1, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                preSum[i+1][j+1] = preSum[i][j+1] + preSum[i+1][j] + matrix[i][j] - preSum[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return preSum[row2+1][col2+1] - preSum[row2+1][col1] - preSum[row1][col2+1] + preSum[row1][col1];
    }
private:
    // preSum[i][j] 表示 (0,0) ~ (i,j) 范围内的元素总和
    vector<vector<int>> preSum;
};
