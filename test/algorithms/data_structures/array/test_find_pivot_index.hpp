#ifndef TEST_FIND_PIVOT_INDEX_HPP
#define TEST_FIND_PIVOT_INDEX_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/data_structures/array/find_pivot_index.hpp"

BOOST_AUTO_TEST_CASE(test_fpivind_invalid_arrays)
{
    std::vector<int> nums = { };
    BOOST_CHECK(-1 == Algo::DS::Array::FindPivot::PivotIndex(nums));

    nums = { 1 };
    BOOST_CHECK(-1 == Algo::DS::Array::FindPivot::PivotIndex(nums));

    nums = { 1, 2 };
    BOOST_CHECK(-1 == Algo::DS::Array::FindPivot::PivotIndex(nums));
}

BOOST_AUTO_TEST_CASE(test_fpivind_valid_arrays)
{
    std::vector<int> nums = {0, 0, 0};
    BOOST_CHECK(0 == Algo::DS::Array::FindPivot::PivotIndex(nums));

    nums = {1, 2, 3};
    BOOST_CHECK(-1 == Algo::DS::Array::FindPivot::PivotIndex(nums));

    nums = {1, 7, 3, 6, 5, 6};
    BOOST_CHECK(3 == Algo::DS::Array::FindPivot::PivotIndex(nums));
}

#endif // TEST_FIND_PIVOT_INDEX_HPP
