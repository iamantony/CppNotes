#ifndef FIND_TWO_ELEMENTS_HPP_
#define FIND_TWO_ELEMENTS_HPP_

// http://stackoverflow.com/questions/4720271/find-a-pair-of-elements-from-an-array-whose-sum-equals-a-given-number
// Given array of n integers and given a number X, find all the unique pairs of
// elements (a,b), whose summation is equal to X.

#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>

#include "algorithms/search/binary_search.hpp"

namespace Algo::Search {

std::vector<std::pair<int, int>> RemoveDuplicates(
        const std::vector<std::pair<int, int>>& data);

// Naive approach: double check all combinations
// Time complexity: O(n^2) - because we have two nested loops
std::vector<std::pair<int, int>> FindTwoElementsNaive(
        const std::vector<int>& data, const int& value)
{
    std::vector<std::pair<int, int>> result;
    for (size_t i = 0; i < data.size(); ++i)
    {
        for(size_t j = i; j < data.size(); ++j)
        {
            // Skip same element
            if (i == j)
            {
                continue;
            }

            if ( (data[i] + data[j]) == value )
            {
                result.push_back(std::pair<int, int>(data[i], data[j]));
            }
        }
    }

    return RemoveDuplicates(result);
}

// Slightly better approach - using binary search
// Time complexity: O(n * log n) - one loop and nested binary search
std::vector<std::pair<int, int>> FindTwoElementsBS(
        const std::vector<int>& data, const int& value)
{
    std::vector<int> srtData = data;
    std::sort(srtData.begin(), srtData.end());

    std::vector<std::pair<int, int>> result;
    for (size_t i = 0; i < srtData.size(); ++i)
    {
        size_t j = 0;
        BinarySearch::Solution solution;
        if (solution.Search(srtData, srtData.size(), value - srtData[i], j) &&
            i != j)
        {
            result.push_back(std::pair<int, int>(srtData[i], srtData[j]));
        }
    }

    return RemoveDuplicates(result);
}

// Optimal solution - using hash table
// Time complexity: O(n) - one loop, access to hash element O(1)
std::vector<std::pair<int, int>> FindTwoElementsHash(
        const std::vector<int>& data, const int& value)
{
    std::unordered_map<int, size_t> umap;
    std::vector<std::pair<int, int>> result;
    for (size_t i = 0; i < data.size(); ++i)
    {
        if (0 < umap.count(value - data[i]))
        {
            size_t j = umap[value - data[i]];
            result.push_back(std::pair<int, int>(data[i], data[j]));
        }
        else
        {
            umap[data[i]] = i;
        }
    }

    return RemoveDuplicates(result);
}

std::vector<std::pair<int, int>> RemoveDuplicates(
        const std::vector<std::pair<int, int>>& data)
{
    std::vector<std::pair<int, int>> result;
    for (size_t i = 0; i < data.size(); ++i)
    {
        std::pair<int, int> orig = data[i];
        std::pair<int, int> inv = {data[i].second, data[i].first};
        auto func = [&orig, &inv](const std::pair<int, int>& p)
        {
            return p == orig || p == inv;
        };

        if (!std::any_of(result.begin(), result.end(), func))
        {
            result.push_back(data[i]);
        }
    }

    return result;
}

/*
 https://leetcode.com/problems/two-sum/description/
 Given an array of integers, return indices of the two numbers such that
 they add up to a specific target.
 You may assume that each input would have exactly one solution, and you
 may not use the same element twice.

 Example:
 Given nums = [2, 7, 11, 15], target = 9,
 Because nums[0] + nums[1] = 2 + 7 = 9,
 return [0, 1].

https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
Given an array of integers that is already sorted in ascending order, find two
numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they
add up to the target, where index1 must be less than index2.

Note:
Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not
use the same element twice.

Example:
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
*/

class TwoSum {
public:
    static std::vector<int> SearchUnordered(const std::vector<int>& nums,
                                            const int& target) {
        std::unordered_map<int, size_t> umap;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (0 < umap.count(target - nums[i])) {
                size_t j = umap[target - nums[i]];

                std::vector<int> result;
                result.push_back(static_cast<int>(j));
                result.push_back(static_cast<int>(i));
                return result;
            }
            else {
                umap[nums[i]] = i;
            }
        }

        return std::vector<int>();
    }

    static std::vector<int> SearchOrdered(const std::vector<int>& nums,
                                          const int& target) {
        if (nums.size() < 2) {
            return std::vector<int>();
        }

        for (size_t left = 0, right = nums.size() - 1; left < right; ) {
            while (left < right && nums[left] + nums[right] > target) {
                --right;
            }

            if (left < right && nums[left] + nums[right] == target) {
                return std::vector<int>({ static_cast<int>(left),
                                        static_cast<int>(right)});
            }

            ++left;
            right = std::max(right, std::min(left + 1, nums.size() - 1));
            while (right < nums.size() && nums[left] + nums[right] < target) {
                ++right;
            }
        }

        return std::vector<int>();
    }
};
}

#endif /* FIND_TWO_ELEMENTS_HPP_ */
