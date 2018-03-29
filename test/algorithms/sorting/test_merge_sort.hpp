#ifndef TEST_MERGESORT_H_
#define TEST_MERGESORT_H_

#include <boost/test/unit_test.hpp>

#include "algorithms/sorting/merge_sort.hpp"
#include "testcases_for_sorting_algorithms.hpp"

using namespace TCFSortingAlgo;

BOOST_AUTO_TEST_CASE(test_ms_empty_container)
{
    BOOST_CHECK(std::vector<int>() == MergeSort(EmptyContainer()));
}

BOOST_AUTO_TEST_CASE(test_ms_one_value)
{
    std::vector<int> result = MergeSort(ContainerWithOneValue());
    BOOST_CHECK(std::is_sorted(result.begin(), result.end()));
}

BOOST_AUTO_TEST_CASE(test_ms_sorted_container)
{
    std::vector<int> result = MergeSort(SortedContainer());
    BOOST_CHECK(std::is_sorted(result.begin(), result.end()));
}

BOOST_AUTO_TEST_CASE(test_ms_min_max_int_values)
{
    std::vector<int> result = MergeSort(ContainerWithMinAndMaxValues());
    BOOST_CHECK(std::is_sorted(result.begin(), result.end()));
}

BOOST_AUTO_TEST_CASE(test_ms_positive_negative_values)
{
    std::vector<int> result =
            MergeSort(ContainerWithPositiveAndNegativeValues());

    BOOST_CHECK(std::is_sorted(result.begin(), result.end()));
}

BOOST_AUTO_TEST_CASE(test_ms_duplicate_values)
{
    std::vector<int> result = MergeSort(ContainerWithDuplicates());
    BOOST_CHECK(std::is_sorted(result.begin(), result.end()));
}

BOOST_AUTO_TEST_CASE(test_ms_many_values)
{
    std::vector<int> result = MergeSort(ContainerWithManyValues());
    BOOST_CHECK(std::is_sorted(result.begin(), result.end()));
}

#endif /* TEST_MERGESORT_H_ */
