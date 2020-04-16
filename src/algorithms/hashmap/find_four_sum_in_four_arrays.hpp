#ifndef FIND_FOUR_SUM_IN_FOUR_ARRAYS_HPP
#define FIND_FOUR_SUM_IN_FOUR_ARRAYS_HPP

/*
https://leetcode.com/problems/4sum-ii/
Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are
such that A[i] + B[j] + C[k] + D[l] is zero.

To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All
integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.

Example:
Input:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

Output:
2

Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
*/

#include <vector>
#include <unordered_map>

namespace Algo::Search {
    class FindFourSumInArrays {
    public:
        static int find(
            std::vector<int> v1, std::vector<int> v2, std::vector<int> v3, std::vector<int> v4)
        {
            if (v1.empty() || v2.empty() || v3.empty() || v4.empty()) { return 0; }

            std::unordered_map<int, int> v1_v2_sums;
            for (const auto& i : v1) {
                for (const auto& j: v2) {
                    ++v1_v2_sums[i + j];
                }
            }

            int result = 0;
            for (const auto& k : v3) {
                for (const auto m : v4) {
                    const auto negative_sum = (k + m) * -1;
                    const auto iter = v1_v2_sums.find(negative_sum);
                    if (iter != v1_v2_sums.end()) {
                        result += iter->second;
                    }
                }
            }

            return result;
        }
    };
}

#endif //FIND_FOUR_SUM_IN_FOUR_ARRAYS_HPP
