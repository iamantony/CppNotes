#ifndef TEST_FIBONACCI_NUMBERS_HPP
#define TEST_FIBONACCI_NUMBERS_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/math/fibonacci_numbers.hpp"

BOOST_AUTO_TEST_CASE(test_fibnum_small_numbers)
{
    FibonacciNumbers::Solution solution;

    {
        std::vector<long long> expected = {0};
        BOOST_CHECK(expected == solution.ListOfFibonacciNumbers(0));
    }

    {
        std::vector<long long> expected = {0, 1};
        BOOST_CHECK(expected == solution.ListOfFibonacciNumbers(1));
    }

    {
        std::vector<long long> expected = {0, 1, 1};
        BOOST_CHECK(expected == solution.ListOfFibonacciNumbers(2));
    }

    {
        std::vector<long long> expected = {0, 1, 1, 2, 3, 5};
        BOOST_CHECK(expected == solution.ListOfFibonacciNumbers(5));
    }

    {
        std::vector<long long> expected = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55};
        BOOST_CHECK(expected == solution.ListOfFibonacciNumbers(10));
    }
}

#endif // TEST_FIBONACCI_NUMBERS_HPP
