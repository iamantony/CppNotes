#ifndef TESTCASES_FOR_SEARCH_ALGORITHMS_HPP
#define TESTCASES_FOR_SEARCH_ALGORITHMS_HPP

#include <vector>
#include <limits>
#include <random>

namespace TCFSearchingAlgo {

template <typename T>
void OneElement(std::vector<T>& container, T& value, bool& expectedIsFound) {
    container = std::vector<T>(1, 5);
    value = 0;
    expectedIsFound = false;
}

template <typename T>
void ValueInMiddle(std::vector<T>& container, T& value,
                   bool& expectedIsFound, size_t& expectedResultIndex) {
    container = {0, 42, 43, 100, 59};
    std::sort(container.begin(), container.end());

    value = 43;
    expectedIsFound = true;
    expectedResultIndex = 2;
}

template <typename T>
void ValueAtStart(std::vector<T>& container, T& value,
                  bool& expectedIsFound, size_t& expectedResultIndex) {
    container = {0, 42, 43, 100, 59};
    std::sort(container.begin(), container.end());

    value = *std::min_element(container.begin(), container.end());
    expectedIsFound = true;
    expectedResultIndex = 0;
}

template <typename T>
void ValueAtEnd(std::vector<T>& container, T& value,
                bool& expectedIsFound, size_t& expectedResultIndex) {
    container = {0, 42, 43, 100, 59};
    std::sort(container.begin(), container.end());

    value = *std::max_element(container.begin(), container.end());
    expectedIsFound = true;
    expectedResultIndex = 4;
}

template <typename T>
void NoValueInContainer(
        std::vector<T>& container, T& value, bool& expectedIsFound) {
    container = {0, 42, 43, 100, 59};
    std::sort(container.begin(), container.end());

    value = 15;
    expectedIsFound = false;
}

template <typename T>
void ValueIsLessThanMinValueInContainer(
        std::vector<T>& container, T& value, bool& expectedIsFound) {
    container = {10, 42, 43, 100, 59};
    std::sort(container.begin(), container.end());

    value = 5;
    expectedIsFound = false;
}

template <typename T>
void SeveralSameValuesInContainer(std::vector<T>& container, T& value,
            bool& expectedIsFound, std::vector<size_t>& expectedResultIndexes) {
    container = {0, 42, 43, 100, 59, 14, 43};
    std::sort(container.begin(), container.end());

    value = 43;
    expectedIsFound = true;
    expectedResultIndexes = {3, 4};
}

template <typename T>
void RandomContainer(std::vector<T>& container,
                     T& value,
                     bool& expectedIsFound,
                     std::vector<size_t>& expectedResultIndexes,
                     const size_t& maxSize = 1000000)
{
    // prepare objects for generation of random values
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<size_t> sizeDist(0, maxSize);
    std::uniform_int_distribution<T> dist(std::numeric_limits<T>::min(),
                                         std::numeric_limits<T>::max());

    // generate random values and push them to container
    container.resize(sizeDist(gen));
    for (size_t i = 0; i < container.size(); ++i) {
        container[i] = dist(gen);
    }

    // sort values in container because we expect that searching algorithms
    // works only with sorted sequences
    std::sort(container.begin(), container.end());

    // generate value that we would search in container
    value = dist(gen);

    // check if such value exist in container
    std::vector<T> searchValues = {value};
    auto firstIter = std::find_first_of(container.begin(), container.end(),
                                    searchValues.begin(), searchValues.end());
    if (firstIter != container.end()) {
        expectedIsFound = true;

        // find last iterator that point to 'value'
        auto lastIter = std::find_end(container.begin(), container.end(),
                                      searchValues.begin(), searchValues.end());

        // fill 'expectedResultIndexes' with valid positions of 'value'
        size_t firstPos = static_cast<size_t>(firstIter - container.begin());
        do {
            expectedResultIndexes.push_back(firstPos);
            ++firstIter;
        }
        while (firstIter != lastIter);
    }
    else {
        expectedIsFound = false;
    }
}

}

#endif // TESTCASES_FOR_SEARCH_ALGORITHMS_HPP

