#ifndef TEST_FIND_TWO_ELEMENTS_HPP_
#define TEST_FIND_TWO_ELEMENTS_HPP_

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

    BOOST_CHECK(areAllPairsEqual(
                    expected, Algo::Search::FindTwoElementsNaive(data, value)));

    BOOST_CHECK(areAllPairsEqual(
                    expected, Algo::Search::FindTwoElementsBS(data, value)));

    BOOST_CHECK(areAllPairsEqual(
                    expected, Algo::Search::FindTwoElementsHash(data, value)));
    {
        std::vector<int> expectedIndexes;
        BOOST_CHECK(expectedIndexes ==
                    Algo::Search::TwoSum::SearchOrdered(data, value));
    }
}

BOOST_AUTO_TEST_CASE(test_fte_one_pair)
{
    std::vector<int> data = {99, -1, 0, 8, 3, 4, 15, 100};
    const int value = 11;
    const std::vector<std::pair<int, int>> expected({ {8, 3} });

    BOOST_CHECK(areAllPairsEqual(
                    expected, Algo::Search::FindTwoElementsNaive(data, value)));

    BOOST_CHECK(areAllPairsEqual(
                    expected, Algo::Search::FindTwoElementsBS(data, value)));

    BOOST_CHECK(areAllPairsEqual(
                    expected, Algo::Search::FindTwoElementsHash(data, value)));

    {
        std::sort(data.begin(), data.end());
        std::vector<int> expectedIndexes({2, 4});
        BOOST_CHECK(expectedIndexes ==
                    Algo::Search::TwoSum::SearchOrdered(data, value));
    }
}

BOOST_AUTO_TEST_CASE(test_fte_several_pairs)
{
    std::vector<int> data = {99, -1, 7, 0, 8, 3, 4, 15, 6, 17, 100, 1, 9, 16};
    int value = 16;
    std::vector<std::pair<int, int>> expected(
        { {1, 15}, {-1, 17}, {7, 9}, {0, 16} });

    BOOST_CHECK(areAllPairsEqual(
                    expected, Algo::Search::FindTwoElementsNaive(data, value)));

    BOOST_CHECK(areAllPairsEqual(
                    expected, Algo::Search::FindTwoElementsBS(data, value)));

    BOOST_CHECK(areAllPairsEqual(
                    expected, Algo::Search::FindTwoElementsHash(data, value)));

    {
        std::sort(data.begin(), data.end());
        std::vector<int> expectedIndexes({0, 11});
        BOOST_CHECK(expectedIndexes ==
                    Algo::Search::TwoSum::SearchOrdered(data, value));
    }
}

BOOST_AUTO_TEST_CASE(test_fte_no_pairs)
{
    std::vector<int> data = {99, -1, 7, 0, 8, 3, 4, 15, 6, 17, 100, 1, 9, 16};
    int value = 1123;
    std::vector<std::pair<int, int>> expected;

    BOOST_CHECK(areAllPairsEqual(
                    expected, Algo::Search::FindTwoElementsNaive(data, value)));

    BOOST_CHECK(areAllPairsEqual(
                    expected, Algo::Search::FindTwoElementsBS(data, value)));

    BOOST_CHECK(areAllPairsEqual(
                    expected, Algo::Search::FindTwoElementsHash(data, value)));

    {
        std::sort(data.begin(), data.end());
        std::vector<int> expectedIndexes;
        BOOST_CHECK(expectedIndexes ==
                    Algo::Search::TwoSum::SearchOrdered(data, value));
    }
}

#endif /* TEST_FIND_TWO_ELEMENTS_HPP_ */
