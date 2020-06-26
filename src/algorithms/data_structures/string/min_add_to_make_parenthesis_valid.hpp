#ifndef CPPNOTESMAIN_MIN_ADD_TO_MAKE_PARENTHESIS_VALID_HPP
#define CPPNOTESMAIN_MIN_ADD_TO_MAKE_PARENTHESIS_VALID_HPP

/*
https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
Given a string S of '(' and ')' parentheses, we add the minimum number of parentheses ( '(' or ')',
and in any positions ) so that the resulting parentheses string is valid.

Formally, a parentheses string is valid if and only if:
- It is the empty string, or
- It can be written as AB (A concatenated with B), where A and B are valid strings, or
- It can be written as (A), where A is a valid string.

Given a parentheses string, return the minimum number of parentheses we must add to make th
resulting string valid.

Example 1:
Input: "())"
Output: 1

Example 2:
Input: "((("
Output: 3

Example 3:
Input: "()"
Output: 0

Example 4:
Input: "()))(("
Output: 4

Note:
- s.length <= 1000
- s only consists of '(' and ')' characters.
*/

#include <string>

namespace Algo::DS::String {
    class ValidParenthesis {
    public:
        static size_t num_of_parenthesis_to_add(const std::string& s) {
            size_t errors = 0;
            size_t open_parenthesis = 0;
            for (const auto& c : s) {
                if (c == '(') {
                    ++open_parenthesis;
                }
                else if (c == ')') {
                    if (open_parenthesis == 0) {
                        ++errors;
                    }
                    else {
                        --open_parenthesis;
                    }
                }
            }

            return errors + open_parenthesis;
        }
    };
}

#endif //CPPNOTESMAIN_MIN_ADD_TO_MAKE_PARENTHESIS_VALID_HPP
