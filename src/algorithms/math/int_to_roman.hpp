#ifndef INT_TO_ROMAN_HPP
#define INT_TO_ROMAN_HPP

// https://leetcode.com/problems/integer-to-roman/description/

/*
Roman numerals are represented by seven different symbols:
I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example, two is written as II in Roman numeral, just two one's added
together. Twelve is written as, XII, which is simply X + II. The number
twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right.
However, the numeral for four is not IIII. Instead, the number four is written
as IV. Because the one is before the five we subtract it making four. The same
 principle applies to the number nine, which is written as IX. There are six
instances where subtraction is used:

- I can be placed before V (5) and X (10) to make 4 and 9.
- X can be placed before L (50) and C (100) to make 40 and 90.
- C can be placed before D (500) and M (1000) to make 400 and 900.

Given an integer, convert it to a roman numeral. Input is guaranteed to be
within the range from 1 to 3999.

Example 1: Input: 3, Output: "III"
Example 2: Input: 4, Output: "IV"
Example 3: Input: 9, Output: "IX"
Example 4: Input: 58, Output: "LVIII"
Explanation: C = 100, L = 50, XXX = 30 and III = 3.

Example 5: Input: 1994, Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/

#include <list>
#include <string>
#include <iostream>

namespace Algo::Math {

class IntToRoman {
public:
    static std::string Convert(int value) {
        if (value < 1 || value >= 4000) {
            return std::string();
        }

        const std::list<std::pair<int, std::string>> numMap = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
            {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"},
            {4, "IV"}, {1, "I"}
        };

        std::string result;
        int divider = 1000;
        auto nmIter = numMap.cbegin();
        while (value > 0) {
            int num = value / divider;
            if (num > 0)
            {
                int fullDigit = num * divider;
                while(fullDigit > 0) {
                    // Find first number in numMap that is <= than fullDigit
                    while(nmIter != numMap.cend() &&
                          fullDigit / nmIter->first == 0) {
                        ++nmIter;
                    }

                    result += nmIter->second;
                    fullDigit -= nmIter->first;
                }
            }

            value = value % divider;
            divider /= 10;
        }

        return result;
    }

    static std::string ConvertSimple(int value) {
        if (value < 1 || value >= 4000) {
            return std::string();
        }

        const std::string thousands[] = {"", "M", "MM", "MMM"};
        const std::string hundreds[] = {"", "C", "CC", "CCC", "CD", "D",
                                        "DC", "DCC", "DCCC", "CM", "M"};

        const std::string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX",
                                    "LXX", "LXXX", "XC"};

        const std::string ones[] = {"", "I", "II", "III", "IV", "V", "VI",
                                    "VII", "VIII", "IX"};

        return thousands[value/1000] + hundreds[(value/100) % 10] +
                tens[(value/10) % 10] + ones[value % 10];
    }
};

}

#endif // INT_TO_ROMAN_HPP
