#ifndef TEST_SELECTIONSORT_H_
#define TEST_SELECTIONSORT_H_

#include <boost/test/unit_test.hpp>

#include "algorithms/sorting/selection_sort.hpp"
#include "testcases_for_sorting_algorithms.hpp"

using namespace TCFSortingAlgo;

BOOST_AUTO_TEST_CASE(test_ss_empty_container)
{
    std::vector<int> container = EmptyContainer();
    SSort::Solution solution;
    solution.SelectionSort(container);
    BOOST_CHECK(std::is_sorted(container.begin(), container.end()));
}

BOOST_AUTO_TEST_CASE(test_ss_one_value)
{
    std::vector<int> container = ContainerWithOneValue();
    SSort::Solution solution;
    solution.SelectionSort(container);
    BOOST_CHECK(std::is_sorted(container.begin(), container.end()));
}

BOOST_AUTO_TEST_CASE(test_ss_sorted_container)
{
    std::vector<int> container = SortedContainer();
    SSort::Solution solution;
    solution.SelectionSort(container);
    BOOST_CHECK(std::is_sorted(container.begin(), container.end()));
}

BOOST_AUTO_TEST_CASE(test_ss_min_max_int_values)
{
    std::vector<int> container = ContainerWithMinAndMaxValues();
    SSort::Solution solution;
    solution.SelectionSort(container);
    BOOST_CHECK(std::is_sorted(container.begin(), container.end()));
}

BOOST_AUTO_TEST_CASE(test_ss_positive_negative_values)
{
    std::vector<int> container = ContainerWithPositiveAndNegativeValues();
    SSort::Solution solution;
    solution.SelectionSort(container);
    BOOST_CHECK(std::is_sorted(container.begin(), container.end()));
}

BOOST_AUTO_TEST_CASE(test_ss_duplicate_values)
{
    std::vector<int> container = ContainerWithDuplicates();
    SSort::Solution solution;
    solution.SelectionSort(container);
    BOOST_CHECK(std::is_sorted(container.begin(), container.end()));
}

BOOST_AUTO_TEST_CASE(test_ss_many_values)
{
    std::vector<int> container = ContainerWithManyValues();
    SSort::Solution solution;
    solution.SelectionSort(container);
    BOOST_CHECK(std::is_sorted(container.begin(), container.end()));
}

BOOST_AUTO_TEST_CASE(test_ss_random_values)
{
    for (int i = 0; i < 10; ++i) {
        std::vector<int> container = RandomContainer(1000);
        SSort::Solution solution;
        solution.SelectionSort(container);
        BOOST_CHECK(std::is_sorted(container.begin(), container.end()));
    }
}

#endif /* TEST_SELECTIONSORT_H_ */
