#ifndef DUPLICATES_IN_ARRAY_HPP
#define DUPLICATES_IN_ARRAY_HPP

// https://leetcode.com/problems/contains-duplicate/description/

// Given an array of integers, find if the array contains any duplicates.
// Your function should return true if any value appears at least twice in
// the array, and it should return false if every element is distinct.

#include <vector>
#include <algorithm>

namespace DuplicatesInArray {

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                return true;
            }
        }

        return false;
    }
};

}

#endif // DUPLICATES_IN_ARRAY_HPP
