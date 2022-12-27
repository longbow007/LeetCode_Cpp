//
//  RangeSumQueryImmutable.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/12/27.
//

#include "RangeSumQueryImmutable.hpp"
#include <vector>

using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        preSum = vector<int>(n + 1, 0);
        for (int i = 0; i < n; i++) {
            preSum[i + 1] = preSum[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return preSum[right+1] - preSum[left];
    }
private:
    vector<int> preSum;
};
