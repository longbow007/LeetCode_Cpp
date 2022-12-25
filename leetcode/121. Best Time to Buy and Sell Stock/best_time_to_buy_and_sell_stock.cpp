//
//  best_time_to_buy_and_sell_stock.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/2.
//

#include "best_time_to_buy_and_sell_stock.hpp"
#include <vector>

using namespace std;

class BestTimeToBuyAndSellStockSolution {
public:
    // 动态规划
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     if (n <= 1) {
    //         return 0;
    //     }
    //     int minPrice = prices[0];
    //     // do[i] 含义：第 i 个元素对应的最大利润。状态转移方程如下：
    //     // dp[i] = max(dp[i-1], minPrice - prices[i])
    //     // 即：第 i 个元素的最大利润，等于第 i-1 个元素对应的最大利润与当前利润的最大值
    //     auto dp = vector<int>(n, 0);
    //     dp[0] = 0;
    //     for (int i = 1; i < n; i++) {
    //         minPrice = min(minPrice, prices[i]);
    //         dp[i] = max(dp[i-1], prices[i] - minPrice);
    //     }
    //     return dp[n-1];
    // }

    // 动态规划改进版本
    // dp[i] 无后效性，所以可以用一个局部变量代替
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) {
            return 0;
        }
        int curPrice = prices[0];
        int minPrice = curPrice;
        int profit = 0;
        for (int i = 1; i < n; i++) {
            curPrice = prices[i];
            minPrice = min(minPrice, curPrice);
            profit = max(profit, curPrice - minPrice);
        }
        return profit;
    }
};
