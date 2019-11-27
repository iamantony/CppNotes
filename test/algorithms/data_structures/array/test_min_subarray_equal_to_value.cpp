#include <boost/test/unit_test.hpp>
#include "algorithms/data_structures/array/min_subarray_equal_to_value.hpp"

BOOST_AUTO_TEST_SUITE(TestMinSubArrayEqualToValue)

BOOST_AUTO_TEST_CASE(empty_array)
{
    BOOST_CHECK(0 ==
          Algo::DS::Array::SubarrayEqualToValue::FindMinLengthSubarray(-1, {0, 1}));

    BOOST_CHECK(0 ==
          Algo::DS::Array::SubarrayEqualToValue::FindMinLengthSubarray(10, {}));

    BOOST_CHECK(0 ==
          Algo::DS::Array::SubarrayEqualToValue::FindMinLengthSubarray(-1, {}));
}

BOOST_AUTO_TEST_CASE(array_with_one_elem)
{
    BOOST_CHECK(0 == Algo::DS::Array::SubarrayEqualToValue::FindMinLengthSubarray(
                    10, {0}));

    BOOST_CHECK(1 == Algo::DS::Array::SubarrayEqualToValue::FindMinLengthSubarray(
                    10, {10}));

    BOOST_CHECK(1 == Algo::DS::Array::SubarrayEqualToValue::FindMinLengthSubarray(
                    9, {15}));
}

BOOST_AUTO_TEST_CASE(array_with_several_elements)
{
    BOOST_CHECK(1 == Algo::DS::Array::SubarrayEqualToValue::FindMinLengthSubarray(
                    5, {1, 2, 3, 4, 5, 6}));

    BOOST_CHECK(1 == Algo::DS::Array::SubarrayEqualToValue::FindMinLengthSubarray(
                    5, {1, 1, 8, 4, 10, 6}));

    BOOST_CHECK(3 == Algo::DS::Array::SubarrayEqualToValue::FindMinLengthSubarray(
                    5, {1, 1, 2, 1, 2}));

    BOOST_CHECK(3 == Algo::DS::Array::SubarrayEqualToValue::FindMinLengthSubarray(
            15, {1, 1, 0, 0, 1, 13, 1, 0}));

//    BOOST_CHECK(6 == Algo::DS::Array::SubarrayEqualToValue::FindMinLengthSubarray(
//            {-2, 1, -3, 4, -1, 2, 1, -5, 4}));
}

BOOST_AUTO_TEST_SUITE_END()
