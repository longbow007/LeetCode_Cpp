//
//  RangeAddition.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/12/27.
//

#include "RangeAddition.hpp"
#include <vector>

using namespace std;

class RangeAdditionSolution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> diff = vector<int>(length, 0);
        for (int i = 0; i < updates.size(); i++) {
            vector<int> update = updates[i];
            int start = update[0];
            int end = update[1];
            int inc = update[2];
            diff[start] += inc;
            if (end + 1 < length) {
                diff[end + 1] -= inc;
            }
        }
        vector<int> res = vector<int>(length, 0);
        int t = 0;
        for (int i = 0; i < length; i++) {
            res[i] = t + diff[i];
            t = res[i];
        }

        return res;
    }
};
