#include <boost/test/unit_test.hpp>
#include "algorithms/data_structures/array/max_subarray_sum.hpp"

BOOST_AUTO_TEST_SUITE(TestMaxSubArraySum)

BOOST_AUTO_TEST_CASE(empty_array)
{
    BOOST_CHECK(0 == Algo::DS::Array::MaxSubarraySum::Calc({}));
}

BOOST_AUTO_TEST_CASE(array_with_one_elem)
{
    BOOST_CHECK(0 == Algo::DS::Array::MaxSubarraySum::Calc({0}));
    BOOST_CHECK(1 == Algo::DS::Array::MaxSubarraySum::Calc({1}));
    BOOST_CHECK(-1 == Algo::DS::Array::MaxSubarraySum::Calc({-1}));
}

BOOST_AUTO_TEST_CASE(array_with_several_elements)
{
    BOOST_CHECK(1 == Algo::DS::Array::MaxSubarraySum::Calc({-2, 1}));
    BOOST_CHECK(-1 == Algo::DS::Array::MaxSubarraySum::Calc({-2, -1}));
    BOOST_CHECK(2 == Algo::DS::Array::MaxSubarraySum::Calc({-1, 2}));
    BOOST_CHECK(6 == Algo::DS::Array::MaxSubarraySum::Calc({0, 2, 4, -1, -1}));
    BOOST_CHECK(7 == Algo::DS::Array::MaxSubarraySum::Calc(
            {-2, -3, 4, -1, -2, 1, 5, -3}));
    BOOST_CHECK(6 == Algo::DS::Array::MaxSubarraySum::Calc(
            {-2, 1, -3, 4, -1, 2, 1, -5, 4}));
}

BOOST_AUTO_TEST_SUITE_END()
