//
//  maximum_subarray.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/2.
//

#include "maximum_subarray.hpp"
#include <vector>

using namespace std;

// 动态规划解法
int maxSubArray(vector<int>& nums) {
    int preVal = 0, maxVal = nums[0];
    for (int x : nums) {
        preVal = max(preVal + x, x);
        maxVal = max(preVal, maxVal);
    }
    return maxVal;
}
