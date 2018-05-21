#ifndef TEST_MERGESORT_H_
#define TEST_MERGESORT_H_

#include <boost/test/unit_test.hpp>

#include "algorithms/sorting/merge_sort.hpp"
#include "testcases_for_sorting_algorithms.hpp"

using namespace TCFSortingAlgo;

BOOST_AUTO_TEST_CASE(test_ms_empty_container)
{
    std::vector<int> container = EmptyContainer();
    std::vector<int> result = MS::Solution<std::vector<int>>::MergeSort(container);
    BOOST_CHECK(std::vector<int>() == result);
}

BOOST_AUTO_TEST_CASE(test_ms_one_value)
{
    std::vector<int> container = ContainerWithOneValue();
    std::vector<int> result = MS::Solution<std::vector<int>>::MergeSort(container);
    BOOST_CHECK(std::is_sorted(result.begin(), result.end()));
}

BOOST_AUTO_TEST_CASE(test_ms_sorted_container)
{
    std::vector<int> container = SortedContainer();
    std::vector<int> result = MS::Solution<std::vector<int>>::MergeSort(container);
    BOOST_CHECK(std::is_sorted(result.begin(), result.end()));
}

BOOST_AUTO_TEST_CASE(test_ms_min_max_int_values)
{
    std::vector<int> container = ContainerWithMinAndMaxValues();
    std::vector<int> result = MS::Solution<std::vector<int>>::MergeSort(container);
    BOOST_CHECK(std::is_sorted(result.begin(), result.end()));
}

BOOST_AUTO_TEST_CASE(test_ms_positive_negative_values)
{
    std::vector<int> container = ContainerWithPositiveAndNegativeValues();
    std::vector<int> result = MS::Solution<std::vector<int>>::MergeSort(container);
    BOOST_CHECK(std::is_sorted(result.begin(), result.end()));
}

BOOST_AUTO_TEST_CASE(test_ms_duplicate_values)
{
    std::vector<int> container = ContainerWithDuplicates();
    std::vector<int> result = MS::Solution<std::vector<int>>::MergeSort(container);
    BOOST_CHECK(std::is_sorted(result.begin(), result.end()));
}

BOOST_AUTO_TEST_CASE(test_ms_many_values)
{
    std::vector<int> container = ContainerWithManyValues();
    std::vector<int> result = MS::Solution<std::vector<int>>::MergeSort(container);
    BOOST_CHECK(std::is_sorted(result.begin(), result.end()));
}

BOOST_AUTO_TEST_CASE(test_ms_random_values)
{
    for (int i = 0; i < 10; ++i) {
        std::vector<int> container = RandomContainer();
        std::vector<int> result = MS::Solution<std::vector<int>>::MergeSort(container);
        BOOST_CHECK(std::is_sorted(container.begin(), container.end()));
    }
}

#endif /* TEST_MERGESORT_H_ */
