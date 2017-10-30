#ifndef TEST_MEDIAN_OF_TWO_SORTED_ARRAYS_HPP
#define TEST_MEDIAN_OF_TWO_SORTED_ARRAYS_HPP

#define BOOST_TEST_MODULE CppNotes test
#include <boost/test/unit_test.hpp>
#include "../common/utils.hpp"

#include "algorithms/median_of_two_sorted_arrays.hpp"

BOOST_AUTO_TEST_CASE(test_motsa_empty_arrays)
{
    std::vector<int> first, second;
    MedianOfTwoSortedArrays::Solution solution;
    double result = solution.findMedianSortedArrays(first, second);

    BOOST_CHECK(areEqual(result, 0.0));
}

BOOST_AUTO_TEST_CASE(test_motsa_empty_and_size_1_arrays)
{
    std::vector<int> first;
    std::vector<int> second = {1};

    MedianOfTwoSortedArrays::Solution solution;
    double result = solution.findMedianSortedArrays(first, second);

    BOOST_CHECK(areEqual(result, 1.0));
}

BOOST_AUTO_TEST_CASE(test_motsa_empty_and_small_arrays)
{
    std::vector<int> first;
    std::vector<int> second = {2, 3};

    MedianOfTwoSortedArrays::Solution solution;
    double result = solution.findMedianSortedArrays(first, second);

    BOOST_CHECK(areEqual(result, 2.5));
}

BOOST_AUTO_TEST_CASE(test_motsa_two_arrays)
{
    std::vector<int> first = {1, 2};
    std::vector<int> second = {3, 4};

    MedianOfTwoSortedArrays::Solution solution;
    double result = solution.findMedianSortedArrays(first, second);

    BOOST_CHECK(areEqual(result, 2.5));
}

BOOST_AUTO_TEST_CASE(test_motsa_two_small_arrays)
{
    std::vector<int> first = {1, 1};
    std::vector<int> second = {1, 2};

    MedianOfTwoSortedArrays::Solution solution;
    double result = solution.findMedianSortedArrays(first, second);

    BOOST_CHECK(areEqual(result, 1.0));
}

BOOST_AUTO_TEST_CASE(test_motsa_two_arrays_diff_size)
{
    std::vector<int> first = {1, 2, 3, 6};
    std::vector<int> second = {9, 14, 17, 25, 26};

    MedianOfTwoSortedArrays::Solution solution;
    double result = solution.findMedianSortedArrays(first, second);

    BOOST_CHECK(areEqual(result, 9.0));
}

#endif // TEST_MEDIAN_OF_TWO_SORTED_ARRAYS_HPP

