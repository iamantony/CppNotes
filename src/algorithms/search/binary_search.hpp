#ifndef BINARYSEARCH_HPP_
#define BINARYSEARCH_HPP_

// http://www.geeksforgeeks.org/binary-search/
// Search a sorted array by repeatedly dividing the search interval in half.
// Begin with an interval covering the whole array. If the value of the search
// key is less than the item in the middle of the interval, narrow the interval
// to the lower half. Otherwise narrow it to the upper half. Repeatedly check
// until the value is found or the interval is empty.

// Time Complexity : O(Log n)
// Auxiliary Space : iterative implementation - O(1), recursive
// implementation - O(Log n) - space for recursion call stack

#include <limits>

namespace Algo::Search {
class BinarySearch {
public:
    template<typename C, typename V>
    static bool Search(const C& container,
                       const size_t& size,
                       const V& value,
                       size_t& resultIndex) {
        if (size == 0) { return false; }
        return SearchImpl(container, 0, size - 1, value, resultIndex);
    }

    template<typename C, typename V>
    static bool SearchImpl(const C& container,
                           const size_t& start,
                           const size_t& end,
                           const V& value,
                           size_t& resultIndex)
    {
        if (end < start) {
            return false;
        }
        else if (end == start) {
            if (container[start] == value) {
                resultIndex = start;
                return true;
            }

            return false;
        }

        size_t middle = (start + end) / 2;
        if (container[middle] < value) {
            size_t newStart = std::min(end, middle + 1);
            return SearchImpl(
                        container, newStart, end, value, resultIndex);
        }
        else if (value < container[middle]) {
            size_t newEnd = middle == 0 ? middle : middle - 1;
            return SearchImpl(
                        container, start, newEnd, value, resultIndex);
        }

        resultIndex = middle;
        return true;
    }
};
}

#endif /* BINARYSEARCH_HPP_ */
