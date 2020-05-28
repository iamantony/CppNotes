#ifndef CPPNOTESMAIN_UNIQUE_WORDS_ABBREVIATION_HPP
#define CPPNOTESMAIN_UNIQUE_WORDS_ABBREVIATION_HPP

/*
https://leetcode.com/problems/unique-word-abbreviation/
An abbreviation of a word follows the form <first letter><number><last letter>. Below are some
examples of word abbreviations:

a) it                      --> it    (no abbreviation)

     1
     ↓
b) d|o|g                   --> d1g

              1    1  1
     1---5----0----5--8
     ↓   ↓    ↓    ↓  ↓
c) i|nternationalizatio|n  --> i18n

              1
     1---5----0
     ↓   ↓    ↓
d) l|ocalizatio|n          --> l10n

Assume you have a dictionary and given a word, find whether its abbreviation is unique in the
dictionary. A word's abbreviation is unique if no other word from the dictionary has the same
abbreviation.

Example:
Given dictionary = [ "deer", "door", "cake", "card" ]
isUnique("dear") -> false
isUnique("cart") -> true
isUnique("cane") -> false
isUnique("make") -> true
*/

#include <string>
#include <vector>
#include <unordered_map>

namespace Algo::DS::HashMap {
    class ValidWordAbbr {
        std::unordered_map<std::string, std::string> m_abbreviations;

        std::string create_abbreviation(const std::string& str) {
            if (str.size() < 3) { return str; }

            return str.front() + std::to_string(str.size() - 2) + str.back();
        }

    public:
        explicit ValidWordAbbr(std::vector<std::string>& dictionary) {
            for (const auto& str : dictionary) {
                const auto abbreviation = create_abbreviation(str);
                const auto iter = m_abbreviations.find(abbreviation);
                if (iter == m_abbreviations.end()) {
                    m_abbreviations.insert({abbreviation, str});
                }
                else {
                    if (iter->second != str) {
                        iter->second.clear();
                    }
                }
            }
        }

        bool isUnique(std::string word) {
            const auto abbreviation = create_abbreviation(word);
            const auto iter = m_abbreviations.find(abbreviation);
            if (iter == m_abbreviations.end()) {
                return true;
            }
            else {
                if (iter->second == word) {
                    return true;
                }
            }

            return false;
        }
    };
}

#endif //CPPNOTESMAIN_UNIQUE_WORDS_ABBREVIATION_HPP
