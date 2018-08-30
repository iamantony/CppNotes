#ifndef DUPLICATES_IN_ARRAY_HPP
#define DUPLICATES_IN_ARRAY_HPP

/*
https://leetcode.com/problems/contains-duplicate/description/
Given an array of integers, find if the array contains any duplicates.
Your function should return true if any value appears at least twice in
the array, and it should return false if every element is distinct.


https://leetcode.com/problems/contains-duplicate-ii/description/
Given an array of integers and an integer k, find out whether there are two
distinct indices i and j in the array such that nums[i] = nums[j] and the
absolute difference between i and j is at most k.

Example 1:
Input: nums = [1,2,3,1], k = 3
Output: true

Example 2:
Input: nums = [1,0,1,1], k = 1
Output: true

Example 3:
Input: nums = [1,2,3,1,2,3], k = 2
Output: false
*/

#include <vector>
#include <unordered_map>
#include <algorithm>

namespace Algo::DS::Array {

class DuplicatesInArray {
public:
    static bool Contains(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                return true;
            }
        }

        return false;
    }

    static bool ContainsWithinDistance(
            const std::vector<int>& nums, const size_t& maxDistance)
    {
        std::unordered_map<int, size_t> elements;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (elements.count(nums[i]) > 0) {
                if (i - elements[nums[i]] <= maxDistance) {
                    return true;
                }
            }

            elements[nums[i]] = i;
        }

        return false;
    }
};

}

#endif // DUPLICATES_IN_ARRAY_HPP
