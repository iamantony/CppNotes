#ifndef CPPNOTESMAIN_SPLIT_ARRAY_INTO_CONSECUTIVE_SUBSEQUENCES_HPP
#define CPPNOTESMAIN_SPLIT_ARRAY_INTO_CONSECUTIVE_SUBSEQUENCES_HPP

#include <vector>

namespace Algo::Greedy {
    class SplitArray {
    public:
        /*
        https://leetcode.com/problems/split-array-into-consecutive-subsequences/
        Given an array nums sorted in ascending order, return true if and only if you can split it
        into 1 or more subsequences such that each subsequence consists of consecutive integers and
        has length at least 3.

        Example 1:
        Input: [1,2,3,3,4,5]
        Output: True
        Explanation:
        You can split them into two consecutive subsequences :
        1, 2, 3
        3, 4, 5

        Example 2:
        Input: [1,2,3,3,4,4,5,5]
        Output: True
        Explanation:
        You can split them into two consecutive subsequences :
        1, 2, 3, 4, 5
        3, 4, 5

        Example 3:
        Input: [1,2,3,4,4,5]
        Output: False

        Constraints:
        - 1 <= nums.length <= 10000
        */
        static bool canSplitIntoConsecutiveSubsequences(const std::vector<int>& nums) {
            std::vector<std::vector<size_t>> sequences;
            for (size_t i = 0; i < nums.size(); ) {
                size_t j = i, count = 0;
                while (j < nums.size() && nums[j] == nums[i]) {
                    ++count;
                    ++j;
                }

                // check if current number is not consecutive number. In this case all current
                // subsequences should be "finished".
                if (i > 0 && nums[i] - nums[i-1] > 1) {
                    for (const auto& seq : sequences) {
                        if (seq.size() < 3) { return false; }
                    }

                    sequences.clear();
                }

                while (count < sequences.size()) {
                    if (sequences.front().size() < 3) { return false; }

                    sequences.erase(sequences.begin());
                }

                sequences.resize(count);
                for (auto& seq : sequences) {
                    seq.push_back(nums[i]);
                }

                i += count;
            }

            for (const auto& seq : sequences) {
                if (seq.size() < 3) { return false; }
            }

            return true;
        }

        /*
        https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/
        https://leetcode.com/problems/hand-of-straights/ - duplicate
        Given an array of integers nums and a positive integer k, find whether it's possible to
        divide this array into sets of k consecutive numbers.
        Return True if its possible otherwise return False.

        Example 1:
        Input: nums = [1,2,3,3,4,4,5,6], k = 4
        Output: true
        Explanation: Array can be divided into [1,2,3,4] and [3,4,5,6].

        Example 2:
        Input: nums = [3,2,1,2,3,4,3,4,5,9,10,11], k = 3
        Output: true
        Explanation: Array can be divided into [1,2,3] , [2,3,4] , [3,4,5] and [9,10,11].

        Example 3:
        Input: nums = [3,3,2,2,1,1], k = 3
        Output: true

        Example 4:
        Input: nums = [1,2,3,4], k = 3
        Output: false
        Explanation: Each array should be divided in subarrays of size 3.

        Constraints:
        1 <= nums.length <= 10^5
        1 <= nums[i] <= 10^9
        1 <= k <= nums.length
        */
        static bool canSplitIntoFixedConsecutiveSubsequences(
            std::vector<int>& nums, const size_t k)
        {
            std::sort(nums.begin(), nums.end());
            std::vector<std::vector<size_t>> sequences;
            for (size_t i = 0; i < nums.size(); ) {
                size_t j = i, count = 0;
                while (j < nums.size() && nums[j] == nums[i]) {
                    ++count;
                    ++j;
                }

                // check if current number is not consecutive number. In this case all current
                // subsequences should be "finished".
                if (i > 0 && nums[i] - nums[i-1] > 1) {
                    for (const auto& seq : sequences) {
                        if (seq.size() != k) { return false; }
                    }

                    sequences.clear();
                }

                auto remove_from_iter = std::remove(
                    sequences.begin(),
                    sequences.end(),
                    [&k](const auto& seq){ return seq.size() == k; });
                sequences.erase(remove_from_iter, sequences.end());

                while (count < sequences.size()) {
                    if (sequences.front().size() != k) { return false; }

                    sequences.erase(sequences.begin());
                }

                sequences.resize(count);
                for (auto& seq : sequences) {
                    seq.push_back(nums[i]);
                }

                i += count;
            }

            for (const auto& seq : sequences) {
                if (seq.size() != k) { return false; }
            }

            return true;
        }
    };
}

#endif //CPPNOTESMAIN_SPLIT_ARRAY_INTO_CONSECUTIVE_SUBSEQUENCES_HPP
