#ifndef MAX_SUBARRAY_SUM_HPP
#define MAX_SUBARRAY_SUM_HPP

// https://leetcode.com/problems/maximum-subarray/description/
// Given an integer array nums, find the contiguous subarray (containing at
// least one number) which has the largest sum and return its sum.

// Example:
// Input: [-2,1,-3,4,-1,2,1,-5,4],
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.

#include <vector>
#include <limits>

namespace Algo::Math {

class MaxSubarraySum {
public:
    static int Calc(const std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int max = std::numeric_limits<int>::min(), currentMax = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            currentMax += nums[i];
            max = std::max(max, currentMax);
            if (currentMax < 0) {
                currentMax = 0;
            }
        }

        return max;
    }
};

}

#endif // MAX_SUBARRAY_SUM_HPP
