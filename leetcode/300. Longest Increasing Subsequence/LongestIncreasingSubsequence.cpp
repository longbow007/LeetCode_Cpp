//
//  LongestIncreasingSubsequence.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/8/25.
//

#include "LongestIncreasingSubsequence.hpp"
#include <vector>

using namespace std;

class LISSolution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        // vector<int> dp(nums.size(), 0);
        int dp[nums.size()];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        int maxDp = 1;
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxDp = max(maxDp, dp[i]);
        }
        return maxDp;
    }
};
