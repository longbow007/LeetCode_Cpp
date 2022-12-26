//
//  BestTimeToBuyAndSellStockIV.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/12/26.
//

#include "BestTimeToBuyAndSellStockIV.hpp"
#include <vector>

using namespace std;

class BestTimeToBuyAndSellStockIVSolution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n < 2 || k < 1) {
            return 0;
        }
        // 最多只能进行 n/2 次交易
        k = min(k, n/2);
        // buy[j] 的含义：买过 j 次以后手头现金的最大值
        // sell[j] 含义同上
        auto buy = vector<int>(k, -prices[0]);
        auto sell = vector<int>(k, 0);
        for (int i = 1; i < n; i++) {
            int p = prices[i];
            // 第 i 天，买过 1 次的情况下，手头现金最大值，所以要和当前价格对比。实际上就是取第 i 天价格最小值的负数
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
