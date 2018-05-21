#ifndef TEST_COUNTING_SORT_HPP
#define TEST_COUNTING_SORT_HPP

#include <boost/test/unit_test.hpp>
#include <algorithm>

#include "algorithms/sorting/counting_sort.hpp"
#include "testcases_for_sorting_algorithms.hpp"

using namespace TCFSortingAlgo;

std::vector<unsigned char> ConvertVectors(const std::vector<int>& v) {
    std::vector<unsigned char> result;
    for (size_t i = 0; i < v.size(); ++i) {
        result.push_back( static_cast<unsigned char>( std::abs(v[i]) ) );
    }

    return result;
}

BOOST_AUTO_TEST_CASE(test_countsort_empty_container)
{
    std::vector<unsigned char> container = ConvertVectors(EmptyContainer());
    std::vector<unsigned char> result = CS::Solution::CountingSort(container);
    BOOST_CHECK(std::is_sorted(result.begin(), result.end()));
}

BOOST_AUTO_TEST_CASE(test_countsort_one_value)
{
    std::vector<unsigned char> container = ConvertVectors(ContainerWithOneValue());
    std::vector<unsigned char> result = CS::Solution::CountingSort(container);
    BOOST_CHECK(std::is_sorted(result.begin(), result.end()));
}

BOOST_AUTO_TEST_CASE(test_countsort_sorted_container)
{
    std::vector<unsigned char> container = ConvertVectors(SortedContainer());
    std::vector<unsigned char> result = CS::Solution::CountingSort(container);
    BOOST_CHECK(std::is_sorted(result.begin(), result.end()));
}

BOOST_AUTO_TEST_CASE(test_countsort_min_max_int_values)
{
    std::vector<unsigned char> container = ConvertVectors(ContainerWithMinAndMaxValues());
    std::vector<unsigned char> result = CS::Solution::CountingSort(container);
    BOOST_CHECK(std::is_sorted(result.begin(), result.end()));
}

BOOST_AUTO_TEST_CASE(test_countsort_positive_negative_values)
{
    std::vector<unsigned char> container = ConvertVectors(ContainerWithPositiveAndNegativeValues());
    std::vector<unsigned char> result = CS::Solution::CountingSort(container);
    BOOST_CHECK(std::is_sorted(result.begin(), result.end()));
}

BOOST_AUTO_TEST_CASE(test_countsort_duplicate_values)
{
    std::vector<unsigned char> container = ConvertVectors(ContainerWithDuplicates());
    std::vector<unsigned char> result = CS::Solution::CountingSort(container);
    BOOST_CHECK(std::is_sorted(result.begin(), result.end()));
}

BOOST_AUTO_TEST_CASE(test_countsort_many_values)
{
    std::vector<unsigned char> container = ConvertVectors(ContainerWithManyValues());
    std::vector<unsigned char> result = CS::Solution::CountingSort(container);
    BOOST_CHECK(std::is_sorted(result.begin(), result.end()));
}

BOOST_AUTO_TEST_CASE(test_countsort_random_values)
{
    for (int i = 0; i < 10; ++i) {
        std::vector<unsigned char> container = ConvertVectors(RandomContainer());
        std::vector<unsigned char> result = CS::Solution::CountingSort(container);
        BOOST_CHECK(std::is_sorted(result.begin(), result.end()));
    }
}

#endif // TEST_COUNTING_SORT_HPP

