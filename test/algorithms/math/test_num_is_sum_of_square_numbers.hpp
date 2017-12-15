#ifndef TEST_NUM_IS_SUM_OF_SQUARE_NUMBERS_HPP
#define TEST_NUM_IS_SUM_OF_SQUARE_NUMBERS_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/math/num_is_sum_of_square_numbers.hpp"

BOOST_AUTO_TEST_CASE(test_nisosn_check)
{
    SumOfSquares::Solution solution;
    BOOST_CHECK(true == solution.judgeSquareSum(0));
    BOOST_CHECK(true == solution.judgeSquareSum(1));
    BOOST_CHECK(true == solution.judgeSquareSum(2));
    BOOST_CHECK(false == solution.judgeSquareSum(3));
    BOOST_CHECK(true == solution.judgeSquareSum(4));
    BOOST_CHECK(true == solution.judgeSquareSum(5));
    BOOST_CHECK(false == solution.judgeSquareSum(7));
    BOOST_CHECK(true == solution.judgeSquareSum(8));
    BOOST_CHECK(false == solution.judgeSquareSum(9));
    BOOST_CHECK(true == solution.judgeSquareSum(10));
    BOOST_CHECK(true == solution.judgeSquareSum(13));
    BOOST_CHECK(true == solution.judgeSquareSum(25));
    BOOST_CHECK(true == solution.judgeSquareSum(257));
}

#endif // TEST_NUM_IS_SUM_OF_SQUARE_NUMBERS_HPP
