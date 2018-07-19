#ifndef TEST_FIND_LARGEST_NUM_TWICE_OF_OTHERS_HPP
#define TEST_FIND_LARGEST_NUM_TWICE_OF_OTHERS_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/data_structures/array/find_largest_num_twice_of_others.hpp"

BOOST_AUTO_TEST_CASE(test_flntoo_arrays)
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

#endif // TEST_FIND_LARGEST_NUM_TWICE_OF_OTHERS_HPP
