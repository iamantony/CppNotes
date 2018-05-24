#ifndef JUMP_SEARCH_HPP
#define JUMP_SEARCH_HPP

// http://www.geeksforgeeks.org/jump-search/
// Like Binary Search, Jump Search is a searching algorithm for sorted arrays.
// The basic idea is to check fewer elements (than linear search) by jumping
// ahead by fixed steps or skipping some elements in place of searching all
// elements.

// What is the optimal block size to be skipped?
// In the worst case, we have to do n/m jumps and if the last checked value
// is greater than the element to be searched for, we perform m-1 comparisons
// more for linear search. Therefore the total number of comparisons in the
// worst case will be ((n/m) + m-1). The value of the function ((n/m) + m-1)
// will be minimum when m = √n. Therefore, the best step size is m = √n.

// Time Complexity : O(√n)
// Auxiliary Space : O(1)

#include <algorithm>

#include "algorithms/search/binary_search.hpp"

namespace JumpSearch {

class Solution {
public:
    template<typename C, typename V>
    bool Search(const C& container,
                const size_t& size,
                const V& value,
                size_t& resultIndex) {
        if (size <= 0) {
            return false;
        }

        size_t interval = static_cast<size_t>(std::sqrt(size));
        for(size_t i = 0; i < size; i += interval) {
            if (container[i] == value) {
                resultIndex = i;
                return true;
            }
            else if (value < container[i]) {
                size_t start = i <= interval ? 0 : i - interval + 1;
                size_t end = i <= interval ? 0 : i - 1;

                BinarySearch::Solution solution;
                return solution.BinarySearchImpl(
                            container, start, end, value, resultIndex);
            }
            else if (i + interval >= size) {
                size_t start = std::min(i + 1, size - 1);

                BinarySearch::Solution solution;
                return solution.BinarySearchImpl(
                            container, start, size - 1, value, resultIndex);
            }
        }

        return false;
    }
};

}

#endif // JUMP_SEARCH_HPP

