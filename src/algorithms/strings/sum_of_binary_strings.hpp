#ifndef SUM_OF_BINARY_STRINGS_HPP
#define SUM_OF_BINARY_STRINGS_HPP

// https://leetcode.com/problems/add-binary/description/
// Given two binary strings, return their sum (also a binary string).
// For example,
// a = "11"
// b = "1"
// Return "100".

#include <string>
#include <list>

namespace SumOfBinaryStrings {

class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        if (a.empty() && b.empty()) {
            return std::string("0");
        }

        char ZERO = '0';
        char ONE = '1';

        std::list<char> sum;
        char carry = ZERO;
        while(!a.empty() || !b.empty()) {
            if (a.empty()) {
                if (carry == ONE) {
                    if (b.back() == ONE) {
                        sum.push_front(ZERO);
                    }
                    else {
                        sum.push_front(carry);
                        carry = ZERO;
                    }
                }
                else {
                    sum.push_front(b.back());
                }

                b.pop_back();
            }
            else if (b.empty()) {
                if (carry == ONE) {
                    if (a.back() == ONE) {
                        sum.push_front(ZERO);
                    }
                    else {
                        sum.push_front(carry);
                        carry = ZERO;
                    }
                }
                else {
                    sum.push_front(a.back());
                }

                a.pop_back();
            }
            else {
                if (a.back() == ZERO && b.back() == ZERO) {
                    sum.push_front(carry);
                    carry = ZERO;
                }
                else if ((a.back() == ONE && b.back() == ZERO) ||
                         (a.back() == ZERO && b.back() == ONE)) {
                    if (carry == ONE) {
                        sum.push_front(ZERO);
                    }
                    else {
                        sum.push_front(ONE);
                    }
                }
                else {
                    if (carry == ONE) {
                        sum.push_front(ONE);
                    }
                    else {
                        sum.push_front(ZERO);
                    }

                    carry = ONE;
                }

                a.pop_back();
                b.pop_back();
            }
        }

        if (carry == ONE) {
            sum.push_front(ONE);
        }

        std::string result;
        for (const char& bit : sum) {
            result.push_back(bit);
        }

        return result;
    }
};

}

#endif // SUM_OF_BINARY_STRINGS_HPP
