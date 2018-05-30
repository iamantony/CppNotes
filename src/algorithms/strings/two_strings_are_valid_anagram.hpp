#ifndef TWO_STRINGS_ARE_VALID_ANAGRAM_HPP
#define TWO_STRINGS_ARE_VALID_ANAGRAM_HPP

// https://leetcode.com/problems/valid-anagram/description/

// Given two strings s and t, write a function to determine if t is an anagram
// of s.

// For example,
// s = "anagram", t = "nagaram", return true.
// s = "rat", t = "car", return false.

// Note:
// You may assume the string contains only lowercase alphabets.

// Follow up:
// What if the inputs contain unicode characters? How would you adapt your
// solution to such case?

#include <string>
#include <algorithm>
#include <locale>

namespace ValidAnagram {

class Solution {
public:
    static bool isAnagram(const std::string& s, const std::string& t) {
        std::locale locale("C");

        auto predicate = [&locale](const char& ch) ->bool {
            return std::isalnum(ch, locale);
        };

        std::string sCleaned, tCleaned;
        std::copy_if(s.begin(), s.end(), std::back_inserter(sCleaned), predicate);
        std::copy_if(t.begin(), t.end(), std::back_inserter(tCleaned), predicate);

        std::sort(sCleaned.begin(), sCleaned.end());
        std::sort(tCleaned.begin(), tCleaned.end());
        return sCleaned == tCleaned;
    }
};

}

#endif // TWO_STRINGS_ARE_VALID_ANAGRAM_HPP
