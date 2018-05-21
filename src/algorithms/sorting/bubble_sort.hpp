#ifndef BUBBLESORT_HPP_
#define BUBBLESORT_HPP_

#include <algorithm>

// Bubble Sort Algorithm
// Simple and slow algorithm
// http://en.wikipedia.org/wiki/Bubble_sort

namespace BS {

class Solution {
public:

    // Basic algorithm
    // Best case performance: O(n^2)
    // Worst case performance: O(n^2)
    // Worst Case Auxiliary Space Complexity: O(1)
    // @input:
    // - container - object of container type with sortable items
    template<typename T>
    static void BubbleSort(T& container) {
        // Why we need to check container emptyness:
        // container.size() = size_t
        // size_t - long unsigned int
        // if size == 0 -> 0 - 1 = max(long unsigned int)
        if (container.empty()) {
            return;
        }

        for (size_t i = 0; i < container.size() - 1; ++i) {
            for(size_t j = 0; j < container.size() - i - 1; ++j) {
                if (container[j + 1] < container[j]) {
                    std::swap(container[j + 1], container[j]);

                    // swap:
                    // int temp = container[j + 1];
                    // container[j] = container[j + 1];
                    // container[j + 1] = temp;
                }
            }
        }
    }

    // Optimised basic algorithm
    // Best case performance: O(n)
    // Worst case performance: O(n^2)
    // Worst Case Auxiliary Space Complexity: O(1)
    // @input:
    // - container - object of container type with sortable items
    template<typename T>
    static void BubbleSortOptimised(T& container) {
        if (container.empty()) {
            return;
        }

        for (size_t i = 0; i < container.size() - 1; ++i) {
            bool swapUsed = false;
            for(size_t j = 0; j < container.size() - i - 1; ++j) {
                if (container[j + 1] < container[j]) {
                    std::swap(container[j + 1], container[j]);
                    swapUsed = true;
                }
            }

            // If we did not swap elements in container, it means that
            // all elements are sorted and we can exit
            if (!swapUsed) {
                return;
            }
        }
    }

    // Recursive algorithm
    // Best case performance: O(n)
    // Worst case performance: O(n^2)
    // Worst Case Auxiliary Space Complexity: O(1)
    // @input:
    // - container - object of container type with sortable items
    template<typename T>
    static void BubbleSortRecursive(T& container) {
        BSRImpl(container, container.size());
    }

private:
    template<typename T>
    static void BSRImpl(T& container, const size_t size) {
        if (size <= 0) {
            return;
        }

        bool swapUsed = false;
        for(size_t j = 0; j < size - 1; ++j) {
            if (container[j + 1] < container[j]) {
                std::swap(container[j + 1], container[j]);
                swapUsed = true;
            }
        }

        if (!swapUsed) {
            return;
        }

        BSRImpl(container, size - 1);
    }
};

}

#endif /* BUBBLESORT_HPP_ */
