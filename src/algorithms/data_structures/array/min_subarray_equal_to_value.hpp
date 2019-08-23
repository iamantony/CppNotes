#ifndef MIN_SUBARRAY_EQUAL_TO_VALUE_HPP
#define MIN_SUBARRAY_EQUAL_TO_VALUE_HPP

// https://leetcode.com/problems/minimum-size-subarray-sum/description/

/*
Given an array of n positive integers and a positive integer s, find the
minimal length of a contiguous subarray of which the sum ≥ s. If there isn't
one, return 0 instead.

Example:
Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem
constraint.

Follow up:
If you have figured out the O(n) solution, try coding another solution of
which the time complexity is O(n log n).
*/

#include <vector>
#include <limits>

namespace Algo::DS::Array {
class SubarrayEqualToValue {
public:
    static int FindMinLengthSubarray(const int& s,
                                     const std::vector<int>& nums) {
        if (s <= 0 || nums.empty()) {
            return 0;
        }

        size_t subArrStart = 0;
        int currentSum = nums[subArrStart];
        if (currentSum >= s) {
            return 1;
        }

        int currentLength = 1, minLength = std::numeric_limits<int>::max();
        for (size_t i = 1; i < nums.size(); ++i) {
            currentSum += nums[i];
            ++currentLength;

            if (currentSum >= s) {
                while(currentSum - nums[subArrStart] >= s) {
                    currentSum -= nums[subArrStart];
                    ++subArrStart;
                    --currentLength;
                }

                minLength = std::min(minLength, currentLength);
            }
        }

        return minLength == std::numeric_limits<int>::max() ? 0 : minLength;
    }
};

}

#endif // MIN_SUBARRAY_EQUAL_TO_VALUE_HPP
