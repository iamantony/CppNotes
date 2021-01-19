#ifndef CPPNOTESMAIN_FIND_PEAK_ELEMENT_HPP
#define CPPNOTESMAIN_FIND_PEAK_ELEMENT_HPP

/*
https://leetcode.com/problems/find-peak-element/
A peak element is an element that is strictly greater than its neighbors.

Given an integer array nums, find a peak element, and return its index. If the array contains
multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞.

Example 1:
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.

Example 2:
Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index
number 5 where the peak element is 6.

Constraints:
* 1 <= nums.length <= 1000
* -231 <= nums[i] <= 231 - 1
* nums[i] != nums[i + 1] for all valid i.

Follow up: Could you implement a solution with logarithmic complexity?
*/

#include <vector>

namespace Algo::DS::Array {
    template <typename T>
    class FindPeakElement {
    public:
        static size_t find(const std::vector<T>& nums) {
            if (nums.empty()) { return nums.size() + 1; }
            if (nums.size() == 1) { return 0; }

            size_t left = 0;
            size_t right = nums.size() - 1;
            while (left <= right) {
                auto middle = left + (right - left) / 2;
                if (middle == 0) {
                    if (nums[middle] > nums[middle + 1]) { return middle; }
                    else {
                        left = middle + 1;
                    }
                }
                else if (middle == nums.size() - 1) {
                    if (nums[middle] > nums[middle - 1]) { return middle; }
                    else {
                        right = middle - 1;
                    }
                }
                else {
                    if (nums[middle] > nums[middle - 1] && nums[middle] > nums[middle + 1]) {
                        return middle;
                    }
                    else if (nums[middle] > nums[middle - 1]) {
                        left = middle + 1;
                    }
                    else {
                        right = middle - 1;
                    }
                }
            }

            return nums.size() + 1;
        }
    };
}

#endif //CPPNOTESMAIN_FIND_PEAK_ELEMENT_HPP
