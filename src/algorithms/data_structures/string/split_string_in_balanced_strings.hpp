#ifndef CPPNOTESMAIN_SPLIT_STRING_IN_BALANCED_STRINGS_HPP
#define CPPNOTESMAIN_SPLIT_STRING_IN_BALANCED_STRINGS_HPP

/*
https://leetcode.com/problems/split-a-string-in-balanced-strings/
Balanced strings are those who have equal quantity of 'L' and 'R' characters.
Given a balanced string s split it in the maximum amount of balanced strings.
Return the maximum amount of splitted balanced strings.

Example 1:
Input: s = "RLRRLLRLRL"
Output: 4
Explanation: s can be split into "RL", "RRLL", "RL", "RL", each substring contains same number
of 'L' and 'R'.

Example 2:
Input: s = "RLLLLRRRLR"
Output: 3
Explanation: s can be split into "RL", "LLLRRR", "LR", each substring contains same number of
'L' and 'R'.

Example 3:
Input: s = "LLLLRRRR"
Output: 1
Explanation: s can be split into "LLLLRRRR".

Example 4:
Input: s = "RLRRRLLRLL"
Output: 2
Explanation: s can be split into "RL", "RRRLLRLL", since each substring contains an equal number of
'L' and 'R'


Constraints:
 - 1 <= s.length <= 1000
 - s[i] = 'L' or 'R'
*/

#include <string>

namespace Algo::DS::String {
    class SplitBalancedString {
    public:
        int num_of_balanced_substrings(const std::string& s) {
            int result = 0;
            size_t num_of_r = 0;
            size_t num_of_l = 0;
            for (const auto& c : s) {
                if (c == 'R') { ++num_of_r; }
                else if (c == 'L') { ++num_of_l; }

                if (num_of_r > 0 && num_of_r == num_of_l) {
                    ++result;
                    num_of_r = num_of_l = 0;
                }
            }

            return result;
        }
    };
}

#endif //CPPNOTESMAIN_SPLIT_STRING_IN_BALANCED_STRINGS_HPP
