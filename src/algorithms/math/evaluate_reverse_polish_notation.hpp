#ifndef EVALUATE_REVERSE_POLISH_NOTATION_HPP
#define EVALUATE_REVERSE_POLISH_NOTATION_HPP

/*
https://leetcode.com/problems/evaluate-reverse-polish-notation/
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Note:
Division between two integers should truncate toward zero.
The given RPN expression is always valid. That means the expression would always evaluate to a
result and there won't be any divide by zero operation.

Example 1:
Input: ["2", "1", "+", "3", "*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9

Example 2:
Input: ["4", "13", "5", "/", "+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6

Example 3:
Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
Output: 22
Explanation:
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
*/

#include <vector>
#include <string>
#include <stack>
#include <unordered_set>
#include <iostream>
#include <exception>

namespace Algo::Math {
    class ReversePolishNotation {
        static std::pair<int, int> getTwoValues(std::stack<int>& values) {
            if (values.size() < 2) {
                throw std::invalid_argument("Can't get two values from stack");
            }

            const auto second = values.top();
            values.pop();

            const auto first = values.top();
            values.pop();

            return {first, second};
        }

        static void addition(std::stack<int>& values) {
            const auto [first, second] = getTwoValues(values);
            values.push(first + second);
        }

        static void subtraction(std::stack<int>& values) {
            const auto [first, second] = getTwoValues(values);
            values.push(first - second);
        }

        static void multiplication(std::stack<int>& values) {
            const auto [first, second] = getTwoValues(values);
            values.push(first * second);
        }

        static void division(std::stack<int>& values) {
            const auto [first, second] = getTwoValues(values);
            if (second == 0) {
                throw std::logic_error("Division by 0 detected");
            }

            const auto result = static_cast<double>(first) / static_cast<double>(second);
            values.push(static_cast<int>(result));
        }

        static void addInteger(const std::string& str, std::stack<int>& values) {
            values.push(std::stoi(str));
        }

    public:
        static int evaluate(const std::vector<std::string>& tokens) {
            std::stack<int> values;
            const std::unordered_set<char> operations = {'+', '-', '*', '/'};
            try {
                for (const auto& token : tokens) {
                    if (token.empty()) {
                        throw std::logic_error("Empty token");
                    }

                    if (token.size() == 1 && operations.count(token[0]) > 0) {
                        switch(token[0]) {
                            case '+': addition(values); break;
                            case '-': subtraction(values); break;
                            case '*': multiplication(values); break;
                            case '/': division(values); break;
                            default: throw std::logic_error("Invalid operator detected");
                        }
                    }
                    else {
                        addInteger(token, values);
                    }
                }
            }
            catch (std::exception& e) {
                std::cout << "Exception during evaluation of Reverse Polish Notation: " <<
                    e.what() << std::endl;
                return 0;
            }

            return values.empty() ? 0 : values.top();
        }
    };
}

#endif //EVALUATE_REVERSE_POLISH_NOTATION_HPP
