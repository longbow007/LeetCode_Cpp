//
//  StockMaxProfit.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/12/26.
//

#include "StockMaxProfit.hpp"
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) {
            return 0;
        }
        int price = prices[0];
        int profit = 0;
        for (int i = 1; i < n; i++) {
            profit = max(profit, prices[i] - price);
            price = min(price, prices[i]);
        }
        return profit;
    }
};
