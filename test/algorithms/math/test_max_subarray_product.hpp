#ifndef TEST_MAX_SUBARRAY_PRODUCT_HPP
#define TEST_MAX_SUBARRAY_PRODUCT_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/math/max_subarray_product.hpp"

BOOST_AUTO_TEST_CASE(test_msp_empty_array)
{
    BOOST_CHECK(0 == Algo::Math::MaxSubarrayProduct::Calc({}));
}

BOOST_AUTO_TEST_CASE(test_msp_array_with_one_elem)
{
    BOOST_CHECK(0 == Algo::Math::MaxSubarrayProduct::Calc({0}));
    BOOST_CHECK(1 == Algo::Math::MaxSubarrayProduct::Calc({1}));
    BOOST_CHECK(-1 == Algo::Math::MaxSubarrayProduct::Calc({-1}));
}

BOOST_AUTO_TEST_CASE(test_msp_array_with_several_elements)
{
    BOOST_CHECK(1 == Algo::Math::MaxSubarrayProduct::Calc({-2, 1}));
    BOOST_CHECK(2 == Algo::Math::MaxSubarrayProduct::Calc({-2, -1}));
    BOOST_CHECK(0 == Algo::Math::MaxSubarrayProduct::Calc({-2, 0, -1}));
    BOOST_CHECK(6 == Algo::Math::MaxSubarrayProduct::Calc({2, 3, -2, 4}));
    BOOST_CHECK(8 == Algo::Math::MaxSubarrayProduct::Calc({0, 2, 4, -1, -1}));
    BOOST_CHECK(360 == Algo::Math::MaxSubarrayProduct::Calc(
            {-2, -3, 4, -1, -2, 1, 5, -3}));
    BOOST_CHECK(960 == Algo::Math::MaxSubarrayProduct::Calc(
            {-2, 1, -3, 4, -1, 2, 1, -5, 4}));
    BOOST_CHECK(60 == Algo::Math::MaxSubarrayProduct::Calc(
            {-1, -3, -10, 0, 60}));
}

#endif // TEST_MAX_SUBARRAY_PRODUCT_HPP
