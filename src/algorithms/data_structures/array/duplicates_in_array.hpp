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


https://leetcode.com/problems/contains-duplicate-iii/description/
Given an array of integers, find out whether there are two distinct indices
i and j in the array such that the absolute difference between nums[i] and
nums[j] is at most t and the absolute difference between i and j is at most k.

Example 1:
Input: nums = [1,2,3,1], k = 3, t = 0
Output: true

Example 2:
Input: nums = [1,0,1,1], k = 1, t = 2
Output: true

Example 3:
Input: nums = [1,5,9,1,5,9], k = 2, t = 3
Output: false
*/

#include <vector>
#include <unordered_map>
#include <map>
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

    static bool ContainsNearbyAlmostDuplicates(
            const std::vector<int>& nums,
            const int& difference,
            const size_t& maxDistance)
    {
        if (nums.size() < 2 || difference < 0 || maxDistance == 0) {
            return false;
        }

        std::map<int, size_t> elements;

        auto CalcDiffValue = [](const int& value, const int& diff) {
            static long long intMin = std::numeric_limits<int>::min();
            static long long intMax = std::numeric_limits<int>::max();

            long long result = value + diff;
            result = std::max(intMin, result);
            result = std::min(intMax, result);
            return static_cast<int>(result);
        };

        auto InsertOrUpdate = [&elements](const int& value, const size_t& pos) {
            auto insertResult = elements.insert( {value, pos} );
            if (!insertResult.second) {
                insertResult.first->second = pos;
            }

            return insertResult.first;
        };

        for (size_t i = 0; i < nums.size(); ++i) {
            auto iter = elements.lower_bound(nums[i]);
            if (iter != elements.end()) {
                if (iter == elements.begin()) {
                    if (nums[i] == iter->first && i - iter->second <= maxDistance) {
                        return true;
                    }
                }
                else {
                    auto prev = iter;
                    --prev;
                    if (prev->second == iter->second) {
                        if (i - iter->second <= maxDistance) {
                            return true;
                        }
                    }
                }
            }

            const int minValidValue = CalcDiffValue(nums[i], -1 * std::abs(difference));
            const int maxValidValue = CalcDiffValue(nums[i], std::abs(difference));

            auto startIter = InsertOrUpdate(minValidValue, i);
            auto endIter = InsertOrUpdate(maxValidValue, i);
            while (startIter != endIter) {
                startIter->second = i;
                ++startIter;
            }
        }

        return false;
    }
};

}

#endif // DUPLICATES_IN_ARRAY_HPP
