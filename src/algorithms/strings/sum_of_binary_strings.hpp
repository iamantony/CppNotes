#ifndef SUM_OF_BINARY_STRINGS_HPP
#define SUM_OF_BINARY_STRINGS_HPP

// https://leetcode.com/problems/add-binary/description/
// Given two binary strings, return their sum (also a binary string).
// For example,
// a = "11"
// b = "1"
// Return "100".

#include <string>
#include <stack>

namespace Algo::Strings {

class AddBinaryStrings {
public:
    static std::string Add(const std::string& a, const std::string& b) {
        if (a.empty() && b.empty()) {
            return std::string("0");
        }

        std::stack<char> sum;
        int carry = 0;
        int aIter = static_cast<int>(a.size()) - 1;
        int bIter = static_cast<int>(b.size()) - 1;
        const char ZERO = '0', ONE = '1';
        for (; aIter >= 0 || bIter >= 0 || carry > 0; --aIter, --bIter) {
            int bitSum = carry;
            if (aIter >= 0) {
                bitSum += a[static_cast<size_t>(aIter)] - ZERO;
            }

            if (bIter >= 0) {
                bitSum += b[static_cast<size_t>(bIter)] - ZERO;
            }

            carry = bitSum > 1 ? 1 : 0;
            char bit = ZERO;
            if (bitSum == 1 || bitSum == 3) {
                bit = ONE;
            }

            sum.push(bit);
        }

        std::string result;
        while(!sum.empty()) {
            result.push_back(sum.top());
            sum.pop();
        }

        return result;
    }
};

}

#endif // SUM_OF_BINARY_STRINGS_HPP
