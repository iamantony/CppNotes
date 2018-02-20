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
#include <algorithm>
#include <iostream>

namespace BuyAndSellStock {

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int profit = 0;
        if (prices.size() < 2) {
            return profit;
        }

        auto dayIter = std::min_element(prices.begin(), prices.end());
        auto maxPriceIter = std::max_element(prices.begin(), prices.end());
        if (std::distance(dayIter, maxPriceIter) < 0) {
            dayIter = std::min_element(prices.begin(), maxPriceIter);
        }

        while (dayIter != prices.end()) {
            maxPriceIter = std::max_element(dayIter + 1, prices.end());
            if (maxPriceIter == prices.end()) {
                break;
            }

            if (*maxPriceIter > *dayIter) {
                profit += *maxPriceIter - *dayIter;
                dayIter = std::min_element(maxPriceIter + 1, prices.end());
            }
            else {
                ++dayIter;
            }
        }

        return profit;
    }
};

}

#endif // BUY_SELL_STOCK_HPP
