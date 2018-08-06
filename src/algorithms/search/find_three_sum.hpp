#ifndef FIND_THREE_SUM_HPP
#define FIND_THREE_SUM_HPP

/*
https://leetcode.com/problems/3sum/description/

Given an array nums of n integers, are there elements a, b, c in nums such
that a + b + c = 0? Find all unique triplets in the array which gives the
sum of zero.

Note:
The solution set must not contain duplicate triplets.

Example:
Given array nums = [-1, 0, 1, 2, -1, -4],
A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>

namespace Algo::Search {

class Find3Sum {
public:

    // TC: O(n^3)
    // SC: O(2n) in worst case
    static std::vector<std::vector<int>> FindNaive(
            const std::vector<int>& nums) {
        if (nums.size() < 3) {
            return std::vector<std::vector<int>>();
        }

        std::set<std::vector<int>> validTriplets;
        for (size_t i = 0; i < nums.size(); ++i) {
            for (size_t j = i + 1; j < nums.size(); ++j) {
                for (size_t k = j + 1; k < nums.size(); ++k) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        std::vector<int> triplet = {nums[i], nums[j], nums[k]};
                        std::sort(triplet.begin(), triplet.end());
                        validTriplets.insert(triplet);

                    }
                }
            }
        }

        std::vector<std::vector<int>> result;
        for (auto iter : validTriplets) {
            result.push_back(iter);
        }

        std::sort(result.begin(), result.end());
        return result;
    }

    // TC: O(n^2)
    // SC: O(2n) in worst case
    static std::vector<std::vector<int>> FindWithHash(
            const std::vector<int>& nums) {
        if (nums.size() < 3) {
            return std::vector<std::vector<int>>();
        }

        std::set<std::vector<int>> validTriplets;
        for (size_t i = 0; i < nums.size(); ++i) {
            std::unordered_set<int> values;
            for (size_t j = i + 1; j < nums.size(); ++j) {
                int thirdValue = -(nums[i] + nums[j]);
                if (values.count(thirdValue) > 0 ) {
                    std::vector<int> triplet = {
                        nums[i], nums[j], thirdValue};

                    std::sort(triplet.begin(), triplet.end());
                    validTriplets.insert(triplet);
                }
                else {
                    values.insert(nums[j]);
                }
            }
        }

        std::vector<std::vector<int>> result;
        for (auto iter : validTriplets) {
            result.push_back(iter);
        }

        std::sort(result.begin(), result.end());
        return result;
    }

    // TC: O(n^2)
    // SC: O(2n) in worst case
    static std::vector<std::vector<int>> FindWithSorting(
            std::vector<int> nums) {
        if (nums.size() < 3) {
            return std::vector<std::vector<int>>();
        }

        std::sort(nums.begin(), nums.end());

        std::set<std::vector<int>> validTriplets;
        for (size_t i = 0; i < nums.size(); ++i) {
            // Skip duplicates after first run
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            size_t mid = i + 1, right = nums.size() - 1;
            while (mid < right) {
                int sum = nums[i] + nums[mid] + nums[right];
                if (sum == 0)
                {
                    std::vector<int> triplet = {
                        nums[i], nums[mid], nums[right]};

                    std::sort(triplet.begin(), triplet.end());
                    validTriplets.insert(triplet);

                    // Skip same elements
                    while (mid < right && nums[mid] == nums[mid + 1]) {
                        ++mid;
                    }

                    while (mid < right - 1 && nums[right] == nums[right - 1]) {
                        --right;
                    }

                    ++mid, --right;
                }
                else if (sum < 0) {
                    ++mid;
                }
                else {
                    --right;
                }
            }
        }

        std::vector<std::vector<int>> result;
        for (auto iter : validTriplets) {
            result.push_back(iter);
        }

        std::sort(result.begin(), result.end());
        return result;
    }
};

}

#endif // FIND_THREE_SUM_HPP
