#ifndef QUICKSORT_HPP_
#define QUICKSORT_HPP_

// Quick Sort Algorithm
// Efficient, general-purpose, comparison-based sorting algorithm.
// https://en.wikipedia.org/wiki/Quicksort
// Best case performance: O(n log n) typical, O(n) natural variant
// Worst case performance: O(n^2)
// Worst Case Auxiliary Space Complexity: О(n)

#include <limits>

namespace QS {

template<typename T>
class Solution {
public:
    static void QuickSort(T& container) {
        if (container.size() < 2) {
            return;
        }

        Sort(container, 0, container.size() - 1);
    }
private:
    static void Sort(T& container, const size_t& start, const size_t& end) {
        if(start >= end) {
            return;
        }

        // As pivot element choose middle element
        size_t pivotIndex = start + (end - start)/ 2;
        auto pivotValue = container[pivotIndex];

        size_t left = start, right = end;
        do {
            // Find element on the LEFT part of the container that is
            // GREATER OR EQUAL than pivot element
            while(container[left] < pivotValue) {
                ++left;
            }

            // Find element on the RIGHT part of the container that is
            // LESS OR EQUAL than pivot element
            while(pivotValue < container[right]) {
                --right;
            }

            if (left <= right) {
                // Swap such elements so they will be in right parts of the
                // container
                std::swap(container[left], container[right]);
                if (left < std::numeric_limits<size_t>::max()) {
                    ++left;
                }

                if (std::numeric_limits<size_t>::min() < right) {
                    --right;
                }
            }
        }
        while(left <= right);

        Sort(container, start, right);
        Sort(container, left, end);
    }
};

}

#endif /* QUICKSORT_HPP_ */
