//
//  valid_sudoku.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/2.
//

#include "valid_sudoku.hpp"
#include <vector>
#include "stdlib.h"

using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    int row[9], col[9], area[9];
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    memset(area, 0, sizeof(area));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char c = board[i][j];
            if (c == '.') continue;
            int a = c - '0';
            int k = i / 3 * 3 + j / 3;
            if (((row[i] >> a) & 1) == 1 || ((col[j] >> a) & 1) == 1 || ((area[k] >> a) & 1) == 1) {
                return false;
            }
            row[i] |= (1 << a);
            col[j] |= (1 << a);
            area[k] |= (1 << a);
        }
    }
    return true;
}
