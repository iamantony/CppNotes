#ifndef CPPNOTESMAIN_IS_NON_DECREASING_ARRAY_WITH_1_CHANGE_HPP
#define CPPNOTESMAIN_IS_NON_DECREASING_ARRAY_WITH_1_CHANGE_HPP

/*
https://leetcode.com/problems/non-decreasing-array/
Given an array nums with n integers, your task is to check if it could become non-decreasing by
modifying at most 1 element.

We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) such
that (0 <= i <= n - 2).

Example 1:
Input: nums = [4,2,3]
Output: true
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.

Example 2:
Input: nums = [4,2,1]
Output: false
Explanation: You can't get a non-decreasing array by modify at most one element.

Constraints:
* 1 <= n <= 10 ^ 4
* -10 ^ 5 <= nums[i] <= 10 ^ 5

Test cases:
3,4,2,3 - true
5,7,1,8 - true
*/

#include <vector>

namespace Algo::DS::Array {
    class IsNonDecreasingArray {
    public:
        static bool check_long(std::vector<int> v) {
            if (v.size() < 2) { return true; }

            size_t first_pp = v.size();
            for (size_t i = 1; i < v.size(); ++i) {
                if (v[i] < v[i-1]) {
                    first_pp = i-1;
                    break;
                }
            }

            if (first_pp >= v.size()) { return true; }

            size_t second_pp = v.size();
            for (size_t i = v.size() - 1; ; --i) {
                if (v[i] < v[i-1]) {
                    second_pp = i-1;
                    break;
                }

                if (i == 0) { break; }
            }

            if (first_pp != second_pp) { return false; }

            const auto is_non_decreasing = [&v](){
                for (size_t i = 1; i < v.size(); ++i) {
                    if (v[i] < v[i-1]) { return false; }
                }

                return true;
            };

            const auto initial_value = v[first_pp];
            if (first_pp == 0) { v[0] = v[1]; }
            else { v[first_pp] = v[first_pp-1];  }

            if (!is_non_decreasing()) {
                if (first_pp == 0 || first_pp == v.size() - 1) { return false; }

                auto next_pp = first_pp + 1;
                v[first_pp] = initial_value;
                v[next_pp] = v[first_pp];
                return is_non_decreasing();
            }

            return true;
        }

        static bool check_fast(std::vector<int> v) {
            size_t count = 0;
            for (size_t i = 0; i < v.size() - 1; ++i)
            {
                if (v[i] > v[i+1])
                {
                    ++count;
                    if(i > 0 && v[i+1] < v[i-1])
                    {
                        v[i+1] = v[i];
                    }
                }
            }

            return count <= 1;
        }
    };
}

#endif //CPPNOTESMAIN_IS_NON_DECREASING_ARRAY_WITH_1_CHANGE_HPP
