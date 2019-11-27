#include <boost/test/unit_test.hpp>
#include <algorithm>
#include "algorithms/sorting/counting_sort.hpp"
#include "testcases_for_sorting_algorithms.hpp"

BOOST_AUTO_TEST_SUITE(TestCountingSort)

using namespace TCFSortingAlgo;

BOOST_AUTO_TEST_CASE(empty_container)
{
    std::vector<unsigned char> container, expected;
    EmptyContainer(container, expected);
    std::vector<unsigned char> result =
            Algo::Sorting::CountingSort::Sort(container);
    BOOST_CHECK(expected == result);
}

BOOST_AUTO_TEST_CASE(one_value)
{
    std::vector<unsigned char> container, expected;
    ContainerWithOneValue(container, expected);
    std::vector<unsigned char> result =
            Algo::Sorting::CountingSort::Sort(container);
    BOOST_CHECK(expected == result);
}

BOOST_AUTO_TEST_CASE(sorted_container)
{
    std::vector<unsigned char> container, expected;
    SortedContainer(container, expected);
    std::vector<unsigned char> result =
            Algo::Sorting::CountingSort::Sort(container);
    BOOST_CHECK(expected == result);
}

BOOST_AUTO_TEST_CASE(min_max_int_values)
{
    std::vector<unsigned char> container, expected;
    ContainerWithMinAndMaxValues(container, expected);
    std::vector<unsigned char> result =
            Algo::Sorting::CountingSort::Sort(container);
    BOOST_CHECK(expected == result);
}

BOOST_AUTO_TEST_CASE(duplicate_values)
{
    std::vector<unsigned char> container, expected;
    ContainerWithDuplicates(container, expected);
    std::vector<unsigned char> result =
            Algo::Sorting::CountingSort::Sort(container);
    BOOST_CHECK(expected == result);
}

BOOST_AUTO_TEST_CASE(random_values)
{
    for (int i = 0; i < 10; ++i) {
        std::vector<unsigned char> container, expected;
        RandomContainer(container, expected, 1000);
        std::vector<unsigned char> result =
                Algo::Sorting::CountingSort::Sort(container);
        BOOST_CHECK(expected == result);
    }
}

BOOST_AUTO_TEST_SUITE_END()
