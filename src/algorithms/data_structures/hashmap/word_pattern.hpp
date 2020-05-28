#ifndef WORD_PATTERN_HPP
#define WORD_PATTERN_HPP

/*
https://leetcode.com/problems/word-pattern/
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a
non-empty word in str.

Example 1:
Input: pattern = "abba", str = "dog cat cat dog"
Output: true

Example 2:
Input:pattern = "abba", str = "dog cat cat fish"
Output: false

Example 3:
Input: pattern = "aaaa", str = "dog cat cat dog"
Output: false

Example 4:
Input: pattern = "abba", str = "dog dog dog dog"
Output: false

Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters that
may be separated by a single space.
*/

#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>

namespace Algo::DS::HashMap {
    class WordPattern {
    public:
        static bool check(const std::string& pattern, const std::string& str) {
            size_t start_pos = 0;
            auto get_next_word = [&start_pos](const std::string_view& input)
            {
                if (start_pos >= input.size()) { return std::string_view(); }

                auto word_end = input.find(' ', start_pos);
                if (word_end == std::string_view::npos) { word_end = input.size(); }

                const auto result = input.substr(start_pos, word_end - start_pos);
                start_pos = word_end + 1;
                return result;
            };

            std::unordered_map<char, std::string_view> patterns_map;
            std::unordered_set<std::string_view> known_words;
            for (const auto& c : pattern) {
                const auto next_word = get_next_word(str);
                if (next_word.empty()) { return false; }

                if (patterns_map.count(c) == 0) {
                    if (known_words.count(next_word) > 0)  { return false; }

                    patterns_map[c] = next_word;
                    known_words.insert(next_word);
                }
                else if (patterns_map[c] != next_word) {
                    return false;
                }
            }

            if (start_pos < str.size()) { return false; }

            return true;
        }
    };
}

#endif //WORD_PATTERN_HPP
