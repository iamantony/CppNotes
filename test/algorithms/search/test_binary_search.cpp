#include <boost/test/unit_test.hpp>
#include <vector>
#include "algorithms/search/binary_search.hpp"
#include "testcases_for_search_algorithms.hpp"

BOOST_AUTO_TEST_SUITE(TestBinarySearch)

using namespace TCFSearchingAlgo;

BOOST_AUTO_TEST_CASE(container_one_elem) {
    std::vector<int> container;
    int value;
    bool expectedIsFound;
    OneElement(container, value, expectedIsFound);

    size_t result = 0;
    bool isFound = Algo::Search::BinarySearch::Search(
                container, container.size(), value, result);
    BOOST_CHECK(expectedIsFound == isFound);
}

BOOST_AUTO_TEST_CASE(val_in_middle) {
    std::vector<int> container;
    int value;
    bool expectedIsFound;
    size_t expectedResultIndex;
    ValueInMiddle(container, value, expectedIsFound, expectedResultIndex);

    size_t result = 0;
    bool isFound = Algo::Search::BinarySearch::Search(
                container, container.size(), value, result);
    BOOST_CHECK(expectedIsFound == isFound);
    BOOST_CHECK(expectedResultIndex == result);
}

BOOST_AUTO_TEST_CASE(val_in_start) {
    std::vector<int> container;
    int value;
    bool expectedIsFound;
    size_t expectedResultIndex;
    ValueAtStart(container, value, expectedIsFound, expectedResultIndex);

    size_t result = 0;
    bool isFound = Algo::Search::BinarySearch::Search(
                container, container.size(), value, result);
    BOOST_CHECK(expectedIsFound == isFound);
    BOOST_CHECK(expectedResultIndex == result);
}

BOOST_AUTO_TEST_CASE(val_in_end) {
    std::vector<int> container;
    int value;
    bool expectedIsFound;
    size_t expectedResultIndex;
    ValueAtEnd(container, value, expectedIsFound, expectedResultIndex);

    size_t result = 0;
    bool isFound = Algo::Search::BinarySearch::Search(
                container, container.size(), value, result);
    BOOST_CHECK(expectedIsFound == isFound);
    BOOST_CHECK(expectedResultIndex == result);
}

BOOST_AUTO_TEST_CASE(no_val) {
    std::vector<int> container;
    int value;
    bool expectedIsFound;
    NoValueInContainer(container, value, expectedIsFound);

    size_t result = 0;
    bool isFound = Algo::Search::BinarySearch::Search(
                container, container.size(), value, result);
    BOOST_CHECK(expectedIsFound == isFound);
}

BOOST_AUTO_TEST_CASE(val_is_less_than_min) {
    std::vector<int> container;
    int value;
    bool expectedIsFound;
    ValueIsLessThanMinValueInContainer(container, value, expectedIsFound);

    size_t result = 0;
    bool isFound = Algo::Search::BinarySearch::Search(
                container, container.size(), value, result);
    BOOST_CHECK(expectedIsFound == isFound);
}

BOOST_AUTO_TEST_CASE(several_same_val) {
    std::vector<int> container;
    int value;
    bool expectedIsFound;
    std::vector<size_t> expectedResultIndexes;
    SeveralSameValuesInContainer(container, value, expectedIsFound,
                                        expectedResultIndexes);

    size_t result = 0;
    bool isFound = Algo::Search::BinarySearch::Search(
                container, container.size(), value, result);
    BOOST_CHECK(expectedIsFound == isFound);

    auto iter = std::find(expectedResultIndexes.begin(),
                          expectedResultIndexes.end(), result);
    BOOST_CHECK(iter != expectedResultIndexes.end());
}

BOOST_AUTO_TEST_CASE(random_values) {
    std::vector<int> container;
    int value;
    bool expectedIsFound;
    std::vector<size_t> expectedResultIndexes;

    for (size_t i = 0; i < 10; ++i) {
        RandomContainer(container, value, expectedIsFound,
                        expectedResultIndexes, 1000);

        size_t result = 0;
        bool isFound = Algo::Search::BinarySearch::Search(
                    container, container.size(), value, result);

        BOOST_CHECK(expectedIsFound == isFound);

        if (isFound) {
            auto iter = std::find(expectedResultIndexes.begin(),
                                  expectedResultIndexes.end(), result);
            BOOST_CHECK(iter != expectedResultIndexes.end());
        }
    }
}

BOOST_AUTO_TEST_SUITE_END()
