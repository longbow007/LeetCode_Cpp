//
//  BestTimeToBuyAndSellStockWithTransactionFee.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/12/26.
//

#include "BestTimeToBuyAndSellStockWithTransactionFee.hpp"
#include <vector>

using namespace std;

class BestTimeToBuyAndSellStockWithTransactionFeeSolution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n < 2) {
            return 0;
        }
        int sell = 0, possess = -prices[0];
        for (int i = 0; i < n; i++) {
            int oldSell = sell, oldPossess = possess;
            int p = prices[i];
            sell = max(oldPossess + p - fee, oldSell);
            possess = max(oldSell - p, oldPossess);
        }
        return sell;
    }
};
