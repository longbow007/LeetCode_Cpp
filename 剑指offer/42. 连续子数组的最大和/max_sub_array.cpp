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
    int preVal = 0, maxVal = nums[0];
    for (int x : nums) {
        preVal = max(preVal + x, x);
        maxVal = max(preVal, maxVal);
    }
    return maxVal;
}
