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

namespace ValidAnagram {

class Solution {
public:
    bool isAnagram(string s, string t) {
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        return s == t;
    }
};

}

#endif // TWO_STRINGS_ARE_VALID_ANAGRAM_HPP
