#ifndef TEST_INSERTIONSORT_H_
#define TEST_INSERTIONSORT_H_

#include <boost/test/unit_test.hpp>

#include "algorithms/sorting/insertion_sort.hpp"
#include "testcases_for_sorting_algorithms.hpp"

using namespace TCFSortingAlgo;

BOOST_AUTO_TEST_CASE(test_is_empty_container)
{
    BOOST_CHECK(std::vector<int>() == InsertionSort(EmptyContainer()));
}

BOOST_AUTO_TEST_CASE(test_is_one_value)
{
    std::vector<int> result = InsertionSort(ContainerWithOneValue());
    BOOST_CHECK(std::is_sorted(result.begin(), result.end()));
}

BOOST_AUTO_TEST_CASE(test_is_sorted_container)
{
    std::vector<int> result = InsertionSort(SortedContainer());
    BOOST_CHECK(std::is_sorted(result.begin(), result.end()));
}

BOOST_AUTO_TEST_CASE(test_is_min_max_int_values)
{
    std::vector<int> result = InsertionSort(ContainerWithMinAndMaxValues());
    BOOST_CHECK(std::is_sorted(result.begin(), result.end()));
}

BOOST_AUTO_TEST_CASE(test_is_positive_negative_values)
{
    std::vector<int> result =
            InsertionSort(ContainerWithPositiveAndNegativeValues());

    BOOST_CHECK(std::is_sorted(result.begin(), result.end()));
}

BOOST_AUTO_TEST_CASE(test_is_duplicate_values)
{
    std::vector<int> result = InsertionSort(ContainerWithDuplicates());
    BOOST_CHECK(std::is_sorted(result.begin(), result.end()));
}

BOOST_AUTO_TEST_CASE(test_is_many_values)
{
    std::vector<int> result = InsertionSort(ContainerWithManyValues());
    BOOST_CHECK(std::is_sorted(result.begin(), result.end()));
}

#endif /* TEST_INSERTIONSORT_H_ */
