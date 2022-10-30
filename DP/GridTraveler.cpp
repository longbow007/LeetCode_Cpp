//
//  GridTraveler.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/8/20.
//

#include "GridTraveler.hpp"
#include <iostream>
#include <vector>

using namespace std;

int gridTraveler(int m, int n) {
    if (m <= 0 || n <= 0) {
        return 0;
    }
    vector<vector<int>> v(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        v[i][0] = 1;
    }
    for (int j = 0; j < n; j++) {
        v[0][j] = 1;
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            v[i][j] = v[i-1][j] + v[i][j-1];
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return v[m-1][n-1];
}
