#ifndef STR_TO_INTEGER_HPP
#define STR_TO_INTEGER_HPP

// https://leetcode.com/problems/string-to-integer-atoi/description/

// Implement atoi to convert a string to an integer.
// Hint: Carefully consider all possible input cases. If you want a challenge,
// please do not see below and ask yourself what are the possible input cases.

// Notes: It is intended for this problem to be specified vaguely (ie, no given
// input specs). You are responsible to gather all the input requirements up
// front.

// Requirements for atoi:
// The function first discards as many whitespace characters as necessary
// until the first non-whitespace character is found. Then, starting from this
// character, takes an optional initial plus or minus sign followed by as many
// numerical digits as possible, and interprets them as a numerical value.

// The string can contain additional characters after those that form the
// integral number, which are ignored and have no effect on the behavior of
// this function.

// If the first sequence of non-whitespace characters in str is not a valid
// integral number, or if no such sequence exists because either str is empty
// or it contains only whitespace characters, no conversion is performed.

// If no valid conversion could be performed, a zero value is returned.
// If the correct value is out of the range of representable values,
// INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

#include <string>
#include <locale>
#include <limits>

namespace Algo::DS::String {
    class StrToInt {
    public:
        int myAtoi(std::string str) {
            long int result = 0;
            long int sign = 1;
            bool inConvertion = false;
            for (size_t i = 0; i < str.size(); ++i) {

                if (str[i] == ' ') {
                    // skip whitespace at the beginning of the string
                    if (!inConvertion) {
                        continue;
                    }
                    else {
                        // whitespace in the middle of the number - stop conversion
                        break;
                    }
                }
                else if (str[i] == '-') {
                    // set up sign of the number
                    if (!inConvertion) {
                        sign = -1;
                        inConvertion = true;
                    }
                    else {
                        // 'minus' in the middle of the number - stop conversion
                        break;
                    }
                }
                else if (str[i] == '+') {
                    // set up sign of the number
                    if (!inConvertion) {
                        inConvertion = true;
                    }
                    else {
                        // 'plus' in the middle of the number - stop conversion
                        break;
                    }
                }
                else if (std::isdigit(str[i])) {
                    inConvertion = true;
                    int digit = str[i] - '0';
                    result = result * 10 + digit;

                    // overflow detection
                    if (result > std::numeric_limits<int>::max()) {
                        return (sign > 0) ? std::numeric_limits<int>::max() :
                                            std::numeric_limits<int>::min();
                    }
                }
                else {
                    break;
                }
            }

            return static_cast<int>(result * sign);
        }
    };
}

#endif // STR_TO_INTEGER_HPP
