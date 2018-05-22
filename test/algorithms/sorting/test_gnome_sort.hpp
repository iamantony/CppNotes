#ifndef TEST_GNOMESORT_H_
#define TEST_GNOMESORT_H_

#include <boost/test/unit_test.hpp>

#include "algorithms/sorting/gnome_sort.hpp"
#include "testcases_for_sorting_algorithms.hpp"

using namespace TCFSortingAlgo;

BOOST_AUTO_TEST_CASE(test_gs_empty_container)
{
    std::vector<int> container = EmptyContainer();
    GS::GnomeSort(container);
    BOOST_CHECK(std::is_sorted(container.begin(), container.end()));
}

BOOST_AUTO_TEST_CASE(test_gs_one_value)
{
    std::vector<int> container = ContainerWithOneValue();
    GS::GnomeSort(container);
    BOOST_CHECK(std::is_sorted(container.begin(), container.end()));
}

BOOST_AUTO_TEST_CASE(test_gs_sorted_container)
{
    std::vector<int> container = SortedContainer();
    GS::GnomeSort(container);
    BOOST_CHECK(std::is_sorted(container.begin(), container.end()));
}

BOOST_AUTO_TEST_CASE(test_gs_min_max_int_values)
{
    std::vector<int> container = ContainerWithMinAndMaxValues();
    GS::GnomeSort(container);
    BOOST_CHECK(std::is_sorted(container.begin(), container.end()));
}

BOOST_AUTO_TEST_CASE(test_gs_positive_negative_values)
{
    std::vector<int> container = ContainerWithPositiveAndNegativeValues();
    GS::GnomeSort(container);
    BOOST_CHECK(std::is_sorted(container.begin(), container.end()));
}

BOOST_AUTO_TEST_CASE(test_gs_duplicate_values)
{
    std::vector<int> container = ContainerWithDuplicates();
    GS::GnomeSort(container);
    BOOST_CHECK(std::is_sorted(container.begin(), container.end()));
}

BOOST_AUTO_TEST_CASE(test_gs_many_values)
{
    std::vector<int> container = ContainerWithManyValues();
    GS::GnomeSort(container);
    BOOST_CHECK(std::is_sorted(container.begin(), container.end()));
}

BOOST_AUTO_TEST_CASE(test_gs_random_values)
{
    for (int i = 0; i < 10; ++i) {
        std::vector<int> container = RandomContainer(1000);
        GS::GnomeSort(container);
        BOOST_CHECK(std::is_sorted(container.begin(), container.end()));
    }
}

#endif /* TEST_GNOMESORT_H_ */
