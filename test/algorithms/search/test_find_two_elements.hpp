#ifndef TEST_FIND_TWO_ELEMENTS_HPP_
#define TEST_FIND_TWO_ELEMENTS_HPP_

#define BOOST_TEST_MODULE CppNotes test
#include <boost/test/unit_test.hpp>

#include <vector>
#include <utility>

#include "algorithms/search/find_two_elements.hpp"

auto areAllPairsEqual = [](const std::vector<std::pair<int, int>>& first,
        const std::vector<std::pair<int, int>>& second)
{
    if (first.size() != second.size())
    {
        return false;
    }

    for (size_t i = 0; i < first.size(); ++i)
    {
        std::pair<int, int> orig = first[i];
        std::pair<int, int> inv = {first[i].second, first[i].first};
        auto func = [&orig, &inv](const std::pair<int, int>& p)
        {
            return p == orig || p == inv;
        };

        if (!std::any_of(second.begin(), second.end(), func))
        {
            return false;
        }
    }

    return true;
};

BOOST_AUTO_TEST_CASE(test_fte_empty_data)
{
    std::vector<int> data;
    int value = 10;
    std::vector<std::pair<int, int>> expected;

    BOOST_CHECK(areAllPairsEqual(expected, FindTwoElementsNaive(data, value)));
    BOOST_CHECK(areAllPairsEqual(expected, FindTwoElementsBS(data, value)));
    BOOST_CHECK(areAllPairsEqual(expected, FindTwoElementsHash(data, value)));
}

BOOST_AUTO_TEST_CASE(test_fte_one_pair)
{
    std::vector<int> data = {99, -1, 0, 8, 3, 4, 15, 100};
    int value = 11;
    std::vector<std::pair<int, int>> expected;
    expected.push_back({8, 3});

    BOOST_CHECK(areAllPairsEqual(expected, FindTwoElementsNaive(data, value)));
    BOOST_CHECK(areAllPairsEqual(expected, FindTwoElementsBS(data, value)));
    BOOST_CHECK(areAllPairsEqual(expected, FindTwoElementsHash(data, value)));
}

BOOST_AUTO_TEST_CASE(test_fte_several_pairs)
{
    std::vector<int> data = {99, -1, 7, 0, 8, 3, 4, 15, 6, 17, 100, 1, 9, 16};
    int value = 16;
    std::vector<std::pair<int, int>> expected;
    expected.push_back({1, 15});
    expected.push_back({-1, 17});
    expected.push_back({7, 9});
    expected.push_back({0, 16});

    BOOST_CHECK(areAllPairsEqual(expected, FindTwoElementsNaive(data, value)));
    BOOST_CHECK(areAllPairsEqual(expected, FindTwoElementsBS(data, value)));
    BOOST_CHECK(areAllPairsEqual(expected, FindTwoElementsHash(data, value)));
}

BOOST_AUTO_TEST_CASE(test_fte_no_pairs)
{
    std::vector<int> data = {99, -1, 7, 0, 8, 3, 4, 15, 6, 17, 100, 1, 9, 16};
    int value = 1123;
    std::vector<std::pair<int, int>> expected;

    BOOST_CHECK(areAllPairsEqual(expected, FindTwoElementsNaive(data, value)));
    BOOST_CHECK(areAllPairsEqual(expected, FindTwoElementsBS(data, value)));
    BOOST_CHECK(areAllPairsEqual(expected, FindTwoElementsHash(data, value)));
}

#endif /* TEST_FIND_TWO_ELEMENTS_HPP_ */
