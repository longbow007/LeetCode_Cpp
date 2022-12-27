//
//  RotateImage.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/12/27.
//

#include "RotateImage.hpp"
#include <vector>

using namespace std;

class RotateImageSolution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < n/2; i++) {
            for (int j = 0; j < n; j++) {
                swap(matrix[j][i], matrix[j][n - i - 1]);
            }
        }
    }
};
