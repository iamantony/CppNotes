#ifndef TEST_INSERTIONSORT_H_
#define TEST_INSERTIONSORT_H_

#include <boost/test/unit_test.hpp>

#include "algorithms/sorting/insertion_sort.hpp"
#include "testcases_for_sorting_algorithms.hpp"

using namespace TCFSortingAlgo;

BOOST_AUTO_TEST_CASE(test_is_empty_container)
{
    std::vector<int> container = EmptyContainer();
    IS::InsertionSort(container);
    BOOST_CHECK(std::is_sorted(container.begin(), container.end()));
}

BOOST_AUTO_TEST_CASE(test_is_one_value)
{
    std::vector<int> container = ContainerWithOneValue();
    IS::InsertionSort(container);
    BOOST_CHECK(std::is_sorted(container.begin(), container.end()));
}

BOOST_AUTO_TEST_CASE(test_is_sorted_container)
{
    std::vector<int> container = SortedContainer();
    IS::InsertionSort(container);
    BOOST_CHECK(std::is_sorted(container.begin(), container.end()));
}

BOOST_AUTO_TEST_CASE(test_is_min_max_int_values)
{
    std::vector<int> container = ContainerWithMinAndMaxValues();
    IS::InsertionSort(container);
    BOOST_CHECK(std::is_sorted(container.begin(), container.end()));
}

BOOST_AUTO_TEST_CASE(test_is_positive_negative_values)
{
    std::vector<int> container = ContainerWithPositiveAndNegativeValues();
    IS::InsertionSort(container);
    BOOST_CHECK(std::is_sorted(container.begin(), container.end()));
}

BOOST_AUTO_TEST_CASE(test_is_duplicate_values)
{
    std::vector<int> container = ContainerWithDuplicates();
    IS::InsertionSort(container);
    BOOST_CHECK(std::is_sorted(container.begin(), container.end()));
}

BOOST_AUTO_TEST_CASE(test_is_many_values)
{
    std::vector<int> container = ContainerWithManyValues();
    IS::InsertionSort(container);
    BOOST_CHECK(std::is_sorted(container.begin(), container.end()));
}

BOOST_AUTO_TEST_CASE(test_is_random_values)
{
    for (int i = 0; i < 10; ++i) {
        std::vector<int> container = RandomContainer(1000);
        IS::InsertionSort(container);
        BOOST_CHECK(std::is_sorted(container.begin(), container.end()));
    }
}

#endif /* TEST_INSERTIONSORT_H_ */
