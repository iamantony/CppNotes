#ifndef TEST_JUMP_SEARCH_HPP
#define TEST_JUMP_SEARCH_HPP

#include <boost/test/unit_test.hpp>
#include <vector>

#include "algorithms/search/jump_search.hpp"
#include "./testcases_for_search_algorithms.hpp"

BOOST_AUTO_TEST_CASE(test_jumpsearch_container_one_elem)
{
    std::vector<int> container;
    int value;
    bool expectedIsFound;
    TCFSA::OneElement(container, value, expectedIsFound);

    size_t result = 0;
    JumpSearch::Solution solution;
    bool isFound = solution.Search(container, container.size(), value, result);
    BOOST_CHECK(expectedIsFound == isFound);
}

BOOST_AUTO_TEST_CASE(test_jumpsearch_val_in_middle)
{
    std::vector<int> container;
    int value;
    bool expectedIsFound;
    size_t expectedResultIndex;
    TCFSA::ValueInMiddle(container, value, expectedIsFound, expectedResultIndex);

    size_t result = 0;
    JumpSearch::Solution solution;
    bool isFound = solution.Search(container, container.size(), value, result);
    BOOST_CHECK(expectedIsFound == isFound);
    BOOST_CHECK(expectedResultIndex == result);
}

BOOST_AUTO_TEST_CASE(test_jumpsearch_val_in_start)
{
    std::vector<int> container;
    int value;
    bool expectedIsFound;
    size_t expectedResultIndex;
    TCFSA::ValueAtStart(container, value, expectedIsFound, expectedResultIndex);

    size_t result = 0;
    JumpSearch::Solution solution;
    bool isFound = solution.Search(container, container.size(), value, result);
    BOOST_CHECK(expectedIsFound == isFound);
    BOOST_CHECK(expectedResultIndex == result);
}

BOOST_AUTO_TEST_CASE(test_jumpsearch_val_in_end)
{
    std::vector<int> container;
    int value;
    bool expectedIsFound;
    size_t expectedResultIndex;
    TCFSA::ValueAtEnd(container, value, expectedIsFound, expectedResultIndex);

    size_t result = 0;
    JumpSearch::Solution solution;
    bool isFound = solution.Search(container, container.size(), value, result);
    BOOST_CHECK(expectedIsFound == isFound);
    BOOST_CHECK(expectedResultIndex == result);
}

BOOST_AUTO_TEST_CASE(test_jumpsearch_no_val)
{
    std::vector<int> container;
    int value;
    bool expectedIsFound;
    TCFSA::NoValueInContainer(container, value, expectedIsFound);

    size_t result = 0;
    JumpSearch::Solution solution;
    bool isFound = solution.Search(container, container.size(), value, result);
    BOOST_CHECK(expectedIsFound == isFound);
}

BOOST_AUTO_TEST_CASE(test_jumpsearch_several_same_val)
{
    std::vector<int> container;
    int value;
    bool expectedIsFound;
    std::vector<size_t> expectedResultIndexes;
    TCFSA::SeveralSameValuesInContainer(container, value, expectedIsFound,
                                        expectedResultIndexes);

    size_t result = 0;
    JumpSearch::Solution solution;
    bool isFound = solution.Search(container, container.size(), value, result);
    BOOST_CHECK(expectedIsFound == isFound);

    auto iter = std::find(expectedResultIndexes.begin(),
                          expectedResultIndexes.end(), result);
    BOOST_CHECK(iter != expectedResultIndexes.end());
}

BOOST_AUTO_TEST_CASE(test_jumpsearch_many_values)
{
    std::vector<int> container;
    int value;
    bool expectedIsFound;
    size_t expectedResultIndex;
    TCFSA::ContainerWithManyValues(container, value, expectedIsFound,
                              expectedResultIndex);

    size_t result = 0;
    JumpSearch::Solution solution;
    bool isFound = solution.Search(container, container.size(), value, result);
    BOOST_CHECK(expectedIsFound == isFound);
    BOOST_CHECK(expectedResultIndex == result);
}

#endif // TEST_JUMP_SEARCH_HPP

