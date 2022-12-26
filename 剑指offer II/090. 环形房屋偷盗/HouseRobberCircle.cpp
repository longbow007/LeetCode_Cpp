//
//  HouseRobberCircle.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/12/26.
//

#include "HouseRobberCircle.hpp"
#include <vector>

using namespace std;

class HouseRobberCircleSolution {
public:
    int robHelper(vector<int>& nums, int start, int count) {
        int p = nums[start];
        if (count <= 1) {
            return p;
        }
        int q = max(p, nums[start + 1]);
        if (count == 2) {
            return q;
        }
        for (int i = start + 2; i < start + count; i++) {
            int r = max(p + nums[i], q);
            p = q;
            q = r;
        }
        return q;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        int rob1 = robHelper(nums, 0, n - 1);
        int rob2 = robHelper(nums, 1, n - 1);
        return max(rob1, rob2);
    }
};
