//
//  maximum_subarray.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/2.
//

#include "maximum_subarray.hpp"

// 动态规划解法
int maximumSubArray(vector<int>& nums) {
    int preVal = 0, maxVal = nums[0];
    for (int x : nums) {
        preVal = max(preVal + x, x);
        maxVal = max(preVal, maxVal);
    }
    return maxVal;
}

int maximumSubArray2(vector<int>& nums) {
    int maxVal = nums[0];
    int start = 0, end = 0;
    int finalStart = 0, finalEnd = 0;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i - 1] > 0) {
            nums[i] += nums[i - 1];
            end = i;
        } else {
            start = i;
            end = i;
        }
        if (nums[i] > maxVal) {
            finalStart = start;
            finalEnd = end;
        }
        maxVal = max(maxVal, nums[i]);
    }
    printf("result: %d, index: %d, %d\n", maxVal, finalStart, finalEnd);
    return maxVal;
}
