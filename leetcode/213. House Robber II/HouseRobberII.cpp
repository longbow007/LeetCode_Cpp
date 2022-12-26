//
//  HouseRobberII.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/12/26.
//

#include "HouseRobberII.hpp"
#include <vector>

using namespace std;

class HouseRobberIISolution {
public:
    int robHelper(vector<int>& nums, int start, int end) {
        // dp[n] = max(dp[n-1], dp[n-2] + nums[n])
        int n = end - start + 1;
        int p = nums[start];
        if (n == 1) { return p; }
        int q = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; i++) {
            int r = max(p + nums[i], q);
            p = q;
            q = r;
        }
        return q;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return nums[0];
        }
        return max(robHelper(nums, 0, n - 2), robHelper(nums, 1, n - 1));
    }
};
