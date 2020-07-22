#ifndef CPPNOTESMAIN_REORGANIZE_STRING_NO_TWO_SIMILAR_ADJACENT_CHARS_HPP
#define CPPNOTESMAIN_REORGANIZE_STRING_NO_TWO_SIMILAR_ADJACENT_CHARS_HPP

/*
https://leetcode.com/problems/reorganize-string/
Given a string S, check if the letters can be rearranged so that two characters that are adjacent
to each other are not the same.

If possible, output any possible result.  If not possible, return the empty string.

Example 1:
Input: S = "aab"
Output: "aba"

Example 2:
Input: S = "aaab"
Output: ""

Note:
- S will consist of lowercase letters and have length in range [1, 500].
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

namespace Algo::DS::String {
    class ReorganizeString {
    public:
        static std::string no_two_similar_adjacent_chars(const std::string& s) {
            std::unordered_map<char, size_t> freq_map;
            for (const auto& c : s) { ++freq_map[c]; }

            std::priority_queue<std::pair<size_t, char>> pq;
            for (const auto& [c, count] : freq_map) { pq.push({count, c}); }

            std::string result;
            result.reserve(s.size());
            while (!pq.empty()) {
                auto top = pq.top();
                pq.pop();

                result += top.second;
                --top.first;
                if (pq.empty() && top.first > 0) { return {}; }
                if (pq.empty()) { break; }

                auto next_top = pq.top();
                pq.pop();

                result += next_top.second;
                --next_top.first;

                if (next_top.first > 0) { pq.push(next_top); }
                if (top.first > 0) { pq.push(top); }
            }

            return result;
        }

        static std::string no_two_similar_adjacent_chars_quick(std::string& s) {
            std::vector<size_t> freq_map(26,0);
            size_t max_freq = 0;
            size_t idx = 0;
            for (size_t i = 0; i < s.size(); i++){
                auto char_index = static_cast<size_t>(s[i] - 'a');
                ++freq_map[char_index];
                if (freq_map[char_index] > max_freq) {
                    max_freq = freq_map[char_index];
                    idx = char_index;
                }
            }

            // Hint: for example s.size() == 5 and 'a' has max frequency == 3. It means that result
            // string would be "a.a.a" where '.' - some other char. Number of dots == freq of a - 1
            if (max_freq * 2 - 1 > s.size()) { return {}; }

            size_t pos = 0;
            while (freq_map[idx] > 0) {
                s[pos] = static_cast<char>(idx) + 'a';
                --freq_map[idx];
                pos += 2;
            }

            for (size_t i = 0; i < 26; ++i) {
                while (freq_map[i] > 0) {
                    if (pos >= s.size()) { pos = 1; }

                    s[pos] = static_cast<char>(i) + 'a';
                    pos += 2;;
                    --freq_map[i];
                }
            }

            return s;
        }
    };
}

#endif //CPPNOTESMAIN_REORGANIZE_STRING_NO_TWO_SIMILAR_ADJACENT_CHARS_HPP
