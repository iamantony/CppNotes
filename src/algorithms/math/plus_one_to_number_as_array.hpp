#ifndef PLUS_ONE_TO_NUMBER_AS_ARRAY_HPP
#define PLUS_ONE_TO_NUMBER_AS_ARRAY_HPP

// https://leetcode.com/problems/plus-one/description/

// Given a non-negative integer represented as a non-empty array of digits,
// plus one to the integer.
// You may assume the integer do not contain any leading zero, except the
// number 0 itself.
// The digits are stored such that the most significant digit is at the head
// of the list.

#include <vector>
#include <algorithm>

namespace Algo::Math {

class PlusOneToVector {
public:
    static std::vector<int> Add(const std::vector<int>& digits) {
        if (digits.empty()) {
            return std::vector<int>();
        }

        std::vector<int> result;
        int carry = 1;
        for (size_t i = digits.size() - 1; ; --i) {
            int valueToAdd = digits[i];
            if (carry > 0) {
                if (digits[i] == 9) {
                    valueToAdd = 0;
                }
                else {
                    valueToAdd += carry;
                    carry = 0;
                }
            }

            result.push_back(valueToAdd);

            if (i == 0) {
                break;
            }
        }

        if (carry > 0) {
            result.push_back(carry);
            carry = 0;
        }

        // Remove unnecessary zeros
        size_t pos = result.size() - 1;
        for (; result[pos] == 0; --pos);
        result.resize(pos + 1);

        std::reverse(result.begin(), result.end());

        return result;
    }
};
}

#endif // PLUS_ONE_TO_NUMBER_AS_ARRAY_HPP
