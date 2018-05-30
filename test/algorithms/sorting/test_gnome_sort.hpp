#ifndef TEST_GNOMESORT_H_
#define TEST_GNOMESORT_H_

#include <boost/test/unit_test.hpp>

#include "algorithms/sorting/gnome_sort.hpp"
#include "testcases_for_sorting_algorithms.hpp"

using namespace TCFSortingAlgo;

BOOST_AUTO_TEST_CASE(test_gs_empty_container)
{
    std::vector<int> container, expected;
    EmptyContainer(container, expected);
    GS::GnomeSort(container);
    BOOST_CHECK(container == expected);
}

BOOST_AUTO_TEST_CASE(test_gs_one_value)
{
    std::vector<int> container, expected;
    ContainerWithOneValue(container, expected);
    GS::GnomeSort(container);
    BOOST_CHECK(container == expected);
}

BOOST_AUTO_TEST_CASE(test_gs_sorted_container)
{
    std::vector<int> container, expected;
    SortedContainer(container, expected);
    GS::GnomeSort(container);
    BOOST_CHECK(container == expected);
}

BOOST_AUTO_TEST_CASE(test_gs_min_max_int_values)
{
    std::vector<int> container, expected;
    ContainerWithMinAndMaxValues(container, expected);
    GS::GnomeSort(container);
    BOOST_CHECK(container == expected);
}

BOOST_AUTO_TEST_CASE(test_gs_positive_negative_values)
{
    std::vector<int> container, expected;
    ContainerWithPositiveAndNegativeValues(container, expected);
    GS::GnomeSort(container);
    BOOST_CHECK(container == expected);
}

BOOST_AUTO_TEST_CASE(test_gs_duplicate_values)
{
    std::vector<int> container, expected;
    ContainerWithDuplicates(container, expected);
    GS::GnomeSort(container);
    BOOST_CHECK(container == expected);
}

BOOST_AUTO_TEST_CASE(test_gs_random_values)
{
    for (int i = 0; i < 10; ++i) {
        std::vector<int> container, expected;
        RandomContainer(container, expected, 100);
        GS::GnomeSort(container);
        BOOST_CHECK(container == expected);
    }
}

#endif /* TEST_GNOMESORT_H_ */
