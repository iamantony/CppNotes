#include <boost/test/unit_test.hpp>
#include "common/equality.hpp"
#include "algorithms/data_structures/array/median_of_two_sorted_arrays.hpp"

BOOST_AUTO_TEST_SUITE(TestMedianOfTwoSortedArrays)

BOOST_AUTO_TEST_CASE(empty_arrays)
{
    std::vector<int> first, second;
    MedianOfTwoSortedArrays::Solution solution;
    double result = solution.findMedianSortedArrays(first, second);

    BOOST_CHECK(equal(result, 0.0));
}

BOOST_AUTO_TEST_CASE(empty_and_size_1_arrays)
{
    std::vector<int> first;
    std::vector<int> second = {1};

    MedianOfTwoSortedArrays::Solution solution;
    double result = solution.findMedianSortedArrays(first, second);

    BOOST_CHECK(equal(result, 1.0));
}

BOOST_AUTO_TEST_CASE(empty_and_small_arrays)
{
    std::vector<int> first;
    std::vector<int> second = {2, 3};

    MedianOfTwoSortedArrays::Solution solution;
    double result = solution.findMedianSortedArrays(first, second);

    BOOST_CHECK(equal(result, 2.5));
}

BOOST_AUTO_TEST_CASE(two_arrays)
{
    std::vector<int> first = {1, 2};
    std::vector<int> second = {3, 4};

    MedianOfTwoSortedArrays::Solution solution;
    double result = solution.findMedianSortedArrays(first, second);

    BOOST_CHECK(equal(result, 2.5));
}

BOOST_AUTO_TEST_CASE(two_small_arrays)
{
    std::vector<int> first = {1, 1};
    std::vector<int> second = {1, 2};

    MedianOfTwoSortedArrays::Solution solution;
    double result = solution.findMedianSortedArrays(first, second);

    BOOST_CHECK(equal(result, 1.0));
}

BOOST_AUTO_TEST_CASE(two_arrays_diff_size)
{
    std::vector<int> first = {1, 2, 3, 6};
    std::vector<int> second = {9, 14, 17, 25, 26};

    MedianOfTwoSortedArrays::Solution solution;
    double result = solution.findMedianSortedArrays(first, second);

    BOOST_CHECK(equal(result, 9.0));
}

BOOST_AUTO_TEST_SUITE_END()

