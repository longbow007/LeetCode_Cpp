//
//  SpiralOrder.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/12/26.
//

#include "SpiralOrder.hpp"
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        int m = matrix.size();  // 行数
        int n = matrix[0].size();  // 列数
        int top = 0, left = 0, right = n - 1, bottom = m - 1;  // 四周边界
        vector<int> v(m * n);
        int cnt = 0;
        int i, j = 0;
        while (top <= bottom && left <= right) {
            // 向右
            for (int i = left; i <= right; i++) {
                v[cnt++] = matrix[top][i];
            }
            top++;
            if (top > bottom) break;
            // 向下
            for (int i = top; i <= bottom; i++) {
                v[cnt++] = matrix[i][right];
            }
            right--;
            if (right < left) break;
            // 向左
            for (int i = right; i >= left; i--) {
                v[cnt++] = matrix[bottom][i];
            }
            bottom--;
            if (bottom < top) break;
            // 向上
            for (int i = bottom; i >= top; i--) {
                v[cnt++] = matrix[i][left];
            }
            left++;
            if (left > right) break;
        }
        return v;
    }
};
