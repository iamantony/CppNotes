#include <boost/test/unit_test.hpp>
#include "algorithms/other/buy_sell_stock_one_transaction.hpp"

BOOST_AUTO_TEST_SUITE(BuyAndSellStockOneTransaction)

BOOST_AUTO_TEST_CASE(invalid_arg)
{
    BOOST_CHECK(0 == Algo::Other::BuySellStockOneTrans::GetMaxProfit({}));
    BOOST_CHECK(0 == Algo::Other::BuySellStockOneTrans::GetMaxProfit({1}));
}

BOOST_AUTO_TEST_CASE(two_elements)
{
    BOOST_CHECK(8 == Algo::Other::BuySellStockOneTrans::GetMaxProfit({2, 10}));
    BOOST_CHECK(0 == Algo::Other::BuySellStockOneTrans::GetMaxProfit({10, 2}));
}

BOOST_AUTO_TEST_CASE(leetcode_tc)
{
    BOOST_CHECK(2 == Algo::Other::BuySellStockOneTrans::GetMaxProfit({2, 4, 1}));
    BOOST_CHECK(3 == Algo::Other::BuySellStockOneTrans::GetMaxProfit({2, 1, 4}));
    BOOST_CHECK(16 == Algo::Other::BuySellStockOneTrans::GetMaxProfit(
            {10, 26, 1, 3, 2, 4, 7}));
}

BOOST_AUTO_TEST_SUITE_END()
