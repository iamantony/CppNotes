#ifndef CPPNOTESMAIN_GENERATE_POSSIBLE_LETTER_COMBINATIONS_OF_PHONE_NUMBER_HPP
#define CPPNOTESMAIN_GENERATE_POSSIBLE_LETTER_COMBINATIONS_OF_PHONE_NUMBER_HPP

/*
https://leetcode.com/problems/letter-combinations-of-a-phone-number/
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that
the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below.
Note that 1 does not map to any letters.

Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:
Input: digits = ""
Output: []

Example 3:
Input: digits = "2"
Output: ["a","b","c"]

Constraints:
- 0 <= digits.length <= 4
- digits[i] is a digit in the range ['2', '9'].
*/

#include <vector>
#include <string>

class LetterCombinationsOfPhoneNumber {
    const std::vector<std::vector<char>> map = {
        {},
        {},
        {'a', 'b','c'},
        {'d', 'e','f'},
        {'g', 'h','i'},
        {'j', 'k','l'},
        {'m', 'n','o'},
        {'p', 'q','r', 's'},
        {'t', 'u','v'},
        {'w', 'x','y', 'z'},
    };

    void construct(
        const std::vector<const std::vector<char>*>& combos,
        const size_t combo_pos,
        const std::string& str,
        std::vector<std::string>& result)
    {
        if (combo_pos >= combos.size()) {
            result.push_back(str);
            return;
        }

        for (size_t i = 0; i < combos[combo_pos]->size(); ++i) {
            auto s = str + combos[combo_pos]->at(i);
            construct(combos, combo_pos + 1, s, result);
        }
    }

public:
    std::vector<std::string> generate_all_possible_combinations(const std::string& digits) {
        if (digits.empty()) { return {}; }

        std::vector<std::string> result;
        std::vector<const std::vector<char>*> combos;
        for (const auto& d : digits) {
            const auto num = static_cast<size_t>(d - '0');
            combos.push_back(&(map.at(num)));
        }

        construct(combos, 0, {}, result);
        return result;
    }
};

#endif //CPPNOTESMAIN_GENERATE_POSSIBLE_LETTER_COMBINATIONS_OF_PHONE_NUMBER_HPP
