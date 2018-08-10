#ifndef REMOVE_DUPLICATES_IN_ARRAY_HPP
#define REMOVE_DUPLICATES_IN_ARRAY_HPP

// https://leetcode.com/problems/remove-duplicates-from-sorted-array

// Given a sorted array, remove the duplicates in-place such that each element
// appear only once and return the new length.
// Do not allocate extra space for another array, you must do this by modifying
// the input array in-place with O(1) extra memory.

// Example:
// Given nums = [1,1,2],
// Your function should return length = 2, with the first two elements of nums
// being 1 and 2 respectively.
// It doesn't matter what you leave beyond the new length.

#include <vector>

namespace Algo::DS::Array {

class RemoveDuplicates {
public:
    static size_t removeDuplicates(std::vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.size();
        }

        size_t writeTo = 0;
        for (size_t i = 0; i < nums.size(); ) {
            size_t j = i + 1;
            while (j < nums.size() && nums[i] == nums[j]) {
                ++j;
            }

            nums[writeTo] = nums[i];
            ++writeTo;
            i = j;
        }

        return writeTo;
    }
};

}

#endif // REMOVE_DUPLICATES_IN_ARRAY_HPP
