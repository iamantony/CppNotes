#include <boost/test/unit_test.hpp>
#include "algorithms/sorting/insertion_sort.hpp"
#include "testcases_for_sorting_algorithms.hpp"

BOOST_AUTO_TEST_SUITE(TestInsertionSort)

using namespace TCFSortingAlgo;

BOOST_AUTO_TEST_CASE(empty_container)
{
    std::vector<int> container, expected;
    EmptyContainer(container, expected);
    Algo::Sorting::InsertionSort<std::vector<int>>::Sort(container);
    BOOST_CHECK(container == expected);
}

BOOST_AUTO_TEST_CASE(one_value)
{
    std::vector<int> container, expected;
    ContainerWithOneValue(container, expected);
    Algo::Sorting::InsertionSort<std::vector<int>>::Sort(container);
    BOOST_CHECK(container == expected);
}

BOOST_AUTO_TEST_CASE(sorted_container)
{
    std::vector<int> container, expected;
    SortedContainer(container, expected);
    Algo::Sorting::InsertionSort<std::vector<int>>::Sort(container);
    BOOST_CHECK(container == expected);
}

BOOST_AUTO_TEST_CASE(min_max_int_values)
{
    std::vector<int> container, expected;
    ContainerWithMinAndMaxValues(container, expected);
    Algo::Sorting::InsertionSort<std::vector<int>>::Sort(container);
    BOOST_CHECK(container == expected);
}

BOOST_AUTO_TEST_CASE(positive_negative_values)
{
    std::vector<int> container, expected;
    ContainerWithPositiveAndNegativeValues(container, expected);
    Algo::Sorting::InsertionSort<std::vector<int>>::Sort(container);
    BOOST_CHECK(container == expected);
}

BOOST_AUTO_TEST_CASE(duplicate_values)
{
    std::vector<int> container, expected;
    ContainerWithDuplicates(container, expected);
    Algo::Sorting::InsertionSort<std::vector<int>>::Sort(container);
    BOOST_CHECK(container == expected);
}

BOOST_AUTO_TEST_CASE(random_values)
{
    for (int i = 0; i < 10; ++i) {
        std::vector<int> container, expected;
        RandomContainer(container, expected, 100);
        Algo::Sorting::InsertionSort<std::vector<int>>::Sort(container);
        BOOST_CHECK(container == expected);
    }
}

BOOST_AUTO_TEST_SUITE_END()
