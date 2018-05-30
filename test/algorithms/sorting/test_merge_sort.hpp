#ifndef TEST_MERGESORT_H_
#define TEST_MERGESORT_H_

#include <boost/test/unit_test.hpp>

#include "algorithms/sorting/merge_sort.hpp"
#include "testcases_for_sorting_algorithms.hpp"

using namespace TCFSortingAlgo;

BOOST_AUTO_TEST_CASE(test_ms_empty_container)
{
    std::vector<int> container, expected;
    EmptyContainer(container, expected);
    MS::Solution<std::vector<int>>::MergeSort(container);
    BOOST_CHECK(std::vector<int>() == container);
}

BOOST_AUTO_TEST_CASE(test_ms_one_value)
{
    std::vector<int> container, expected;
    ContainerWithOneValue(container, expected);
    MS::Solution<std::vector<int>>::MergeSort(container);
    BOOST_CHECK(container == expected);
}

BOOST_AUTO_TEST_CASE(test_ms_sorted_container)
{
    std::vector<int> container, expected;
    SortedContainer(container, expected);
    MS::Solution<std::vector<int>>::MergeSort(container);
    BOOST_CHECK(container == expected);
}

BOOST_AUTO_TEST_CASE(test_ms_min_max_int_values)
{
    std::vector<int> container, expected;
    ContainerWithMinAndMaxValues(container, expected);
    MS::Solution<std::vector<int>>::MergeSort(container);
    BOOST_CHECK(container == expected);
}

BOOST_AUTO_TEST_CASE(test_ms_positive_negative_values)
{
    std::vector<int> container, expected;
    ContainerWithPositiveAndNegativeValues(container, expected);
    MS::Solution<std::vector<int>>::MergeSort(container);
    BOOST_CHECK(container == expected);
}

BOOST_AUTO_TEST_CASE(test_ms_duplicate_values)
{
    std::vector<int> container, expected;
    ContainerWithDuplicates(container, expected);
    MS::Solution<std::vector<int>>::MergeSort(container);
    BOOST_CHECK(container == expected);
}

BOOST_AUTO_TEST_CASE(test_ms_random_values)
{
    for (int i = 0; i < 10; ++i) {
        std::vector<int> container, expected;
        RandomContainer(container, expected, 1000);
        MS::Solution<std::vector<int>>::MergeSort(container);
        BOOST_CHECK(container == expected);
    }
}

#endif /* TEST_MERGESORT_H_ */
