#ifndef SEARCH_INSERT_POSITION_HPP
#define SEARCH_INSERT_POSITION_HPP

/*
https://leetcode.com/problems/search-insert-position/description/
Given a sorted array and a target value, return the index if the target is
found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:
Input: [1,3,5,6], 5
Output: 2

Example 2:
Input: [1,3,5,6], 2
Output: 1

Example 3:
Input: [1,3,5,6], 7
Output: 4

Example 4:
Input: [1,3,5,6], 0
Output: 0
*/

#include <vector>

namespace Algo::DS::Array {

class SearchInsertPos {
public:
    static size_t Search(const std::vector<int>& nums, const int& target) {
        if (nums.empty()) {
            return 0;
        }

        size_t left = 0, right = nums.size() - 1;
        while (left <= right) {
            size_t middle = left + (right - left) / 2;
            if (nums[middle] >= target) {
                if (middle == 0) {
                    return middle;
                }

                right = middle - 1;
            }
            else {
                left = middle + 1;
            }
        }

        return left;
    }
};

}

#endif // SEARCH_INSERT_POSITION_HPP
