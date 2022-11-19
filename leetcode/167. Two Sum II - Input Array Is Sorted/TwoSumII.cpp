//
//  TwoSumII.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/11/5.
//

#include "TwoSumII.hpp"
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum == target) {
                return {l+1, r+1};
            } else if (sum < target) {
                l++;
            } else {
                r--;
            }
        }
        return {};
    }
};
