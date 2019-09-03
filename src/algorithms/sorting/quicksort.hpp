#ifndef QUICKSORT_HPP_
#define QUICKSORT_HPP_

// Quick Sort Algorithm
// Efficient general-purpose in-place comparison-based sorting algorithm.
// https://en.wikipedia.org/wiki/Quicksort
// Best case performance: O(n log n) typical, O(n) natural variant
// Worst case performance: O(n^2)
// Worst Space Complexity: О(n)

#include <limits>

namespace Algo::Sorting {
template<typename T>
class QuickSort {
public:
    enum class Type {
        BASIC,
        THREE_WAY
    };

    static void Sort(T& container, const Type type) {
        if (container.size() < 2) {
            return;
        }

        switch(type)
        {
            case Type::THREE_WAY:
                Sort3Way(container, 0, container.size() - 1);
                break;

            case Type::BASIC:
            default:
                SortBasic(container, 0, container.size() - 1);
                break;
        }
    }

private:
    static void SortBasic(T& container, const size_t& start, const size_t& end) {
        if(start >= end) {
            return;
        }

        size_t pivotFinalIndex = Partition(container, start, end);
        if (pivotFinalIndex > 0) {
            SortBasic(container, start, pivotFinalIndex - 1);
        }

        SortBasic(container, pivotFinalIndex + 1, end);
    }

    static size_t Partition(T& container,
                            const size_t& start, const size_t& end) {
        // Choose pivot element as middle element of container. Swap it
        // with the first element.
        size_t pivotIndex = start + (end - start)/ 2;
        std::swap(container[pivotIndex], container[start]);

        auto pivotValue = container[start];

        // Let's iterate over container and compare elements with pivot.
        // Our goal - is to rearrange elements in container so they would
        // form two parts: first (left) part will contain only elements that
        // are less than pivot; second (right) part will contain all other
        // elements.
        // We could start iteration with element that stands after pivot.
        // We will use two indexes:
        // 'left' - end of the partition with elements less than pivot
        // 'i' - iterator over container elements
        size_t left = start + 1;
        for(size_t i = start + 1; i <= end; ++i)
        {
            // All elements that are less than pivot put to the left partition
            if (container[i] < pivotValue) {
                std::swap(container[i], container[left]);
                ++left;
            }
        }

        // Put pivot element to its final position - last element of partition
        // that contains only elements that are less than pivot
        std::swap(container[start], container[left - 1]);

        // Return final position of pivot element
        return left - 1;
    }

    static void Sort3Way(T& container, const size_t& start, const size_t& end) {
        if(start >= end) {
            return;
        }

        auto pivotStartEnd = Partition3Way(container, start, end);
        if (pivotStartEnd.first > 0) {
            Sort3Way(container, start, pivotStartEnd.first - 1);
        }

        Sort3Way(container, pivotStartEnd.second + 1, end);
    }

    static std::pair<size_t, size_t> Partition3Way(
            T& container, const size_t& start, const size_t& end) {
        const auto pivotIndex = Partition(container, start, end);
        const auto pivotValue = container[pivotIndex];
        size_t eq = pivotIndex + 1;
        for(size_t i = pivotIndex + 1; i <= end; ++i)
        {
            if (container[i] == pivotValue) {
                std::swap(container[i], container[eq]);
                ++eq;
            }
        }

        return {pivotIndex, eq - 1};
    }
};
}

#endif /* QUICKSORT_HPP_ */
