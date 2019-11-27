#include <boost/test/unit_test.hpp>
#include "algorithms/data_structures/array/find_pivot_index.hpp"

BOOST_AUTO_TEST_SUITE(TestFindPivotIndex)

BOOST_AUTO_TEST_CASE(invalid_arrays)
{
    std::vector<int> nums = { };
    BOOST_CHECK(-1 == Algo::DS::Array::FindPivot::PivotIndex(nums));

    nums = { 1 };
    BOOST_CHECK(-1 == Algo::DS::Array::FindPivot::PivotIndex(nums));

    nums = { 1, 2 };
    BOOST_CHECK(-1 == Algo::DS::Array::FindPivot::PivotIndex(nums));
}

BOOST_AUTO_TEST_CASE(valid_arrays)
{
    std::vector<int> nums = {0, 0, 0};
    BOOST_CHECK(0 == Algo::DS::Array::FindPivot::PivotIndex(nums));

    nums = {1, 2, 3};
    BOOST_CHECK(-1 == Algo::DS::Array::FindPivot::PivotIndex(nums));

    nums = {1, 7, 3, 6, 5, 6};
    BOOST_CHECK(3 == Algo::DS::Array::FindPivot::PivotIndex(nums));
}

BOOST_AUTO_TEST_SUITE_END()
