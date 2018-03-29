#ifndef TEST_QUICKSORT_H_
#define TEST_QUICKSORT_H_

#include <boost/test/unit_test.hpp>

#include "algorithms/sorting/quicksort.hpp"
#include "testcases_for_sorting_algorithms.hpp"

using namespace TCFSortingAlgo;

BOOST_AUTO_TEST_CASE(test_qs_empty_container)
{
    BOOST_CHECK(std::vector<int>() == QuickSort(EmptyContainer()));
}

BOOST_AUTO_TEST_CASE(test_qs_one_value)
{
    std::vector<int> result = QuickSort(ContainerWithOneValue());
    BOOST_CHECK(std::is_sorted(result.begin(), result.end()));
}

BOOST_AUTO_TEST_CASE(test_qs_sorted_container)
{
    std::vector<int> result = QuickSort(SortedContainer());
    BOOST_CHECK(std::is_sorted(result.begin(), result.end()));
}

BOOST_AUTO_TEST_CASE(test_qs_min_max_int_values)
{
    std::vector<int> result = QuickSort(ContainerWithMinAndMaxValues());
    BOOST_CHECK(std::is_sorted(result.begin(), result.end()));
}

BOOST_AUTO_TEST_CASE(test_qs_positive_negative_values)
{
    std::vector<int> result =
            QuickSort(ContainerWithPositiveAndNegativeValues());

    BOOST_CHECK(std::is_sorted(result.begin(), result.end()));
}

BOOST_AUTO_TEST_CASE(test_qs_duplicate_values)
{
    std::vector<int> result = QuickSort(ContainerWithDuplicates());
    BOOST_CHECK(std::is_sorted(result.begin(), result.end()));
}

BOOST_AUTO_TEST_CASE(test_qs_many_values)
{
    std::vector<int> result = QuickSort(ContainerWithManyValues());
    BOOST_CHECK(std::is_sorted(result.begin(), result.end()));
}

#endif /* TEST_QUICKSORT_H_ */
