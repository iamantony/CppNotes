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

namespace Algo { namespace DS { namespace Array {

class RemoveDuplicates {
public:
    static size_t removeDuplicates(std::vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.size();
        }

        size_t size = nums.size();
        size_t currentPos = 0;
        while(currentPos < size) {
            // Find position of next different element
            size_t diffElemPos = currentPos + 1;
            while(diffElemPos < size &&
                    nums[diffElemPos] == nums[currentPos]) {
                ++diffElemPos;
            }

            // If next different element is on the next position, we will
            // not need any copy operations, we can just move next position
            if (diffElemPos - currentPos <= 1) {
                ++currentPos;
                continue;
            }

            // Eliminate duplicate elements by moving tail elements to next
            // position of currentPos
            for (size_t toInd = currentPos + 1, fromInd = diffElemPos;
                    fromInd < size;
                    ++toInd, ++fromInd) {
                nums[toInd] = nums[fromInd];
            }

            size = size - (diffElemPos - currentPos - 1);
            ++currentPos;
        }

        return size;
    }
};

} } }

#endif // REMOVE_DUPLICATES_IN_ARRAY_HPP
