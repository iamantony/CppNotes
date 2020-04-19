#include <boost/test/unit_test.hpp>
#include "algorithms/hashmap/intersection_of_two_arrays.hpp"

BOOST_AUTO_TEST_SUITE(TestIntersectionOfTwoArrays)

BOOST_AUTO_TEST_CASE(empty_arr)
{
    {
        std::vector<int> nums1 = {};
        std::vector<int> nums2 = {};
        BOOST_CHECK(Algo::HashMap::IntersectionOfTwoArray::find_all(nums1, nums2).empty());
    }

    {
        std::vector<int> nums1 = {1, 2};
        std::vector<int> nums2 = {};
        BOOST_CHECK(Algo::HashMap::IntersectionOfTwoArray::find_all(nums1, nums2).empty());
    }

    {
        std::vector<int> nums1 = {};
        std::vector<int> nums2 = {3, 4};
        BOOST_CHECK(Algo::HashMap::IntersectionOfTwoArray::find_all(nums1, nums2).empty());
    }
}

BOOST_AUTO_TEST_CASE(no_intersection)
{
    std::vector<int> nums1 = {1, 2};
    std::vector<int> nums2 = {3, 4, 5, 6};
    BOOST_CHECK(Algo::HashMap::IntersectionOfTwoArray::find_all(nums1, nums2).empty());
}

BOOST_AUTO_TEST_CASE(have_intersection)
{
    std::vector<int> nums1 = {1, 23, 3, 5};
    std::vector<int> nums2 = {3, 4, 5, 6, 7, 99};
    std::vector<int> expected = {3, 5};
    BOOST_CHECK(expected == Algo::HashMap::IntersectionOfTwoArray::find_all(nums1, nums2));
}

BOOST_AUTO_TEST_SUITE_END()
