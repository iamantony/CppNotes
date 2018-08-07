#ifndef TEST_MAX_SUBARRAY_SUM_HPP
#define TEST_MAX_SUBARRAY_SUM_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/math/max_subarray_sum.hpp"

BOOST_AUTO_TEST_CASE(test_mss_empty_array)
{
    BOOST_CHECK(0 == Algo::Math::MaxSubarraySum::Calc({}));
}

BOOST_AUTO_TEST_CASE(test_mss_array_with_one_elem)
{
    BOOST_CHECK(0 == Algo::Math::MaxSubarraySum::Calc({0}));
    BOOST_CHECK(1 == Algo::Math::MaxSubarraySum::Calc({1}));
    BOOST_CHECK(-1 == Algo::Math::MaxSubarraySum::Calc({-1}));
}

BOOST_AUTO_TEST_CASE(test_mss_array_with_several_elements)
{
    BOOST_CHECK(1 == Algo::Math::MaxSubarraySum::Calc({-2, 1}));
    BOOST_CHECK(-1 == Algo::Math::MaxSubarraySum::Calc({-2, -1}));
    BOOST_CHECK(2 == Algo::Math::MaxSubarraySum::Calc({-1, 2}));
    BOOST_CHECK(6 == Algo::Math::MaxSubarraySum::Calc({0, 2, 4, -1, -1}));
    BOOST_CHECK(7 == Algo::Math::MaxSubarraySum::Calc(
            {-2, -3, 4, -1, -2, 1, 5, -3}));
    BOOST_CHECK(6 == Algo::Math::MaxSubarraySum::Calc(
            {-2, 1, -3, 4, -1, 2, 1, -5, 4}));
}

#endif // TEST_MAX_SUBARRAY_SUM_HPP
