#ifndef CPPNOTESMAIN_GENERATE_ALL_SUBSETS_OF_INPUT_NUMS_HPP
#define CPPNOTESMAIN_GENERATE_ALL_SUBSETS_OF_INPUT_NUMS_HPP

/*
https://leetcode.com/problems/subsets/
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:
Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

#include <vector>
#include <algorithm>

namespace Algo::DP {
    class GenerateSubsets {
        void create_subset(
            std::vector<std::vector<int>>& result,
            const std::vector<int>& nums,
            std::vector<int> subset,
            const size_t pos)
        {
            if (pos >= nums.size()) { return; }

            create_subset(result, nums, subset, pos+1);

            for (size_t i = pos; i < nums.size(); ++i) {
                subset.push_back(nums[i]);
                result.push_back(subset);
                create_subset(result, nums, subset, i+2);
            }
        }

    public:
        std::vector<std::vector<int>> generate_subsets(std::vector<int>& nums) {
            std::vector<std::vector<int>> result;
            result.push_back({});

            std::sort(nums.begin(), nums.end());
            for (size_t i = 0; i < nums.size(); ++i) {
                std::vector<int> subset = {nums[i]};
                result.push_back(subset);

                create_subset(result, nums, subset, i+1);
            }

            return result;
        }
    };
}

#endif //CPPNOTESMAIN_GENERATE_ALL_SUBSETS_OF_INPUT_NUMS_HPP
