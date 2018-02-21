#ifndef BUY_SELL_STOCK_HPP
#define BUY_SELL_STOCK_HPP

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

// Say you have an array for which the ith element is the price of a given
//stock on day i.

// Design an algorithm to find the maximum profit. You may complete as many
// transactions as you like (ie, buy one and sell one share of the stock
// multiple times). However, you may not engage in multiple transactions at
// the same time (ie, you must sell the stock before you buy again).

#include <vector>

namespace BuyAndSellStock {

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int profit = 0;
        for (size_t day = 1; day < prices.size(); ++day) {
            if (prices[day] > prices[day - 1]) {
                profit += prices[day] - prices[day - 1];
            }
        }

        return profit;
    }
};

}

#endif // BUY_SELL_STOCK_HPP
