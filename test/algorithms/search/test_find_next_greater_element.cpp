#include <boost/test/unit_test.hpp>
#include "algorithms/search/find_next_greater_element.hpp"

BOOST_AUTO_TEST_SUITE(TestFindNextGreaterElement)

BOOST_AUTO_TEST_CASE(empty_data)
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

BOOST_AUTO_TEST_CASE(invalid_data)
{
    std::vector<int> nums1(2, 0), nums2(1, 0);
    std::vector<int> expected;

    BOOST_CHECK(expected ==
                Algo::Search::FindNextGreaterElem::FindSimple(nums1, nums2));

    BOOST_CHECK(expected ==
                Algo::Search::FindNextGreaterElem::FindUsingStack(nums1, nums2));
}

BOOST_AUTO_TEST_CASE(two_arrays)
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

BOOST_AUTO_TEST_CASE(next_greater_temperature)
{
    const std::vector<int> temp = {73, 74, 75, 71, 69, 72, 76, 73};
    const std::vector<int> expected = {1, 1, 4, 2, 1, 1, 0, 0};
    BOOST_CHECK(expected == Algo::Search::FindNextGreaterElem::FindNextGreaterTemperature(temp));
}

BOOST_AUTO_TEST_CASE(in_circular_arr)
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

BOOST_AUTO_TEST_CASE(smallest_greater_num)
{
    BOOST_CHECK(-1 ==
        Algo::Search::FindNextGreaterElem::FindSmallestGreaterNum(0));

    BOOST_CHECK(-1 ==
        Algo::Search::FindNextGreaterElem::FindSmallestGreaterNum(1));

    BOOST_CHECK(-1 ==
        Algo::Search::FindNextGreaterElem::FindSmallestGreaterNum(10));

    BOOST_CHECK(21 ==
        Algo::Search::FindNextGreaterElem::FindSmallestGreaterNum(12));

    BOOST_CHECK(132 ==
        Algo::Search::FindNextGreaterElem::FindSmallestGreaterNum(123));

    BOOST_CHECK(-1 ==
        Algo::Search::FindNextGreaterElem::FindSmallestGreaterNum(1999999999));

    BOOST_CHECK(1243 ==
        Algo::Search::FindNextGreaterElem::FindSmallestGreaterNum(1234));

    BOOST_CHECK(230412 ==
        Algo::Search::FindNextGreaterElem::FindSmallestGreaterNum(230241));

    BOOST_CHECK(13222344 ==
        Algo::Search::FindNextGreaterElem::FindSmallestGreaterNum(12443322));
}

BOOST_AUTO_TEST_SUITE_END()
