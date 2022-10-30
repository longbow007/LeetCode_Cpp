//
//  MaximumProductSubarray.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/8/26.
//

#include "MaximumProductSubarray.hpp"

class MaximumProductSubarraySolution {
public:
    int maxProduct(vector<int>& nums) {
        int maxVal = nums[0], minVal = maxVal, res = maxVal;
        for (int i = 1; i < nums.size(); i++) {
            int an = nums[i];
            int tempMax = maxVal * an, tempMin = minVal * an;
            maxVal = max(tempMax, max(tempMin, an));
            minVal = min(tempMin, min(tempMax, an));
            res = max(res, maxVal);
        }
        return res;
    }
};
