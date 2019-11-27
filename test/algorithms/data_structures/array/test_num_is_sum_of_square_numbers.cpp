#include <boost/test/unit_test.hpp>
#include "algorithms/data_structures/array/num_is_sum_of_square_numbers.hpp"

BOOST_AUTO_TEST_SUITE(TestNumIsSumOfSquareNumbers)

BOOST_AUTO_TEST_CASE(check)
{
    BOOST_CHECK(true == Algo::DS::Array::SumOfSquares::check(0));
    BOOST_CHECK(true == Algo::DS::Array::SumOfSquares::check(1));
    BOOST_CHECK(true == Algo::DS::Array::SumOfSquares::check(2));
    BOOST_CHECK(false == Algo::DS::Array::SumOfSquares::check(3));
    BOOST_CHECK(true == Algo::DS::Array::SumOfSquares::check(4));
    BOOST_CHECK(true == Algo::DS::Array::SumOfSquares::check(5));
    BOOST_CHECK(false == Algo::DS::Array::SumOfSquares::check(7));
    BOOST_CHECK(true == Algo::DS::Array::SumOfSquares::check(8));
    BOOST_CHECK(true == Algo::DS::Array::SumOfSquares::check(9));
    BOOST_CHECK(true == Algo::DS::Array::SumOfSquares::check(10));
    BOOST_CHECK(true == Algo::DS::Array::SumOfSquares::check(13));
    BOOST_CHECK(true == Algo::DS::Array::SumOfSquares::check(25));
    BOOST_CHECK(true == Algo::DS::Array::SumOfSquares::check(257));
}

BOOST_AUTO_TEST_SUITE_END()
