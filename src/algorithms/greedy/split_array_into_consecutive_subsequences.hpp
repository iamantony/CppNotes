#ifndef CPPNOTESMAIN_SPLIT_ARRAY_INTO_CONSECUTIVE_SUBSEQUENCES_HPP
#define CPPNOTESMAIN_SPLIT_ARRAY_INTO_CONSECUTIVE_SUBSEQUENCES_HPP

/*
https://leetcode.com/problems/split-array-into-consecutive-subsequences/
Given an array nums sorted in ascending order, return true if and only if you can split it into 1
or more subsequences such that each subsequence consists of consecutive integers and has length at
least 3.

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

#include <vector>

namespace Algo::Greedy {
    class SplitArray {
    public:
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
    };
}

#endif //CPPNOTESMAIN_SPLIT_ARRAY_INTO_CONSECUTIVE_SUBSEQUENCES_HPP
