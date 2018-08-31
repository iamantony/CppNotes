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
#include <unordered_set>
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
            const int& maxDifference,
            const size_t& maxDistance)
    {
        if (nums.size() < 2 || maxDifference < 0 || maxDistance <= 0) {
            return false;
        }

        std::multimap<int, size_t> elements;

        // Carefully calculate summation of 'value' and 'diff' without overflow
        auto CalcDiffValue = [](const int& value, const int& diff) -> int {
            long long intMin = std::numeric_limits<int>::min();
            long long intMax = std::numeric_limits<int>::max();

            long long sum = static_cast<long long>(value) +
                    static_cast<long long>(diff);

            sum = std::max(intMin, std::min(intMax, sum));
            return static_cast<int>(sum);
        };

        for (size_t i = 0; i < nums.size(); ++i) {
            // Get iterator to the map key that is >= than nums[i]
            auto iter = elements.lower_bound(nums[i]);
            if (iter != elements.end()) {
                if (nums[i] == iter->first) {
                    // Here we got iter that points to the first element
                    // with key == nums[i]. We should iterate over all
                    // elements with the same key and check their value
                    while (iter != elements.end() && iter->first == nums[i]) {
                        if (i - iter->second <= maxDistance) {
                            return true;
                        }

                        ++iter;
                    }
                }
                else if (iter != elements.begin()) {
                    // Here iter is the middle element with first key > nums[i].
                    // We could be in two positions:
                    // 1. Between several ranges
                    // 2. Inside several ranges

                    // Our aim is to be in case 2. We would return true only if
                    // this range have value within maxDistance.
                    // Let's first of all get all valid values for
                    // keys > nums[i].

                    std::unordered_set<size_t> validDistances;

                    {
                        auto iterWithSameKey = iter;
                        const int key = iterWithSameKey->first;
                        while (iterWithSameKey != elements.end() &&
                               iterWithSameKey->first == key)
                        {
                            if (i - iterWithSameKey->second <= maxDistance) {
                                validDistances.insert(iterWithSameKey->second);
                            }

                            ++iterWithSameKey;
                        }
                    }

                    // Next step - get previous iterator with key < nums[i].
                    // Find out if there are elements with prevKey and valid
                    // value. If yes, then we are in valid range -> return true.
                    auto prevIter = iter;
                    --prevIter;
                    const int prevKey = prevIter->first;
                    while (prevIter->first == prevKey) {
                        if (validDistances.count(prevIter->second) > 0) {
                            return true;
                        }

                        if (prevIter == elements.begin()) {
                            break;
                        }

                        --prevIter;
                    }
                }
            }

            /*
            We could insert into the map values { nums[i] - maxDifference,
            nums[i] - maxDifference + 1, ... , nums[i] + maxDifference }, but
            there could be millions of values depending on 'maxDifference'.
            To save memory, it is more efficient to insert ranges -
            { nums[i] - maxDifference, nums[i] + maxDifference }.
            */
            const int minRangeValue =
                    CalcDiffValue(nums[i], -1 * std::abs(maxDifference));

            const int maxRangeValue =
                    CalcDiffValue(nums[i], std::abs(maxDifference));

            auto startIter = elements.insert( { minRangeValue, i } );
            if (maxRangeValue > minRangeValue) {
                elements.insert( { maxRangeValue, i } );

                // Between startIter and maxRangeIter there could be other
                // elements that has relation to other ranges.
                ++startIter;
                while (startIter->first != maxRangeValue) {
                    const int key = startIter->first;
                    elements.insert(startIter, {key, i});
                    while (key == startIter->first) {
                        ++startIter;
                    }
                }
            }
        }

        return false;
    }
};

}

#endif // DUPLICATES_IN_ARRAY_HPP
