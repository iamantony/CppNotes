#ifndef TEST_FIND_NEXT_GREATER_ELEMENT_HPP
#define TEST_FIND_NEXT_GREATER_ELEMENT_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/search/find_next_greater_element.hpp"

BOOST_AUTO_TEST_CASE(test_fnge_empty_data)
{
    std::vector<int> nums1, nums2;
    std::vector<int> expected;

    BOOST_CHECK(expected ==
                Algo::Search::FindNextGreaterElem::FindSimple(nums1, nums2));

    BOOST_CHECK(expected ==
                Algo::Search::FindNextGreaterElem::FindUsingStack(nums1, nums2));

    BOOST_CHECK(expected ==
                Algo::Search::FindNextGreaterElem::FindInCircularArray(nums1));
}

BOOST_AUTO_TEST_CASE(test_fnge_invalid_data)
{
    std::vector<int> nums1(2, 0), nums2(1, 0);
    std::vector<int> expected;

    BOOST_CHECK(expected ==
                Algo::Search::FindNextGreaterElem::FindSimple(nums1, nums2));

    BOOST_CHECK(expected ==
                Algo::Search::FindNextGreaterElem::FindUsingStack(nums1, nums2));
}

BOOST_AUTO_TEST_CASE(test_fnge_two_arrays)
{
    {
        std::vector<int> nums1 = {4, 1, 2};
        std::vector<int> nums2 = {1, 3, 4, 2};
        std::vector<int> expected = {-1, 3, -1};

        BOOST_CHECK(expected ==
            Algo::Search::FindNextGreaterElem::FindSimple(nums1, nums2));

        BOOST_CHECK(expected ==
            Algo::Search::FindNextGreaterElem::FindUsingStack(nums1, nums2));
    }

    {
        std::vector<int> nums1 = {2, 4};
        std::vector<int> nums2 = {1, 2, 3, 4};
        std::vector<int> expected = {3, -1};

        BOOST_CHECK(expected ==
            Algo::Search::FindNextGreaterElem::FindSimple(nums1, nums2));

        BOOST_CHECK(expected ==
            Algo::Search::FindNextGreaterElem::FindUsingStack(nums1, nums2));
    }
}

BOOST_AUTO_TEST_CASE(test_fnge_in_circular_arr)
{
    {
        std::vector<int> nums = {4};
        std::vector<int> expected = {-1};

        BOOST_CHECK(expected ==
            Algo::Search::FindNextGreaterElem::FindInCircularArray(nums));
    }

    {
        std::vector<int> nums = {1, 2, 3};
        std::vector<int> expected = {2, 3, -1};

        BOOST_CHECK(expected ==
            Algo::Search::FindNextGreaterElem::FindInCircularArray(nums));
    }

    {
        std::vector<int> nums = {3, 2, 1};
        std::vector<int> expected = {-1, 3, 3};

        BOOST_CHECK(expected ==
            Algo::Search::FindNextGreaterElem::FindInCircularArray(nums));
    }

    {
        std::vector<int> nums = {1, 2, 1};
        std::vector<int> expected = {2, -1, 2};

        BOOST_CHECK(expected ==
            Algo::Search::FindNextGreaterElem::FindInCircularArray(nums));
    }
}

#endif // TEST_FIND_NEXT_GREATER_ELEMENT_HPP
