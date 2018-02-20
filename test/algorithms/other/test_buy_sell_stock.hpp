#ifndef TEST_BUY_SELL_STOCK_HPP
#define TEST_BUY_SELL_STOCK_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/other/buy_sell_stock.hpp"

BOOST_AUTO_TEST_CASE(test_bsstock_empty)
{
    BuyAndSellStock::Solution solution;
    std::vector<int> prices;
    BOOST_CHECK(solution.maxProfit(prices) == 0);
}

BOOST_AUTO_TEST_CASE(test_bsstock_one_elem)
{
    BuyAndSellStock::Solution solution;
    std::vector<int> prices = {10};
    int result = 0;
    BOOST_CHECK(solution.maxProfit(prices) == result);
}

BOOST_AUTO_TEST_CASE(test_bsstock_two_elements)
{
    BuyAndSellStock::Solution solution;

    {
        std::vector<int> prices = {10, 2};
        int result = 0;
        BOOST_CHECK(solution.maxProfit(prices) == result);
    }

    {
        std::vector<int> prices = {2, 10};
        int result = 8;
        BOOST_CHECK(solution.maxProfit(prices) == result);
    }
}

BOOST_AUTO_TEST_CASE(test_bsstock_leetcode_tc)
{
    BuyAndSellStock::Solution solution;

    {
        std::vector<int> prices = {2, 4, 1};
        int result = 2;
        BOOST_CHECK(solution.maxProfit(prices) == result);
    }

    {
        std::vector<int> prices = {2, 1, 4};
        int result = 3;
        BOOST_CHECK(solution.maxProfit(prices) == result);
    }

    {
        std::vector<int> prices = {6, 1, 3, 2, 4, 7};
        int result = 7;
        BOOST_CHECK(solution.maxProfit(prices) == result);
    }
}

#endif // TEST_BUY_SELL_STOCK_HPP
