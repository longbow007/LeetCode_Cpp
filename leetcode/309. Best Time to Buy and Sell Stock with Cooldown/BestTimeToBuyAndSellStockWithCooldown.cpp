//
//  BestTimeToBuyAndSellStockWithCooldown.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/12/26.
//

#include "BestTimeToBuyAndSellStockWithCooldown.hpp"
#include <vector>

using namespace std;

class BestTimeToBuyAndSellStockWithCooldownSolution {
public:
    /*
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) {
            return 0;
        }
        // 0 是卖出，1 是买入或持有
        auto dp = vector<vector<int>>(n, vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; i++) {
            int p = prices[i];
            dp[i][0] = max(dp[i-1][1] + p, dp[i-1][0]);
            if (i == 1) {
                dp[i][1] = max(-p, dp[i-1][1]);
            } else {
                dp[i][1] = max(dp[i-2][0] - p, dp[i-1][1]);
            }
        }
        return dp[n-1][0];
    }
    */

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) {
            return 0;
        }
        int sell = 0, possess = -prices[0], lastSell = 0;
        for (int i = 1; i < n; i++) {
            int p = prices[i];
            int oldSell = sell, oldPossess = possess;
            if (i == 1) {
                possess = max(-p, oldPossess);
            } else {
                possess = max(lastSell - p, oldPossess);
                lastSell = oldSell;
            }
            sell = max(oldPossess + p, oldSell);
        }
        return sell;
    }
};
