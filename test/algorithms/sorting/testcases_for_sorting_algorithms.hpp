#ifndef TESTCASES_FOR_SORTING_ALGORITHMS_HPP
#define TESTCASES_FOR_SORTING_ALGORITHMS_HPP

#include <vector>
#include <limits>
#include <random>

namespace TCFSortingAlgo {

std::vector<int> EmptyContainer() {
    return std::vector<int>();
}

std::vector<int> ContainerWithOneValue() {
    return std::vector<int>({42});
}

std::vector<int> SortedContainer() {
    return std::vector<int>({0, 42, 43, 100});
}

std::vector<int> ContainerWithMinAndMaxValues() {
    return std::vector<int>({42, 10, 1,
            std::numeric_limits<int>::min(), std::numeric_limits<int>::max()});
}

std::vector<int> ContainerWithPositiveAndNegativeValues() {
    return std::vector<int>({42, -10, 1, 0, -1000, 11});
}

std::vector<int> ContainerWithDuplicates() {
    return std::vector<int>({42, 1, 1, 10, 43, 10});
}

std::vector<int> RandomContainer(const size_t& maxSize = 1000000) {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<size_t> sizeDist(0, maxSize);
    std::uniform_int_distribution<int> dist(std::numeric_limits<int>::min(),
                                         std::numeric_limits<int>::max());

    std::vector<int> container(sizeDist(gen));
    for (size_t i = 0; i < container.size(); ++i) {
        container[i] = dist(gen);
    }

    return container;
}

}

#endif // TESTCASES_FOR_SORTING_ALGORITHMS_HPP

