//
//  SpiralMatrixII.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/12/27.
//

#include "SpiralMatrixII.hpp"
#include <vector>

using namespace std;

class SpiralMatrixIISolution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int val = 1;
        int left = 0, right = n - 1, up = 0, down = n - 1;
        auto res = vector<vector<int>>(n, vector<int>(n, 0));
        int i = 0, j = 0;
        // 0:right 1:down 2:left 3:up
        int dir = 0;
        while (left <= right && up <= down) {
            res[i][j] = val;
            val++;
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
