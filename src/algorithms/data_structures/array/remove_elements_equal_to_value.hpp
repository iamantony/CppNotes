#ifndef MOVE_ZEROS_TO_THE_END_OF_ARRAY_HPP
#define MOVE_ZEROS_TO_THE_END_OF_ARRAY_HPP

/*
https://leetcode.com/problems/move-zeroes/description/
Given an array nums, write a function to move all 0's to the end of it while
maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function,
nums should be [1, 3, 12, 0, 0].

Note:
- You must do this in-place without making a copy of the array.
- Minimize the total number of operations.

https://leetcode.com/problems/remove-element/description/
Given an array nums and a value val, remove all instances of that value
in-place and return the new length.

Do not allocate extra space for another array, you must do this by modifying
the input array in-place with O(1) extra memory.

The order of elements can be changed. It doesn't matter what you leave beyond
the new length.

Example 1:
Given nums = [3,2,2,3], val = 3,
Your function should return length = 2, with the first two elements of nums
being 2.
It doesn't matter what you leave beyond the returned length.

Example 2:
Given nums = [0,1,2,2,3,0,4,2], val = 2,
Your function should return length = 5, with the first five elements of nums
containing 0, 1, 3, 0, and 4.
Note that the order of those five elements can be arbitrary.
It doesn't matter what values are set beyond the returned length.

Clarification:
Confused why the returned value is an integer but your answer is an array?
Note that the input array is passed in by reference, which means modification
to the input array will be known to the caller as well.

Internally you can think of this:

// nums is passed in by reference. (i.e., without making a copy)
int len = removeElement(nums, val);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
*/

#include <vector>
#include <algorithm>

namespace Algo::DS::Array {

class RemoveElement {
public:
    // Most effective algorithm with minimum copy operations
    static void MoveZerosToTheEnd(std::vector<int>& nums) {
        Remove(nums, 0);
    }

    static int Remove(std::vector<int>& nums, const int& value) {
        size_t moveHere = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] != value) {
                std::swap(nums[moveHere], nums[i]);
                ++moveHere;
            }
        }

        return static_cast<int>(moveHere);
    }
};

}

#endif // MOVE_ZEROS_TO_THE_END_OF_ARRAY_HPP
