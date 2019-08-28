#ifndef TEST_KNAPSACK_PROBLEM_HPP
#define TEST_KNAPSACK_PROBLEM_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/math/knapsack_problem.hpp"
#include "common/equality.hpp"

BOOST_AUTO_TEST_CASE(test_knapsackp_test)
{
    {
        std::unordered_map<uint32_t, uint32_t> items = {
            {10, 10}, {5, 100}, {15, 3}
        };

        uint32_t maxWeight = 20;
        double expectedResult = 25.35;
        BOOST_CHECK(
            equal(Algo::Math::Knapsack::Fill(maxWeight, items), expectedResult));
    }

    {
        std::unordered_map<uint32_t, uint32_t> items = {
            {60, 20}, {100, 50}, {120, 30}
        };

        uint32_t maxWeight = 50;
        double expectedResult = 180.0;
        BOOST_CHECK(
            equal(Algo::Math::Knapsack::Fill(maxWeight, items), expectedResult));
    }

    {
        std::unordered_map<uint32_t, uint32_t> items = { {500, 30} };

        uint32_t maxWeight = 10;
        const double expectedResult = 166.6667;
        const double result = Algo::Math::Knapsack::Fill(maxWeight, items);
        BOOST_CHECK(equalDoubles(result, expectedResult, 0.0001));
    }
}

#endif // TEST_KNAPSACK_PROBLEM_HPP

