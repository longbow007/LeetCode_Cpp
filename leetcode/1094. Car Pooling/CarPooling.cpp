//
//  CarPooling.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/12/27.
//

#include "CarPooling.hpp"
#include <vector>

using namespace std;

class CarPoolingSolution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = 1001;
        auto diffArray = vector<int>(n, 0);
        for (auto trip : trips) {
            int num = trip[0];
            int from = trip[1];
            int to = trip[2];
            diffArray[from] += num;
            if (to < n) {
                diffArray[to] -= num;
            }
        }
        int t = 0;
        for (auto num : diffArray) {
            int sum = t + num;
            if (sum > capacity) {
                return false;
            }
            t = sum;
        }
        return true;
    }
};
