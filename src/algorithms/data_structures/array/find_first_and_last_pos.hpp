#ifndef FIND_FIRST_AND_LAST_POS_HPP
#define FIND_FIRST_AND_LAST_POS_HPP

/*
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
Given an array of integers nums sorted in ascending order, find the starting
and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/

#include <vector>

namespace Algo::DS::Array {

class FindFirstAndLastPos {
public:
    static std::vector<int> Find(
            const std::vector<int>& nums, const int& target) {
        std::vector<int> result = {-1, -1};
        if (nums.empty()) {
            return result;
        }

        FindImpl(nums, 0, nums.size() - 1, target, result);
        return result;
    }

private:
    static void FindImpl(const std::vector<int>& nums,
                         const size_t& start,
                         const size_t& end,
                         const int& target,
                         std::vector<int>& indexes) {
        if (start > end) {
            return;
        }

        size_t mid = start + (end - start) / 2;
        if (nums[mid] == target) {
            UpdateIndexes(mid, indexes);
            FindImpl(nums, mid + 1, end, target, indexes);
            if (mid > 0) {
                FindImpl(nums, start, mid - 1, target, indexes);
            }
        }
        else if (nums[mid] < target) {
            FindImpl(nums, mid + 1, end, target, indexes);
        }
        else if (mid > 0) {
            FindImpl(nums, start, mid - 1, target, indexes);
        }
    }

    static void UpdateIndexes(const size_t& targetIndex,
                              std::vector<int>& indexes) {
        const size_t LOW = 0, HIGH = 1;
        int indx = static_cast<int>(targetIndex);
        if (indexes[LOW] == indexes[HIGH] && indexes[LOW] == -1) {
            indexes[LOW] = indexes[HIGH] = indx;
        }
        else if (indexes[HIGH] < indx) {
            indexes[HIGH] = indx;
        }
        else if (indexes[LOW] > indx) {
            indexes[LOW] = indx;
        }
    }
};

}

#endif // FIND_FIRST_AND_LAST_POS_HPP
