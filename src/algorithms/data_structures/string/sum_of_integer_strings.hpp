#ifndef CPPNOTESMAIN_SUM_OF_INTEGER_STRINGS_HPP
#define CPPNOTESMAIN_SUM_OF_INTEGER_STRINGS_HPP

/*
https://leetcode.com/problems/add-strings/
Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:
- The length of both num1 and num2 is < 5100.
- Both num1 and num2 contains only digits 0-9.
- Both num1 and num2 does not contain any leading zero.
- You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/

#include <string>
#include <algorithm>

namespace Algo::DS::String {
    class AddIntegerStrings {
    public:
        static std::string add(const std::string& num1, const std::string& num2) {
            const auto max_size = std::max(num1.size(), num2.size());
            std::reverse(num1.begin(), num1.end());
            std::reverse(num2.begin(), num2.end());

            std::string sum;
            char carry = 0;
            for (size_t i = 0; i < max_size; ++i) {
                char num = 0;
                if (i < num1.size() && i < num2.size()) {
                    num = (num1[i] - '0') + (num2[i] - '0') + carry;
                }
                else if (i < num1.size()) {
                    num = (num1[i] - '0') + carry;
                }
                else {
                    num = (num2[i] - '0') + carry;
                }

                carry = 0;
                if (num >= 10) {
                    num %= 10;
                    carry = 1;
                }

                num += '0';
                sum.push_back(num);
            }

            if (carry > 0) {
                sum.push_back('1');
            }

            std::reverse(sum.begin(), sum.end());
            return sum;
        }
    };
}

#endif //CPPNOTESMAIN_SUM_OF_INTEGER_STRINGS_HPP
