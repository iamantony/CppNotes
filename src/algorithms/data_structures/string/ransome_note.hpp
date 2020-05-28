#ifndef RANSOME_NOTE_HPP_
#define RANSOME_NOTE_HPP_

/*
https://leetcode.com/problems/ransom-note/
Given an arbitrary ransom note string and another string containing letters from all the magazines,
write a function that will return true if the ransom note can be constructed from the magazines;
otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Example 1:
Input: ransomNote = "a", magazine = "b"
Output: false

Example 2:
Input: ransomNote = "aa", magazine = "ab"
Output: false

Example 3:
Input: ransomNote = "aa", magazine = "aab"
Output: true

Constraints:
You may assume that both strings contain only lowercase letters.
*/
#include <string>
#include <unordered_map>

namespace Algo::DS::String {
    bool isStrFormedFromStr(const std::string& str, const std::string& source)
    {
        if (str.empty()) { return true; }
        if (source.empty()) { return false; }

        std::unordered_map<char, int> map;
        for (const char& ch : str) {
            if (map.end() == map.find(ch)) {
                map[ch] = 0;
            }

            ++map[ch];
        }

        for (const char& ch : source) {
            std::unordered_map<char, int>::iterator it = map.find(ch);
            if (it == map.end()) { continue; }

            --(it->second);
            if (it->second <= 0) {
                map.erase(it);
                if (map.empty()) { return true; }
            }
        }

        return false;
    }
}

#endif /* RANSOME_NOTE_HPP_ */
