#include <boost/test/unit_test.hpp>
#include "algorithms/math/fibonacci_numbers.hpp"

BOOST_AUTO_TEST_SUITE(TestFibbonacciNumbers)

BOOST_AUTO_TEST_CASE(small_numbers) {
    {
        std::vector<long long> expected = {0};
        BOOST_CHECK(expected == Algo::Math::FibonacciNumbers::ListOfNums(0));
    }

    {
        std::vector<long long> expected = {0, 1};
        BOOST_CHECK(expected == Algo::Math::FibonacciNumbers::ListOfNums(1));
    }

    {
        std::vector<long long> expected = {0, 1, 1};
        BOOST_CHECK(expected == Algo::Math::FibonacciNumbers::ListOfNums(2));
    }

    {
        std::vector<long long> expected = {0, 1, 1, 2, 3, 5};
        BOOST_CHECK(expected == Algo::Math::FibonacciNumbers::ListOfNums(5));
    }

    {
        std::vector<long long> expected = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55};
        BOOST_CHECK(expected == Algo::Math::FibonacciNumbers::ListOfNums(10));
    }
}

BOOST_AUTO_TEST_CASE(last_digit) {
    BOOST_CHECK(0 == Algo::Math::FibonacciNumbers::LastDigitOfNum(0));
    BOOST_CHECK(1 == Algo::Math::FibonacciNumbers::LastDigitOfNum(1));
    BOOST_CHECK(5 == Algo::Math::FibonacciNumbers::LastDigitOfNum(5));
    BOOST_CHECK(4 == Algo::Math::FibonacciNumbers::LastDigitOfNum(9));
    BOOST_CHECK(9 == Algo::Math::FibonacciNumbers::LastDigitOfNum(331));
    BOOST_CHECK(5 == Algo::Math::FibonacciNumbers::LastDigitOfNum(327305));
}

BOOST_AUTO_TEST_SUITE_END()
