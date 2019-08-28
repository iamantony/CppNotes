#ifndef TEST_COIN_CHANGE_HPP
#define TEST_COIN_CHANGE_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/math/coin_change.hpp"

BOOST_AUTO_TEST_CASE(test_coinchange_invalid_input) {
    {
        std::vector<int> empty;
        BOOST_CHECK(Algo::Math::CoinChange::ChangeGreedy(empty, 1) == -1);
    }

    {
        std::vector<int> empty;
        BOOST_CHECK(Algo::Math::CoinChange::ChangeGreedy(empty, -12) == -1);
    }
}

BOOST_AUTO_TEST_CASE(test_coinchange_greedy_valid_input) {
    {
        std::vector<int> coins = {1};
        BOOST_CHECK(Algo::Math::CoinChange::ChangeGreedy(coins, 0) == 0);
    }

    {
        std::vector<int> coins = {1};
        BOOST_CHECK(Algo::Math::CoinChange::ChangeGreedy(coins, 2) == 2);
    }

    {
        std::vector<int> coins = {1, 5, 10};
        BOOST_CHECK(Algo::Math::CoinChange::ChangeGreedy(coins, 28) == 6);
    }
}

// TODO
BOOST_AUTO_TEST_CASE(test_coinchange_dp_no_change) {
    {
//        std::vector<int> coins = {186, 419, 83, 408};
//        BOOST_CHECK(Algo::Math::CoinChange::ChangeGreedy(coins, 6249) == 20);
    }
}

BOOST_AUTO_TEST_CASE(test_coinchange_greedy_no_change) {
    {
        std::vector<int> coins = {2, 5, 10};
        BOOST_CHECK(Algo::Math::CoinChange::ChangeGreedy(coins, 1) == -1);
        BOOST_CHECK(Algo::Math::CoinChange::ChangeGreedy(coins, 13) == -1);
    }
}

#endif // TEST_COIN_CHANGE_HPP
