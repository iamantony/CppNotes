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

namespace RDIA {

class Solution {
public:
    size_t removeDuplicates(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        size_t size = nums.size();
        size_t currentPos = 0;
        while(currentPos < size) {
            const int valueToSearch = nums[currentPos];

            size_t nextElemPos = currentPos + 1;
            while ( nextElemPos < size &&
                    nums[nextElemPos] == valueToSearch) {
                ++nextElemPos;
            }

            if (nextElemPos >= size) {
                break;
            }

            for (size_t toInd = currentPos + 1, fromInd = nextElemPos;
                 toInd < nextElemPos; ++ toInd, ++fromInd) {
                nums[toInd] = nums[fromInd];
                --size;
            }

            ++currentPos;
        }

        return size;
    }
};

}

#endif // REMOVE_DUPLICATES_IN_ARRAY_HPP
