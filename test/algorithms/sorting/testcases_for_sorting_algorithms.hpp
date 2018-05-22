#ifndef TESTCASES_FOR_SORTING_ALGORITHMS_HPP
#define TESTCASES_FOR_SORTING_ALGORITHMS_HPP

#include <vector>
#include <limits>
#include <random>

namespace TCFSortingAlgo {

template <typename T>
void EmptyContainer(std::vector<T>& container, std::vector<T>& expected) {
    container = std::vector<T>();
    expected = container;
    std::sort(expected.begin(), expected.end());
}

template <typename T>
void ContainerWithOneValue(std::vector<T>& container,
                           std::vector<T>& expected) {
    container = std::vector<T>({42});
    expected = container;
    std::sort(expected.begin(), expected.end());
}

template <typename T>
void SortedContainer(std::vector<T>& container, std::vector<T>& expected) {
    container = std::vector<T>({0, 42, 43, 100});
    expected = container;
    std::sort(expected.begin(), expected.end());
}

template <typename T>
void ContainerWithMinAndMaxValues(std::vector<T>& container,
                                  std::vector<T>& expected) {
    container = std::vector<T>({42, 10, 1,
            std::numeric_limits<T>::min(), std::numeric_limits<T>::max()});

    expected = container;
    std::sort(expected.begin(), expected.end());
}

template <typename T>
void ContainerWithPositiveAndNegativeValues(std::vector<T>& container,
                                            std::vector<T>& expected) {
    container = std::vector<T>({42, -10, 1, 0, -1000, 11});
    expected = container;
    std::sort(expected.begin(), expected.end());
}

template <typename T>
void ContainerWithDuplicates(std::vector<T>& container,
                             std::vector<T>& expected) {
    container = std::vector<T>({42, 1, 1, 10, 43, 10});
    expected = container;
    std::sort(expected.begin(), expected.end());
}

template <typename T>
void RandomContainer(std::vector<T>& container, std::vector<T>& expected,
                     const size_t& maxSize = 1000000)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<size_t> sizeDist(0, maxSize);
    std::uniform_int_distribution<T> dist(std::numeric_limits<T>::min(),
                                         std::numeric_limits<T>::max());

    container.resize(sizeDist(gen));
    for (size_t i = 0; i < container.size(); ++i) {
        container[i] = dist(gen);
    }

    expected = container;
    std::sort(expected.begin(), expected.end());
}

}

#endif // TESTCASES_FOR_SORTING_ALGORITHMS_HPP

