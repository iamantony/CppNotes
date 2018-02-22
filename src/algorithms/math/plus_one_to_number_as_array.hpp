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

namespace PlusOne {

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        if (digits.empty()) {
            return std::vector<int>();
        }

        bool carry = false;
        for (size_t i = digits.size() - 1; ; --i) {
            if (digits[i] == 9) {
                digits[i] = 0;
                carry = true;
            }
            else {
                digits[i] += 1;
                carry = false;
                break;
            }

            if (i == 0) {
                break;
            }
        }

        std::vector<int> result;
        if (carry) {
            result.push_back(1);
            result.insert(result.end(), digits.begin(), digits.end());
        }
        else {
            result = digits;
        }

        return result;
    }
};

}

#endif // PLUS_ONE_TO_NUMBER_AS_ARRAY_HPP
