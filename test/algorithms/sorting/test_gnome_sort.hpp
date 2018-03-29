#ifndef TEST_GNOMESORT_H_
#define TEST_GNOMESORT_H_

#include <boost/test/unit_test.hpp>

#include "algorithms/sorting/gnome_sort.hpp"
#include "testcases_for_sorting_algorithms.hpp"

using namespace TCFSortingAlgo;

BOOST_AUTO_TEST_CASE(test_gs_empty_container)
{
    BOOST_CHECK(std::vector<int>() == GnomeSort(EmptyContainer()));
}

BOOST_AUTO_TEST_CASE(test_gs_one_value)
{
    std::vector<int> result = GnomeSort(ContainerWithOneValue());
    BOOST_CHECK(std::is_sorted(result.begin(), result.end()));
}

BOOST_AUTO_TEST_CASE(test_gs_sorted_container)
{
    std::vector<int> result = GnomeSort(SortedContainer());
    BOOST_CHECK(std::is_sorted(result.begin(), result.end()));
}

BOOST_AUTO_TEST_CASE(test_gs_min_max_int_values)
{
    std::vector<int> result = GnomeSort(ContainerWithMinAndMaxValues());
    BOOST_CHECK(std::is_sorted(result.begin(), result.end()));
}

BOOST_AUTO_TEST_CASE(test_gs_positive_negative_values)
{
    std::vector<int> result =
            GnomeSort(ContainerWithPositiveAndNegativeValues());

    BOOST_CHECK(std::is_sorted(result.begin(), result.end()));
}

BOOST_AUTO_TEST_CASE(test_gs_duplicate_values)
{
    std::vector<int> result = GnomeSort(ContainerWithDuplicates());
    BOOST_CHECK(std::is_sorted(result.begin(), result.end()));
}

BOOST_AUTO_TEST_CASE(test_gs_many_values)
{
    std::vector<int> result = GnomeSort(ContainerWithManyValues());
    BOOST_CHECK(std::is_sorted(result.begin(), result.end()));
}

#endif /* TEST_GNOMESORT_H_ */
