//
//  NumberOfLongestIncreasingSubsequence.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/8/25.
//

#include "NumberOfLongestIncreasingSubsequence.hpp"
#include <vector>

using namespace std;

class NumberOfLISSolution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        int dp[size];
        memset(dp, 0, sizeof(dp));
        int cnt[size];
        memset(cnt, 0, sizeof(cnt));
        dp[0] = 1;
        cnt[0] = 1;
        int maxDp = 1;
        for (int i = 1; i < size; i++) {
            dp[i] = 1;
            cnt[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    } else if (dp[j] + 1 == dp[i]) {
                        cnt[i] += cnt[j];
                    }
                }
                maxDp = max(maxDp, dp[i]);
            }
        }
        int result = 0;
        for (int k = 0; k < size; k++) {
            if (dp[k] == maxDp) {
                result += cnt[k];
            }
        }
        return result;
    }
};
