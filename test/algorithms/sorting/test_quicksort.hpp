#ifndef TEST_QUICKSORT_H_
#define TEST_QUICKSORT_H_

#include <boost/test/unit_test.hpp>
#include <algorithm>

#include "algorithms/sorting/quicksort.hpp"
#include "testcases_for_sorting_algorithms.hpp"

using namespace TCFSortingAlgo;

BOOST_AUTO_TEST_CASE(test_qs_empty_container)
{
    std::vector<int> container = EmptyContainer();
    QS::Solution<std::vector<int>>::QuickSort(container);
    BOOST_CHECK(std::is_sorted(container.begin(), container.end()));
}

BOOST_AUTO_TEST_CASE(test_qs_one_value)
{
    std::vector<int> container = ContainerWithOneValue();
    QS::Solution<std::vector<int>>::QuickSort(container);
    BOOST_CHECK(std::is_sorted(container.begin(), container.end()));
}

BOOST_AUTO_TEST_CASE(test_qs_sorted_container)
{
    std::vector<int> container = SortedContainer();
    QS::Solution<std::vector<int>>::QuickSort(container);
    BOOST_CHECK(std::is_sorted(container.begin(), container.end()));
}

BOOST_AUTO_TEST_CASE(test_qs_min_max_int_values)
{
    std::vector<int> container = ContainerWithMinAndMaxValues();
    QS::Solution<std::vector<int>>::QuickSort(container);
    BOOST_CHECK(std::is_sorted(container.begin(), container.end()));
}

BOOST_AUTO_TEST_CASE(test_qs_positive_negative_values)
{
    std::vector<int> container = ContainerWithPositiveAndNegativeValues();
    QS::Solution<std::vector<int>>::QuickSort(container);
    BOOST_CHECK(std::is_sorted(container.begin(), container.end()));
}

BOOST_AUTO_TEST_CASE(test_qs_duplicate_values)
{
    std::vector<int> container = ContainerWithDuplicates();
    QS::Solution<std::vector<int>>::QuickSort(container);
    BOOST_CHECK(std::is_sorted(container.begin(), container.end()));
}

BOOST_AUTO_TEST_CASE(test_qs_many_values)
{
    std::vector<int> container = ContainerWithManyValues();
    QS::Solution<std::vector<int>>::QuickSort(container);
    BOOST_CHECK(std::is_sorted(container.begin(), container.end()));
}

BOOST_AUTO_TEST_CASE(test_qs_random_values)
{
    for (int i = 0; i < 10; ++i) {
        std::vector<int> container = RandomContainer();
        QS::Solution<std::vector<int>>::QuickSort(container);
        BOOST_CHECK(std::is_sorted(container.begin(), container.end()));
    }
}

#endif /* TEST_QUICKSORT_H_ */
