#ifndef FIND_SINGLE_ITEM_IN_SORTED_ARRAY_HPP
#define FIND_SINGLE_ITEM_IN_SORTED_ARRAY_HPP

// https://leetcode.com/problems/single-element-in-a-sorted-array/description/
// Given a sorted array consisting of only integers where every element appears
// twice except for one element which appears once. Find this single element
// that appears only once.

// Example 1:
// Input: [1,1,2,3,3,4,4,8,8]
// Output: 2

// Example 2:
// Input: [3,3,7,7,10,11,11]
// Output: 10

//Note: Your solution should run in O(log n) time and O(1) space.

#include <vector>

namespace Algo::Search {

template <typename T>
class FindSingleItemInSortedArr {
public:

    // TC: O(lg n)
    // Use Binary Search.
    // All elements before the required have first occurrence at even
    // index (0, 2, ..) and next occurrence at odd index (1, 3, …).
    // And all elements after the required element have first occurrence
    // at odd index and next occurrence at even index.
    static T FindBS(const std::vector<T>& v) {
        if (v.empty()) {
            return T();
        }

        if (v.size() == 1) {
            return v[0];
        }

        size_t low = 0, high = v.size() - 1;
        while (low < high) {
            size_t mid = low + (high - low) / 2;
            if (mid % 2 == 0) {
                if (v[mid] == v[mid + 1]) {
                    low = mid + 2;
                }
                else {
                    high = mid;
                }
            }
            else {
                if (v[mid] == v[mid - 1]) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }

        if (low == high) {
            return v[low];
        }

        return T();
    }

    // TC: O(n)
    static T FindLinear(const std::vector<T>& v) {
        if (v.empty()) {
            return T();
        }

        if (v.size() == 1) {
            return v[0];
        }

        // Size of the array should be odd, because it contains 2 * k + 1
        // elements, where k - number of elements that appears twice
        if (v.size() % 2 == 0) {
            return T();
        }

        for (size_t i = 0; i < v.size() - 2; i += 2) {
            if (v[i] != v[i + 1]) {
                return v[i];
            }
        }

        return v[v.size() - 1];
    }
};

}

#endif // FIND_SINGLE_ITEM_IN_SORTED_ARRAY_HPP
