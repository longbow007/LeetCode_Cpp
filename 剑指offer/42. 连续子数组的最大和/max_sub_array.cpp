//
//  max_sub_array.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/4.
//

#include "max_sub_array.hpp"
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums) {
    // 动态规划
    // int preVal = 0, maxVal = nums[0];
    // for (int x : nums) {
    //     preVal = max(preVal + x, x);
    //     maxVal = max(preVal, maxVal);
    // }
    // return maxVal;

    // 动态规划，加输出下标
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
