#ifndef SEARCH_IN_ROTATED_SORTED_ARRAY_HPP
#define SEARCH_IN_ROTATED_SORTED_ARRAY_HPP

/*
https://leetcode.com/problems/search-in-rotated-sorted-array/description/
Suppose an array sorted in ascending order is rotated at some pivot unknown to
you beforehand. (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index,
otherwise return -1.

You may assume no duplicate exists in the array.
Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/

#include <vector>

namespace Algo::Search {

class SearchInRotatedArray {
public:
    static bool Search(const std::vector<int>& v, const int& target,
                       size_t& position) {
        if (v.empty()) {
            return false;
        }

        return SearchImpl(v, 0, v.size() - 1, target, position);
    }

private:
    static bool SearchImpl(const std::vector<int>& v, const size_t& start,
                           const size_t& end, const int& target,
                           size_t& position) {
        if (start > end) {
            return false;
        }

        size_t mid = start + (end - start) / 2;
        if (v[mid] == target) {
            position = mid;
            return true;
        }
        // Check if right part is sorted
        else if (v[mid] < v[end]) {
            // Check if target value in right part
            if (target > v[mid] && target <= v[end]) {
                return SearchImpl(v, mid + 1, end, target, position);
            }
            // Otherwise search in left part
            else if (mid > 0) {
                return SearchImpl(v, start, mid - 1, target, position);
            }
        }
        // If right part is not sorted, then left part must be sorted. Check
        // that target value located in left part
        else if (target >= v[start] && target < v[mid] && mid > 0) {
            return SearchImpl(v, start, mid - 1, target, position);
        }

        return SearchImpl(v, mid + 1, end, target, position);
    }
};

}

#endif // SEARCH_IN_ROTATED_SORTED_ARRAY_HPP
