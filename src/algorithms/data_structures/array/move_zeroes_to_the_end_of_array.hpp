#ifndef MOVE_ZEROS_TO_THE_END_OF_ARRAY_HPP
#define MOVE_ZEROS_TO_THE_END_OF_ARRAY_HPP

// https://leetcode.com/problems/move-zeroes/description/

// Given an array nums, write a function to move all 0's to the end of it while
// maintaining the relative order of the non-zero elements.

// For example, given nums = [0, 1, 0, 3, 12], after calling your function,
// nums should be [1, 3, 12, 0, 0].

// Note:
// - You must do this in-place without making a copy of the array.
// - Minimize the total number of operations.

#include <vector>
#include <algorithm>

namespace Algo { namespace DS { namespace Array {

class MoveZerosToEnd {
public:
    // Most effective algorithm with minimum copy operations
    static void move(std::vector<int>& nums) {
        for (size_t moveNumHere = 0, current = 0; current < nums.size();
             ++current) {
            if (nums[current] != 0) {
                std::swap(nums[moveNumHere++], nums[current]);
            }
        }
    }
};

} } }

#endif // MOVE_ZEROS_TO_THE_END_OF_ARRAY_HPP
