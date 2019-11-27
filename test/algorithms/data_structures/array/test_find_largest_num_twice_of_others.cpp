#include <boost/test/unit_test.hpp>
#include "algorithms/data_structures/array/find_largest_num_twice_of_others.hpp"

BOOST_AUTO_TEST_SUITE(TestFindLargestNumTwiceOfOthers)

BOOST_AUTO_TEST_CASE(arrays)
{
    std::vector<int> nums = { };
    BOOST_CHECK(-1 ==
        Algo::DS::Array::FindLargest::LargestAtLeastTwiceOfOthers(nums));

    nums = { 1 };
    BOOST_CHECK(0 ==
        Algo::DS::Array::FindLargest::LargestAtLeastTwiceOfOthers(nums));

    nums = { 1, 0 };
    BOOST_CHECK(0 ==
        Algo::DS::Array::FindLargest::LargestAtLeastTwiceOfOthers(nums));

    nums = { 3, 6, 1, 0 };
    BOOST_CHECK(1 ==
        Algo::DS::Array::FindLargest::LargestAtLeastTwiceOfOthers(nums));

    nums = { 1, 2 };
    BOOST_CHECK(1 ==
        Algo::DS::Array::FindLargest::LargestAtLeastTwiceOfOthers(nums));

    nums = { 1, 2, 3, 4 };
    BOOST_CHECK(-1 ==
        Algo::DS::Array::FindLargest::LargestAtLeastTwiceOfOthers(nums));
}

BOOST_AUTO_TEST_SUITE_END()
