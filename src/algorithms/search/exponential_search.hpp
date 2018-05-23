#ifndef EXPONENTIAL_SEARCH_HPP
#define EXPONENTIAL_SEARCH_HPP

// http://www.geeksforgeeks.org/exponential-search/
// Exponential search involves two steps:
// 1. Find range where element is present
// 2. Do Binary Search in above found range.

// How to find the range where element may be present?
// The idea is to start with subarray size 1 compare its last element with x,
// then try size 2, then 4 and so on until last element of a subarray is not
// greater.
// Once we find an index i (after repeated doubling of i), we know that the
// element must be present between i/2 and i (Why i/2? because we could not
// find a greater value in previous iteration)

// Time Complexity : O(Log n)
// Auxiliary Space : with recursive BinarySearch - O(Log n), with iterative
// BinarySearch - O(1)

#include <algorithm>
#include "algorithms/search/binary_search.hpp"

namespace ExponentialSearch {

class Solution {
public:
    template<typename C, typename V>
    bool Search(const C& container,
                const size_t& size,
                const V& value,
                size_t& resultIndex)
    {
        if (size <= 0) {
            return false;
        }

        size_t rangeStart = 0, rangeEnd = 0;
        while (rangeEnd < size) {
            if (value == container[rangeEnd]) {
                resultIndex = rangeEnd;
                return true;
            }
            else if (value < container[rangeEnd]) {
                break;
            }

            rangeStart = rangeEnd + 1;

            // rangeEnd = 2 ^ power - 1
            rangeEnd = ((rangeEnd + 1) << 1) - 1;
        }

        BinarySearch::Solution solution;
        return solution.BinarySearchImpl(container,
                                         std::min(rangeStart, size - 1),
                                         std::min(rangeEnd, size - 1),
                                         value,
                                         resultIndex);
    }
};

}

#endif // EXPONENTIAL_SEARCH_HPP

