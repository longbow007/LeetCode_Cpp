//
//  BestTimeToBuyAndSellStockIII.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/12/26.
//

#include "BestTimeToBuyAndSellStockIII.hpp"
#include <vector>

using namespace std;

class BestTimeToBuyAndSellStockIIISolution {
public:
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     if (n < 2) {
    //         return 0;
    //     }
    //     // 每一天结束时可能的状态：什么也不干，买过一次，卖过一次，买过2次，卖过2次
    //     int buy1 = -prices[0]; // 买过一次
    //     int sell1 = 0;  // 卖过一次
    //     int buy2 = -prices[0]; // 买过2次。初始相当于 buy1 + sell1 - prices[0]
    //     int sell2 = 0;  // 卖过2次
    //     for (int i = 1; i < n; i++) {
    //         int p = prices[i];
    //         buy1 = max(buy1, -p);
    //         sell1 = max(buy1 + p, sell1);
    //         buy2 = max(sell1 - p, buy2);
    //         sell2 = max(buy2 + p, sell2);
    //     }
    //     return sell2;
    // }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) {
            return 0;
        }
        int k = 2;
        auto buy = vector<int>(k, -prices[0]);
        auto sell = vector<int>(k, 0);
        for (int i = 1; i < n; i++) {
            int p = prices[i];
            buy[0] = max(buy[0], -p);
            sell[0] = max(sell[0], buy[0] + p);
            for (int j = 1; j < k; j++) {
                buy[j] = max(buy[j], sell[j-1] - p);
                sell[j] = max(sell[j], buy[j] + p);
            }
        }
        return sell[k-1];
    }
};
