//
//  HouseRobber.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/12/26.
//

#include "HouseRobber.hpp"
#include <vector>

using namespace std;

class HouseRobberSolution {
public:
    int rob(vector<int>& nums) {
        // dp[n] = max(dp[n-1], dp[n-2] + nums[n])
        int n = nums.size();
        int p = nums[0];
        if (n == 1) { return p; }
        int q = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            int r = max(p + nums[i], q);
            p = q;
            q = r;
        }
        return q;
    }
};
