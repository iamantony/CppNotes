#ifndef CPPNOTESMAIN_SHORTES_UNSORTED_CONTINUOUS_SUBARRAY_HPP
#define CPPNOTESMAIN_SHORTES_UNSORTED_CONTINUOUS_SUBARRAY_HPP

/*
https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
Given an integer array, you need to find one continuous subarray that if you only sort this
subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted
in ascending order.

Note:
- Then length of the input array is in range [1, 10,000].
- The input array may contain duplicates, so ascending order here means <=.
*/

#include <vector>
#include <algorithm>

namespace Algo::DS::Array {
    class ShortedUnsortedContinuousSubarray {
    public:
        static size_t find_with_sorting(const std::vector<int>& nums) {
            if (nums.size() < 2) { return 0; }

            auto dup = nums;
            std::sort(dup.begin(), dup.end());

            size_t l = 0, r = nums.size() - 1;
            while (l < r) {
                if (dup[l] == nums[l]) { ++l; }
                else if (dup[r] == nums[r]) { --r; }
                else { break; }
            }

            return l < r ? r - l + 1 : 0;
        }

        static size_t find_fastest(const std::vector<int>& nums) {
            if (nums.size() < 2) { return 0; }

            int min_num = std::numeric_limits<int>::max();
            bool unsorted = false;
            for (size_t i = 1; i < nums.size(); ++i) {
                if (nums[i] < nums[i - 1]) { unsorted = true; }
                if (unsorted) {
                    min_num = std::min(min_num, nums[i]);
                }
            }

            if (!unsorted) { return 0; }

            int max_num = std::numeric_limits<int>::min();
            unsorted = false;
            for (size_t i = nums.size() - 2; i >= 0; --i) {
                if (nums[i] > nums[i + 1]) { unsorted = true; }
                if (unsorted) {
                    max_num = std::max(max_num, nums[i]);
                }

                if (i == 0) { break; }
            }

            size_t l = 0;
            while (nums[l] <= min_num) { ++l; }

            size_t r = nums.size() - 1;
            while (max_num <= nums[r]) { --r; }

            return r - l + 1;
        }
    };
}

#endif //CPPNOTESMAIN_SHORTES_UNSORTED_CONTINUOUS_SUBARRAY_HPP
