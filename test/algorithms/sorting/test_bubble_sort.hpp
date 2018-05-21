#ifndef TEST_BUBBLESORT_H_
#define TEST_BUBBLESORT_H_

#include <boost/test/unit_test.hpp>
#include <algorithm>

#include "algorithms/sorting/bubble_sort.hpp"
#include "testcases_for_sorting_algorithms.hpp"

using namespace TCFSortingAlgo;

BOOST_AUTO_TEST_CASE(test_bs_empty_container)
{
    std::vector<int> containerToSort = EmptyContainer();
    BS::Solution::BubbleSort(containerToSort);
    BOOST_CHECK(std::is_sorted(containerToSort.begin(), containerToSort.end()));

    containerToSort = EmptyContainer();;
    BS::Solution::BubbleSortOptimised(containerToSort);
    BOOST_CHECK(std::is_sorted(containerToSort.begin(), containerToSort.end()));

    containerToSort = EmptyContainer();;
    BS::Solution::BubbleSortRecursive(containerToSort);
    BOOST_CHECK(std::is_sorted(containerToSort.begin(), containerToSort.end()));
}

BOOST_AUTO_TEST_CASE(test_bs_one_value)
{
    std::vector<int> containerToSort = ContainerWithOneValue();
    BS::Solution::BubbleSort(containerToSort);
    BOOST_CHECK(std::is_sorted(containerToSort.begin(), containerToSort.end()));

    containerToSort = ContainerWithOneValue();
    BS::Solution::BubbleSortOptimised(containerToSort);
    BOOST_CHECK(std::is_sorted(containerToSort.begin(), containerToSort.end()));

    containerToSort = ContainerWithOneValue();
    BS::Solution::BubbleSortRecursive(containerToSort);
    BOOST_CHECK(std::is_sorted(containerToSort.begin(), containerToSort.end()));
}

BOOST_AUTO_TEST_CASE(test_bs_sorted_container)
{
    std::vector<int> containerToSort = SortedContainer();
    BS::Solution::BubbleSort(containerToSort);
    BOOST_CHECK(std::is_sorted(containerToSort.begin(), containerToSort.end()));

    containerToSort = SortedContainer();
    BS::Solution::BubbleSortOptimised(containerToSort);
    BOOST_CHECK(std::is_sorted(containerToSort.begin(), containerToSort.end()));

    containerToSort = SortedContainer();
    BS::Solution::BubbleSortRecursive(containerToSort);
    BOOST_CHECK(std::is_sorted(containerToSort.begin(), containerToSort.end()));
}

BOOST_AUTO_TEST_CASE(test_bs_min_max_int_values)
{
    std::vector<int> containerToSort = ContainerWithMinAndMaxValues();
    BS::Solution::BubbleSort(containerToSort);
    BOOST_CHECK(std::is_sorted(containerToSort.begin(), containerToSort.end()));

    containerToSort = ContainerWithMinAndMaxValues();
    BS::Solution::BubbleSortOptimised(containerToSort);
    BOOST_CHECK(std::is_sorted(containerToSort.begin(), containerToSort.end()));

    containerToSort = ContainerWithMinAndMaxValues();
    BS::Solution::BubbleSortRecursive(containerToSort);
    BOOST_CHECK(std::is_sorted(containerToSort.begin(), containerToSort.end()));
}

BOOST_AUTO_TEST_CASE(test_bs_positive_negative_values)
{
    std::vector<int> containerToSort = ContainerWithPositiveAndNegativeValues();
    BS::Solution::BubbleSort(containerToSort);
    BOOST_CHECK(std::is_sorted(containerToSort.begin(), containerToSort.end()));

    containerToSort = ContainerWithPositiveAndNegativeValues();
    BS::Solution::BubbleSortOptimised(containerToSort);
    BOOST_CHECK(std::is_sorted(containerToSort.begin(), containerToSort.end()));

    containerToSort = ContainerWithPositiveAndNegativeValues();
    BS::Solution::BubbleSortRecursive(containerToSort);
    BOOST_CHECK(std::is_sorted(containerToSort.begin(), containerToSort.end()));
}

BOOST_AUTO_TEST_CASE(test_bs_duplicate_values)
{
    std::vector<int> containerToSort = ContainerWithDuplicates();
    BS::Solution::BubbleSort(containerToSort);
    BOOST_CHECK(std::is_sorted(containerToSort.begin(), containerToSort.end()));

    containerToSort = ContainerWithDuplicates();
    BS::Solution::BubbleSortOptimised(containerToSort);
    BOOST_CHECK(std::is_sorted(containerToSort.begin(), containerToSort.end()));

    containerToSort = ContainerWithDuplicates();
    BS::Solution::BubbleSortRecursive(containerToSort);
    BOOST_CHECK(std::is_sorted(containerToSort.begin(), containerToSort.end()));
}

BOOST_AUTO_TEST_CASE(test_bs_many_values)
{
    std::vector<int> containerToSort = ContainerWithManyValues();
    BS::Solution::BubbleSort(containerToSort);
    BOOST_CHECK(std::is_sorted(containerToSort.begin(), containerToSort.end()));

    containerToSort = ContainerWithManyValues();
    BS::Solution::BubbleSortOptimised(containerToSort);
    BOOST_CHECK(std::is_sorted(containerToSort.begin(), containerToSort.end()));

    containerToSort = ContainerWithManyValues();
    BS::Solution::BubbleSortRecursive(containerToSort);
    BOOST_CHECK(std::is_sorted(containerToSort.begin(), containerToSort.end()));
}

BOOST_AUTO_TEST_CASE(test_bs_random_values)
{
    for (int i = 0; i < 10; ++i) {
        std::vector<int> containerToSort = RandomContainer(10000);
        BS::Solution::BubbleSort(containerToSort);
        BOOST_CHECK(std::is_sorted(containerToSort.begin(), containerToSort.end()));

        containerToSort = RandomContainer(10000);
        BS::Solution::BubbleSortOptimised(containerToSort);
        BOOST_CHECK(std::is_sorted(containerToSort.begin(), containerToSort.end()));

        containerToSort = RandomContainer(10000);
        BS::Solution::BubbleSortRecursive(containerToSort);
        BOOST_CHECK(std::is_sorted(containerToSort.begin(), containerToSort.end()));
    }
}

#endif /* TEST_BUBBLESORT_H_ */
