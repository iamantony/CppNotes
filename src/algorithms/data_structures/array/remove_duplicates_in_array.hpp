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
        if (nums.size() < 2) {
            return nums.size();
        }

        int size = static_cast<int>(nums.size());
        // Use raw pointer to array data to avoid compiler errors
        int* dataPtr = nums.data();

        int currentPos = 0;
        while(currentPos < size) {
            // Find position of next different element
            int diffElemPos = currentPos + 1;
            while ( diffElemPos < size &&
                    dataPtr[diffElemPos] == dataPtr[currentPos]) {
                ++diffElemPos;
            }

            // If next different element is on the next position, just move
            // to it
            if (diffElemPos - currentPos <= 1) {
                currentPos += 1;
                continue;
            }

            // Eliminate duplicate elements by moving tail elements to next
            // position of currentPos
            for (int toInd = currentPos + 1, fromInd = diffElemPos;
                 fromInd < size; ++toInd, ++fromInd) {
                dataPtr[toInd] = dataPtr[fromInd];
            }

            size = size - (diffElemPos - currentPos - 1);
            ++currentPos;
        }

        return static_cast<size_t>(size);
    }
};

}

#endif // REMOVE_DUPLICATES_IN_ARRAY_HPP
