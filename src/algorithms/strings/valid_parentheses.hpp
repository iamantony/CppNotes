#ifndef VALID_PARENTHESES_HPP
#define VALID_PARENTHESES_HPP

// https://leetcode.com/problems/valid-parentheses/description/

/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

An input string is valid if:
- Open brackets must be closed by the same type of brackets.
- Open brackets must be closed in the correct order.

Note that an empty string is also considered valid.

Example 1: Input: "()", Output: true
Example 2: Input: "()[]{}", Output: true
Example 3: Input: "(]", Output: false
Example 4: Input: "([)]", Output: false
Example 5: Input: "{[]}", Output: true
*/

#include <string>
#include <unordered_map>
#include <set>
#include <stack>

namespace Algo::Strings {

class ValidParentheses {
public:
    static bool IsValid(const std::string& s) {
        std::stack<char> expectedCloseBrackets;
        for (auto bracket : s) {
            if (IsOpenBracket(bracket)) {
                auto closeBracket = GetCloseBracket(bracket);
                if (closeBracket == 0) {
                    return false;
                }

                expectedCloseBrackets.push(closeBracket);
            }
            else {
                if (expectedCloseBrackets.empty() ||
                    expectedCloseBrackets.top() != bracket) {
                    return false;
                }

                expectedCloseBrackets.pop();
            }
        }

        return expectedCloseBrackets.empty();
    }

private:
    static bool IsOpenBracket(const char& bracket) {
        static std::set<char> openBrackets = {'(', '{', '['};
        return openBrackets.count(bracket) > 0;
    }

    static char GetCloseBracket(const char& closeBracket) {
        static std::unordered_map<char, char> bracketsMap = {
            {'(', ')'}, {'{', '}'}, {'[', ']'}
        };

        auto iter = bracketsMap.find(closeBracket);
        return iter != bracketsMap.end() ? iter->second : 0;
    }
};

}

#endif // VALID_PARENTHESES_HPP
