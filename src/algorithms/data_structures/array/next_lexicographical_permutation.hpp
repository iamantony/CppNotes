#ifndef CPPNOTESMAIN_NEXT_LEXICOGRAPHICAL_PERMUTATION_HPP
#define CPPNOTESMAIN_NEXT_LEXICOGRAPHICAL_PERMUTATION_HPP

/*
https://leetcode.com/problems/next-permutation/
Implement next permutation, which rearranges numbers into the lexicographically next greater
permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order
(i.e., sorted in ascending order).

The replacement must be in place and use only constant extra memory.

Example 1:
Input: nums = [1,2,3]
Output: [1,3,2]

Example 2:
Input: nums = [3,2,1]
Output: [1,2,3]

Example 3:
Input: nums = [1,1,5]
Output: [1,5,1]

Example 4:
Input: nums = [1]
Output: [1]

Constraints:
* 1 <= nums.length <= 100
* 0 <= nums[i] <= 100
*/

#include <vector>
#include <algorithm>

namespace Algo::DS::Array {
    class NextPermutation {
    public:
        static void get(std::vector<int>& nums) {
            if (nums.size() < 2) { return; }

            size_t swap_pos = nums.size() + 1;
            auto largest = nums.back();
            for (size_t i = nums.size() - 2; i >= 0; --i) {
                if (nums[i] < largest) {
                    swap_pos = i;
                    break;
                }
                else {
                    largest = nums[i];
                }

                if (i == 0) { break; }
            }

            if (swap_pos >= nums.size()) {
                std::reverse(nums.begin(), nums.end());
            }
            else {
                for (size_t i = nums.size() - 1; i > swap_pos; --i) {
                    if (nums[swap_pos] < nums[i]) {
                        std::swap(nums[swap_pos], nums[i]);
                        break;
                    }
                }

                std::reverse(nums.begin() + swap_pos + 1, nums.end());
            }
        }
    };
}

#endif //CPPNOTESMAIN_NEXT_LEXICOGRAPHICAL_PERMUTATION_HPP
