//
//  RussianDollEnvelopes.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/8/25.
//

#include "RussianDollEnvelopes.hpp"

class RussianDollEnvelopesSolution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.empty()) return 0;
        sort(envelopes.begin(), envelopes.end(), [](const auto& e1, const auto& e2) {
            return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]);
        });
        int n = envelopes.size();
        int dp[n];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        int maxDp = 1;
        for (int i = 1; i < n; i++) {
            dp[i] = 1;
            vector vi = envelopes[i];
            for (int j = 0; j < i; j++) {
                vector vj = envelopes[j];
                if (vj[0] < vi[0] && vj[1] < vi[1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxDp = max(maxDp, dp[i]);
        }
        return maxDp;
    }
};
