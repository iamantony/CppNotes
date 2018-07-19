#ifndef FIND_LARGEST_NUM_TWICE_OF_OTHERS_HPP
#define FIND_LARGEST_NUM_TWICE_OF_OTHERS_HPP

// https://leetcode.com/problems/largest-number-at-least-twice-of-others/description/

/*
In a given integer array nums, there is always exactly one largest element.

Find whether the largest element in the array is at least twice as much as
every other number in the array.

If it is, return the index of the largest element, otherwise return -1.

Example 1:
Input: nums = [3, 6, 1, 0]
Output: 1
Explanation: 6 is the largest integer, and for every other number in the array x,
6 is more than twice as big as x.  The index of value 6 is 1, so we return 1.

Example 2:
Input: nums = [1, 2, 3, 4]
Output: -1
Explanation: 4 isn't at least as big as twice the value of 3, so we return -1.

Note:
- nums will have a length in the range [1, 50].
- Every nums[i] will be an integer in the range [0, 99].
*/

#include <vector>

namespace Algo::DS::Array {

class FindLargest {
public:
    static int LargestAtLeastTwiceOfOthers(const std::vector<int>& nums) {
        if (nums.empty()) {
            return -1;
        }

        if (nums.size() == 1) {
            return 0;
        }

        size_t largestIndex = 0, prevLargestIndex = 0;
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[largestIndex]) {
                prevLargestIndex = largestIndex;
                largestIndex = i;
            }
            else {
                if (prevLargestIndex == largestIndex) {
                    prevLargestIndex = i;
                }
                else if (nums[i] > nums[prevLargestIndex]) {
                    prevLargestIndex = i;
                }
            }
        }

        if (nums[prevLargestIndex] * 2 <= nums[largestIndex]) {
            return static_cast<int>(largestIndex);
        }

        return -1;
    }
};

}

#endif // FIND_LARGEST_NUM_TWICE_OF_OTHERS_HPP
