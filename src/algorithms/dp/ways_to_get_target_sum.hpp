#ifndef WAYS_TO_GET_TARGET_SUM_HPP
#define WAYS_TO_GET_TARGET_SUM_HPP

/*
https://leetcode.com/problems/target-sum/
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have
2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3.
Output: 5

Explanation:
-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.

Note:
- The length of the given array is positive and will not exceed 20.
- The sum of elements in the given array will not exceed 1000.
- Your output answer is guaranteed to be fitted in a 32-bit integer.
*/

#include <vector>
#include <algorithm>
#include <numeric>

// TODO refer to 0-1 knapsack problem
namespace Algo::DP {
    class WaysToGetTargetSum {
        static size_t calcImpl(const std::vector<int>& v, const int& target, const size_t pos) {
            if (pos >= v.size()) { return 0; }

            auto posValue = std::abs(v[pos]);
            auto plusVariant = v, minusVariant = v;
            plusVariant[pos] = posValue;
            minusVariant[pos] = posValue * -1;

            size_t numOfVariantsEqualToTarget = 0;

            if (std::accumulate(plusVariant.begin(), plusVariant.end(), 0) == target) {
                ++numOfVariantsEqualToTarget;
            }

            if (std::accumulate(minusVariant.begin(), minusVariant.end(), 0) == target) {
                ++numOfVariantsEqualToTarget;
            }

            numOfVariantsEqualToTarget += calcImpl(plusVariant, target, pos + 1);
            numOfVariantsEqualToTarget += calcImpl(minusVariant, target, pos + 1);
            return numOfVariantsEqualToTarget;
        }

    public:
        static size_t calc(std::vector<int> v, const int& target) {
            return calcImpl(v, target, 0);
        }
    };
}

#endif //WAYS_TO_GET_TARGET_SUM_HPP
