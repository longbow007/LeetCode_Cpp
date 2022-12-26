//
//  BestTimeToBuyAndSellStockII.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/12/26.
//

#include "BestTimeToBuyAndSellStockII.hpp"
#include <vector>

using namespace std;

class BestTimeToBuyAndSellStockIISolution {
public:
    /*
    // 动态规划
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) {
            return 0;
        }
        // dp[i][j] 含义：第 i 天时，状态为 j 时手里的现金。j 为0或1, 1表示持有，0表示卖出
        auto dp = vector<vector<int>>(n, vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; i++) {
            int p = prices[i];
            dp[i][0] = max(dp[i-1][1] + p, dp[i-1][0]);
            dp[i][1] = max(dp[i-1][0] - p, dp[i-1][1]);
        }
        return dp[n-1][0];
    }
    */
    // 空间优化版本
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) {
            return 0;
        }
        int sell = 0, hold = -prices[0];
        for (int i = 1; i < n; i++) {
            int p = prices[i];
            int oldSell = sell, oldHold = hold;
            sell = max(oldHold + p, oldSell);
            hold = max(oldSell - p, oldHold);
        }
        return sell;
    }
};
