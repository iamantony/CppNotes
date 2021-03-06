#include <boost/test/unit_test.hpp>
#include "algorithms/dp/coin_change.hpp"

BOOST_AUTO_TEST_SUITE(TestCoinChange)

BOOST_AUTO_TEST_CASE(test_coinchange_invalid_input) {
    {
        std::vector<int> empty;
        BOOST_CHECK(Algo::DP::CoinChange::ChangeGreedy(empty, 1) == -1);
    }

    {
        std::vector<int> empty;
        BOOST_CHECK(Algo::DP::CoinChange::ChangeDP(empty, 1) == -1);
    }

    {
        std::vector<int> empty;
        BOOST_CHECK(Algo::DP::CoinChange::ChangeGreedy(empty, -12) == -1);
    }

    {
        std::vector<int> empty;
        BOOST_CHECK(Algo::DP::CoinChange::ChangeDP(empty, -12) == -1);
    }
}

BOOST_AUTO_TEST_CASE(test_coinchange_valid_input) {
    {
        std::vector<int> coins = {1};
        BOOST_CHECK(Algo::DP::CoinChange::ChangeGreedy(coins, 0) == 0);
    }

    {
        std::vector<int> coins = {1};
        BOOST_CHECK(Algo::DP::CoinChange::ChangeDP(coins, 0) == 0);
    }

    {
        std::vector<int> coins = {1};
        BOOST_CHECK(Algo::DP::CoinChange::ChangeGreedy(coins, 2) == 2);
    }

    {
        std::vector<int> coins = {1};
        BOOST_CHECK(Algo::DP::CoinChange::ChangeDP(coins, 2) == 2);
    }

    {
        std::vector<int> coins = {1, 5, 10};
        BOOST_CHECK(Algo::DP::CoinChange::ChangeGreedy(coins, 28) == 6);
    }

    {
        std::vector<int> coins = {1, 5, 10};
        BOOST_CHECK(Algo::DP::CoinChange::ChangeDP(coins, 28) == 6);
    }

    {
        std::vector<int> coins = {186, 419, 83, 408};
        BOOST_CHECK(Algo::DP::CoinChange::ChangeDP(coins, 6249) == 20);
    }

    {
        std::vector<int> coins = {2, 5, 10};
        BOOST_CHECK(Algo::DP::CoinChange::ChangeDP(coins, 13) == 5);
    }
}

BOOST_AUTO_TEST_CASE(test_coinchange_no_change) {
    {
        std::vector<int> coins = {2, 5, 10};
        BOOST_CHECK(Algo::DP::CoinChange::ChangeGreedy(coins, 1) == -1);
        BOOST_CHECK(Algo::DP::CoinChange::ChangeGreedy(coins, 13) == -1);
    }

    {
        std::vector<int> coins = {2, 5, 10};
        BOOST_CHECK(Algo::DP::CoinChange::ChangeDP(coins, 1) == -1);
    }
}

BOOST_AUTO_TEST_SUITE_END()
