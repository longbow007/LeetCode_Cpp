//
//  best_time_to_buy_and_sell_stock.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/2.
//

#include "best_time_to_buy_and_sell_stock.hpp"
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    int low = prices[0], profit = 0;
    for (int x : prices) {
        low = min(low, x);
        profit = max(profit, x - low);
    }
    return profit;
}
