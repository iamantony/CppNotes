#ifndef TEST_KNAPSACK_PROBLEM_HPP
#define TEST_KNAPSACK_PROBLEM_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/math/knapsack_problem.hpp"
#include "common/equality.hpp"

BOOST_AUTO_TEST_CASE(test_knapsackp_example)
{
    Knapsack::Solution solution;

    {
        std::unordered_map<int, int> items = {
            {10, 10},
            {5, 100},
            {15, 3}
        };

        int maxWeight = 20;
        double expectedResult = 25.35;
        BOOST_CHECK(equal(solution.knapsakProblem(maxWeight, items), expectedResult));
    }
}

#endif // TEST_KNAPSACK_PROBLEM_HPP

