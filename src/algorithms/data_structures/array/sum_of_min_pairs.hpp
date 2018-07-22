#ifndef SUM_OF_MIN_PAIRS_HPP
#define SUM_OF_MIN_PAIRS_HPP

/*
https://leetcode.com/problems/array-partition-i/description/

Given an array of 2n integers, your task is to group these integers into n
pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes
sum of min(ai, bi) for all i from 1 to n as large as possible.

Example 1:
Input: [1,4,3,2]
Output: 4
Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).

Note:
n is a positive integer, which is in the range of [1, 10000].
All the integers in the array will be in the range of [-10000, 10000].
*/

#include <vector>
#include <algorithm>

namespace Algo::DS::Array {

class SumOfMinPairs {
public:
    static int LargestSum(std::vector<int>& nums) {
        if (nums.empty() || nums.size() % 2 == 1) {
            return 0;
        }

        std::sort(nums.begin(), nums.end());
        int result = 0;
        for (size_t i = 0; i < nums.size(); i += 2) {
            result += nums[i];
        }

        return result;
    }
};

}

#endif // SUM_OF_MIN_PAIRS_HPP
