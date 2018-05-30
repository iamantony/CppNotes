#ifndef TEST_HEAP_SORT_HPP
#define TEST_HEAP_SORT_HPP
#include <boost/test/unit_test.hpp>

#include "algorithms/sorting/heap_sort.hpp"
#include "testcases_for_sorting_algorithms.hpp"

using namespace Algorithms::Sorting::HS;
using namespace TCFSortingAlgo;

BOOST_AUTO_TEST_CASE(test_heapsort_empty_container)
{
    std::vector<int> container, expected;
    EmptyContainer(container, expected);
    Solution<int>::HeapSort(container);
    BOOST_CHECK(container == expected);
}

BOOST_AUTO_TEST_CASE(test_heapsort_one_value)
{
    std::vector<int> container, expected;
    ContainerWithOneValue(container, expected);
    Solution<int>::HeapSort(container);
    BOOST_CHECK(container == expected);
}

BOOST_AUTO_TEST_CASE(test_heapsort_sorted_container)
{
    std::vector<int> container, expected;
    SortedContainer(container, expected);
    Solution<int>::HeapSort(container);
    BOOST_CHECK(container == expected);
}

BOOST_AUTO_TEST_CASE(test_heapsort_min_max_int_values)
{
    std::vector<int> container, expected;
    ContainerWithMinAndMaxValues(container, expected);
    Solution<int>::HeapSort(container);
    BOOST_CHECK(container == expected);
}

BOOST_AUTO_TEST_CASE(test_heapsort_positive_negative_values)
{
    std::vector<int> container, expected;
    ContainerWithPositiveAndNegativeValues(container, expected);
    Solution<int>::HeapSort(container);
    BOOST_CHECK(container == expected);
}

BOOST_AUTO_TEST_CASE(test_heapsort_duplicate_values)
{
    std::vector<int> container, expected;
    ContainerWithDuplicates(container, expected);
    Solution<int>::HeapSort(container);
    BOOST_CHECK(container == expected);
}

BOOST_AUTO_TEST_CASE(test_hs_random_values)
{
    for (int i = 0; i < 10; ++i) {
        std::vector<int> container, expected;
        RandomContainer(container, expected, 1000);
        Solution<int>::HeapSort(container);
        BOOST_CHECK(container == expected);
    }
}

#endif // TEST_HEAP_SORT_HPP

