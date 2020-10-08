#ifndef CPPNOTESMAIN_GENERATE_VALID_PERMUTATIONS_OF_PARENTHESES_HPP
#define CPPNOTESMAIN_GENERATE_VALID_PERMUTATIONS_OF_PARENTHESES_HPP

/*
https://leetcode.com/problems/generate-parentheses/
Given n pairs of parentheses, write a function to generate all combinations of
well-formed parentheses.

Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]

Constraints:
1 <= n <= 8
*/

#include <string>
#include <vector>

namespace Algo::DP {
    class GenerateParenthesesPermutations {
        static void backtrack(
            std::vector<std::string>& result,
            std::string str,
            const size_t open,
            const size_t close,
            const size_t pairs_num)
        {
            if (str.size() == pairs_num * 2) {
                result.push_back(str);
                return;
            }

            if (open < pairs_num) {
                backtrack(result, str+"(", open+1, close, pairs_num);
            }
            if (close < open) {
                backtrack(result, str+")", open, close+1, pairs_num);
            }
        }

    public:
        static std::vector<std::string> generate(const size_t pairs_num) {
            std::vector<std::string> result;
            backtrack(result, "", 0, 0, pairs_num);
            return result;
        }
    };
}

#endif //CPPNOTESMAIN_GENERATE_VALID_PERMUTATIONS_OF_PARENTHESES_HPP
