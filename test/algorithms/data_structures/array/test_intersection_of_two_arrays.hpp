#ifndef TEST_INTERSECTION_OF_TWO_ARRAYS_HPP
#define TEST_INTERSECTION_OF_TWO_ARRAYS_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/data_structures/array/intersection_of_two_arrays.hpp"

BOOST_AUTO_TEST_CASE(test_iota_empty_arr)
{
    {
        std::vector<int> nums1 = {};
        std::vector<int> nums2 = {};
        BOOST_CHECK(std::vector<int>() ==
                Algo::DS::Array::Intersection::GetIntersection(nums1, nums2));
    }

    {
        std::vector<int> nums1 = {1, 2};
        std::vector<int> nums2 = {};
        BOOST_CHECK(std::vector<int>() ==
                Algo::DS::Array::Intersection::GetIntersection(nums1, nums2));
    }

    {
        std::vector<int> nums1 = {};
        std::vector<int> nums2 = {3, 4};
        BOOST_CHECK(std::vector<int>() ==
                Algo::DS::Array::Intersection::GetIntersection(nums1, nums2));
    }
}

BOOST_AUTO_TEST_CASE(test_iota_no_intersection)
{
    std::vector<int> nums1 = {1, 2};
    std::vector<int> nums2 = {3, 4, 5, 6};
    BOOST_CHECK(std::vector<int>() ==
                Algo::DS::Array::Intersection::GetIntersection(nums1, nums2));
}

BOOST_AUTO_TEST_CASE(test_iota_have_intersection)
{
    std::vector<int> nums1 = {1, 23, 3, 5};
    std::vector<int> nums2 = {3, 4, 5, 6, 7, 99};
    std::vector<int> expected = {3, 5};
    BOOST_CHECK(expected ==
                Algo::DS::Array::Intersection::GetIntersection(nums1, nums2));
}

#endif // TEST_INTERSECTION_OF_TWO_ARRAYS_HPP
