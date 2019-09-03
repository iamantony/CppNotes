#ifndef TEST_QUICKSORT_H_
#define TEST_QUICKSORT_H_

#include <boost/test/unit_test.hpp>
#include <algorithm>

#include "algorithms/sorting/quicksort.hpp"
#include "testcases_for_sorting_algorithms.hpp"

using namespace TCFSortingAlgo;

BOOST_AUTO_TEST_CASE(test_qs_empty_container)
{
    {
        std::vector<int> container, expected;
        EmptyContainer(container, expected);
        Algo::Sorting::QuickSort<std::vector<int>>::Sort(container,
            Algo::Sorting::QuickSort<std::vector<int>>::Type::BASIC);
        BOOST_CHECK(container == expected);
    }

    {
        std::vector<int> container, expected;
        EmptyContainer(container, expected);
        Algo::Sorting::QuickSort<std::vector<int>>::Sort(container,
            Algo::Sorting::QuickSort<std::vector<int>>::Type::THREE_WAY);
        BOOST_CHECK(container == expected);
    }
}

BOOST_AUTO_TEST_CASE(test_qs_one_value)
{
    {
        std::vector<int> container, expected;
        ContainerWithOneValue(container, expected);
        Algo::Sorting::QuickSort<std::vector<int>>::Sort(container,
            Algo::Sorting::QuickSort<std::vector<int>>::Type::BASIC);
        BOOST_CHECK(container == expected);
    }

    {
        std::vector<int> container, expected;
        ContainerWithOneValue(container, expected);
        Algo::Sorting::QuickSort<std::vector<int>>::Sort(container,
            Algo::Sorting::QuickSort<std::vector<int>>::Type::THREE_WAY);
        BOOST_CHECK(container == expected);
    }
}

BOOST_AUTO_TEST_CASE(test_qs_sorted_container)
{
    {
        std::vector<int> container, expected;
        SortedContainer(container, expected);
        Algo::Sorting::QuickSort<std::vector<int>>::Sort(container,
            Algo::Sorting::QuickSort<std::vector<int>>::Type::BASIC);
        BOOST_CHECK(container == expected);
    }

    {
        std::vector<int> container, expected;
        SortedContainer(container, expected);
        Algo::Sorting::QuickSort<std::vector<int>>::Sort(container,
            Algo::Sorting::QuickSort<std::vector<int>>::Type::THREE_WAY);
        BOOST_CHECK(container == expected);
    }
}

BOOST_AUTO_TEST_CASE(test_qs_min_max_int_values)
{
    {
        std::vector<int> container, expected;
        ContainerWithMinAndMaxValues(container, expected);
        Algo::Sorting::QuickSort<std::vector<int>>::Sort(container,
            Algo::Sorting::QuickSort<std::vector<int>>::Type::BASIC);
        BOOST_CHECK(container == expected);
    }

    {
        std::vector<int> container, expected;
        ContainerWithMinAndMaxValues(container, expected);
        Algo::Sorting::QuickSort<std::vector<int>>::Sort(container,
            Algo::Sorting::QuickSort<std::vector<int>>::Type::THREE_WAY);
        BOOST_CHECK(container == expected);
    }
}

BOOST_AUTO_TEST_CASE(test_qs_positive_negative_values)
{
    {
        std::vector<int> container, expected;
        ContainerWithPositiveAndNegativeValues(container, expected);
        Algo::Sorting::QuickSort<std::vector<int>>::Sort(container,
            Algo::Sorting::QuickSort<std::vector<int>>::Type::BASIC);
        BOOST_CHECK(container == expected);
    }

    {
        std::vector<int> container, expected;
        ContainerWithPositiveAndNegativeValues(container, expected);
        Algo::Sorting::QuickSort<std::vector<int>>::Sort(container,
            Algo::Sorting::QuickSort<std::vector<int>>::Type::THREE_WAY);
        BOOST_CHECK(container == expected);
    }
}

BOOST_AUTO_TEST_CASE(test_qs_duplicate_values)
{
    {
        std::vector<int> container, expected;
        ContainerWithDuplicates(container, expected);
        Algo::Sorting::QuickSort<std::vector<int>>::Sort(container,
            Algo::Sorting::QuickSort<std::vector<int>>::Type::BASIC);
        BOOST_CHECK(container == expected);
    }

    {
        std::vector<int> container, expected;
        ContainerWithDuplicates(container, expected);
        Algo::Sorting::QuickSort<std::vector<int>>::Sort(container,
            Algo::Sorting::QuickSort<std::vector<int>>::Type::THREE_WAY);
        BOOST_CHECK(container == expected);
    }
}

BOOST_AUTO_TEST_CASE(test_qs_random_values)
{
    for (int i = 0; i < 10; ++i) {
        std::vector<int> container, expected;
        RandomContainer(container, expected, 1000);
        Algo::Sorting::QuickSort<std::vector<int>>::Sort(container,
            Algo::Sorting::QuickSort<std::vector<int>>::Type::BASIC);
        BOOST_CHECK(container == expected);
    }

    for (int i = 0; i < 10; ++i) {
        std::vector<int> container, expected;
        RandomContainer(container, expected, 1000);
        Algo::Sorting::QuickSort<std::vector<int>>::Sort(container,
            Algo::Sorting::QuickSort<std::vector<int>>::Type::THREE_WAY);
        BOOST_CHECK(container == expected);
    }
}

#endif /* TEST_QUICKSORT_H_ */
