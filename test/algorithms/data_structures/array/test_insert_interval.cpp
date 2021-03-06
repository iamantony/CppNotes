#include <boost/test/unit_test.hpp>
#include "algorithms/data_structures/array/insert_interval.hpp"

BOOST_AUTO_TEST_SUITE(TestIntersectInterval)

BOOST_AUTO_TEST_CASE(empty_args)
{
    std::vector<std::vector<int>> intervals;
    std::vector<int> newInterval;
    std::vector<std::vector<int>> expected;
    BOOST_CHECK(expected ==
                Algo::DS::Array::InsertInverval::Insert(intervals, newInterval));
}

BOOST_AUTO_TEST_CASE(empty_intervals)
{
    std::vector<std::vector<int>> intervals;
    std::vector<int> newInterval = {1, 3};
    std::vector<std::vector<int>> expected = {{1, 3}};
    BOOST_CHECK(expected ==
                Algo::DS::Array::InsertInverval::Insert(intervals, newInterval));
}

BOOST_AUTO_TEST_CASE(base_case)
{
    std::vector<std::vector<int>> intervals = {{1, 3}, {6, 9}};
    std::vector<int> newInterval = {2, 5};
    std::vector<std::vector<int>> expected = {{1, 5}, {6, 9}};
    BOOST_CHECK(expected ==
                Algo::DS::Array::InsertInverval::Insert(intervals, newInterval));
}

BOOST_AUTO_TEST_CASE(long_interval)
{
    std::vector<std::vector<int>> intervals =
        {{1,2}, {3,5}, {6,7}, {8,10}, {12,16}};

    std::vector<int> newInterval = {4, 8};
    std::vector<std::vector<int>> expected = {{1,2}, {3,10}, {12, 16}};
    BOOST_CHECK(expected ==
                Algo::DS::Array::InsertInverval::Insert(intervals, newInterval));
}

BOOST_AUTO_TEST_SUITE_END()
