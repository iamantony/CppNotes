#ifndef TEST_SELECTIONSORT_H_
#define TEST_SELECTIONSORT_H_

#include <boost/test/unit_test.hpp>

#include "algorithms/sorting/selection_sort.hpp"
#include "testcases_for_sorting_algorithms.hpp"

using namespace TCFSortingAlgo;

BOOST_AUTO_TEST_CASE(test_ss_empty_container)
{
    std::vector<int> container, expected;
    EmptyContainer(container, expected);
    SSort::Solution solution;
    solution.SelectionSort(container);
    BOOST_CHECK(container == expected);
}

BOOST_AUTO_TEST_CASE(test_ss_one_value)
{
    std::vector<int> container, expected;
    ContainerWithOneValue(container, expected);
    SSort::Solution solution;
    solution.SelectionSort(container);
    BOOST_CHECK(container == expected);
}

BOOST_AUTO_TEST_CASE(test_ss_sorted_container)
{
    std::vector<int> container, expected;
    SortedContainer(container, expected);
    SSort::Solution solution;
    solution.SelectionSort(container);
    BOOST_CHECK(container == expected);
}

BOOST_AUTO_TEST_CASE(test_ss_min_max_int_values)
{
    std::vector<int> container, expected;
    ContainerWithMinAndMaxValues(container, expected);
    SSort::Solution solution;
    solution.SelectionSort(container);
    BOOST_CHECK(container == expected);
}

BOOST_AUTO_TEST_CASE(test_ss_positive_negative_values)
{
    std::vector<int> container, expected;
    ContainerWithPositiveAndNegativeValues(container, expected);
    SSort::Solution solution;
    solution.SelectionSort(container);
    BOOST_CHECK(container == expected);
}

BOOST_AUTO_TEST_CASE(test_ss_duplicate_values)
{
    std::vector<int> container, expected;
    ContainerWithDuplicates(container, expected);
    SSort::Solution solution;
    solution.SelectionSort(container);
    BOOST_CHECK(container == expected);
}

BOOST_AUTO_TEST_CASE(test_ss_random_values)
{
    for (int i = 0; i < 10; ++i) {
        std::vector<int> container, expected;
        RandomContainer(container, expected, 100);
        SSort::Solution solution;
        solution.SelectionSort(container);
        BOOST_CHECK(container == expected);
    }
}

#endif /* TEST_SELECTIONSORT_H_ */
