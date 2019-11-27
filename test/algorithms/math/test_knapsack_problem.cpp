#include <boost/test/unit_test.hpp>
#include "algorithms/math/knapsack_problem.hpp"
#include "common/equality.hpp"

BOOST_AUTO_TEST_SUITE(KnapsakProblem)

BOOST_AUTO_TEST_CASE(greedy_test)
{
    {
        std::vector<std::pair<uint32_t, uint32_t>> items = {
            {10, 10}, {5, 100}, {15, 3}
        };

        uint32_t maxWeight = 20;
        double expectedResult = 25.35;
        BOOST_CHECK(
            equal(Algo::Math::Knapsack::FillGreedy(maxWeight, items), expectedResult));
    }

    {
        std::vector<std::pair<uint32_t, uint32_t>> items = {
            {60, 20}, {100, 50}, {120, 30}
        };

        uint32_t maxWeight = 50;
        double expectedResult = 180.0;
        BOOST_CHECK(
            equal(Algo::Math::Knapsack::FillGreedy(maxWeight, items), expectedResult));
    }

    {
        std::vector<std::pair<uint32_t, uint32_t>> items = { {500, 30} };

        uint32_t maxWeight = 10;
        const double expectedResult = 166.6667;
        const double result = Algo::Math::Knapsack::FillGreedy(maxWeight, items);
        BOOST_CHECK(equalDoubles(result, expectedResult, 0.0001));
    }

    {
        std::vector<std::pair<uint32_t, uint32_t>> items = {
            {100, 5}, {100, 5} };

        uint32_t maxWeight = 10;
        const double expectedResult = 200;
        const double result = Algo::Math::Knapsack::FillGreedy(maxWeight, items);
        BOOST_CHECK(equalDoubles(result, expectedResult, 0.0001));
    }
}

BOOST_AUTO_TEST_CASE(dp_without_repetitions_test) {
    {
        std::vector<std::pair<uint32_t, uint32_t>> items;
        uint32_t maxWeight = 20;
        uint32_t expected = 0;
        BOOST_CHECK(Algo::Math::Knapsack::FillDP(maxWeight, items) == expected);
    }

    {
        std::vector<std::pair<uint32_t, uint32_t>> items = {{1, 1}};
        uint32_t maxWeight = 0;
        uint32_t expected = 0;
        BOOST_CHECK(Algo::Math::Knapsack::FillDP(maxWeight, items) == expected);
    }

    {
        std::vector<std::pair<uint32_t, uint32_t>> items = {
            {1, 1}, {4, 4}, {8, 8}};
        uint32_t maxWeight = 10;
        uint32_t expected = 9;
        BOOST_CHECK(Algo::Math::Knapsack::FillDP(maxWeight, items) == expected);
    }

    {
        std::vector<std::pair<uint32_t, uint32_t>> items = {
            {6, 6}, {3, 3}, {4, 4}, {2, 2}};
        uint32_t maxWeight = 10;
        uint32_t expected = 10;
        BOOST_CHECK(Algo::Math::Knapsack::FillDP(maxWeight, items) == expected);
    }
}

BOOST_AUTO_TEST_SUITE_END()
