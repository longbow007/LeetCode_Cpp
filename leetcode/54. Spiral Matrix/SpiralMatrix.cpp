//
//  SpiralMatrix.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/12/27.
//

#include "SpiralMatrix.hpp"
#include <vector>

using namespace std;

class SpiralMatrixSolution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left = 0, right = matrix[0].size() - 1, up = 0, down = matrix.size() - 1;
        auto res = vector<int>();
        int i = 0, j = 0;
        // 0:right 1:down 2:left 3:up
        int dir = 0;
        while (left <= right && up <= down) {
            res.push_back(matrix[i][j]);
            switch (dir) {
                case 0: {
                    if (j == right) {
                        dir = 1;
                        i++;
                        up++;
                    } else {
                        j++;
                    }
                    break;
                }
                case 1: {
                    if (i == down) {
                        dir = 2;
                        j--;
                        right--;
                    } else {
                        i++;
                    }
                    break;
                }
                case 2: {
                    if (j == left) {
                        dir = 3;
                        i--;
                        down--;
                    } else {
                        j--;
                    }
                    break;
                }
                case 3: {
                    if (i == up) {
                        dir = 0;
                        j++;
                        left++;
                    } else {
                        i--;
                    }
                    break;
                }
            }
        }
        return res;
    }
};
