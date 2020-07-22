#ifndef CPPNOTESMAIN_REARRANGE_STRING_WITH_K_DISTANCE_HPP
#define CPPNOTESMAIN_REARRANGE_STRING_WITH_K_DISTANCE_HPP

/*
https://leetcode.com/problems/rearrange-string-k-distance-apart/
Given a non-empty string s and an integer k, rearrange the string such that the same characters are
at least distance k from each other.

All input strings are given in lowercase letters. If it is not possible to rearrange the string,
return an empty string "".

Example 1:
Input: s = "aabbcc", k = 3
Output: "abcabc"
Explanation: The same letters are at least distance 3 from each other.

Example 2:
Input: s = "aaabc", k = 3
Output: ""
Explanation: It is not possible to rearrange the string.

Example 3:
Input: s = "aaadbbcc", k = 2
Output: "abacabcd"
Explanation: The same letters are at least distance 2 from each other.
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

namespace Algo::DS::String {
    class RearrangeStringWithKDistance {
        static std::vector<std::pair<char, size_t>> create_freq_vec(const std::string& s) {
            std::unordered_map<char, size_t> count_map;
            for (const auto& c : s) {
                ++count_map[c];
            }

            std::vector<std::pair<char, size_t>> freq_vec;
            for (const auto& [t, c] : count_map) {
                freq_vec.push_back({t, c});
            }

            return freq_vec;
        }

        static void update_freq_vec(std::vector<std::pair<char, size_t>>& freq_vec) {
            std::sort(
                freq_vec.begin(),
                freq_vec.end(),
                [](const auto& left, const auto& right){ return left.second > right.second; });

            const auto zero_iter = std::find_if(
                freq_vec.begin(),
                freq_vec.end(),
                [](const auto& pair){ return pair.second == 0; });

            freq_vec.erase(zero_iter, freq_vec.end());
        }

    public:
        static std::string rearrange(const std::string& s, const int k) {
            std::vector<std::pair<char, size_t>> freq_vec = create_freq_vec(s);
            update_freq_vec(freq_vec);

            const auto kk = static_cast<size_t>(k);
            std::unordered_map<char, size_t> pos_map;
            std::string result;
            result.reserve(s.size());
            while (!freq_vec.empty()) {
                size_t distance = 0;
                size_t char_index = freq_vec.size();
                const size_t next_pos = result.size();
                for (size_t i = 0; i < freq_vec.size(); ++i) {
                    auto& char_item = freq_vec[i];
                    if (pos_map.count(char_item.first) == 0) {
                        distance = kk;
                        char_index = i;
                        break;
                    }

                    const auto char_distance = next_pos - pos_map[char_item.first] - 1;
                    if (char_distance >= distance) {
                        distance = char_distance;
                        char_index = i;
                        if (distance >= kk) {
                            break;
                        }
                    }
                }

                if (distance < kk) { return {}; }

                auto& char_item = freq_vec[char_index];
                result += char_item.first;
                --char_item.second;
                pos_map[char_item.first] = result.size() - 1;
                update_freq_vec(freq_vec);
            }

            return result;
        }

        static std::string rearrange_pq(std::string& s, const int k) {
            std::vector<int> freq_vec(26, 0);
            for (const auto& c : s) {
                const auto index = static_cast<size_t>(c - 'a');
                ++freq_vec[index];
            }

            std::priority_queue<std::pair<size_t, char>> pq;
            for (size_t i = 0; i < freq_vec.size(); ++i) {
                if (freq_vec[i] > 0) {
                    pq.push({freq_vec[i], 'a' + i});
                }
            }

            std::queue<std::pair<std::pair<size_t, char>, size_t>> q;
            size_t pos = 0;
            const auto kk = static_cast<size_t>(k);
            while (!pq.empty() || !q.empty()) {
                while (!q.empty()) {
                    if (pos - q.front().second >= kk) {
                        pq.push(q.front().first);
                        q.pop();
                    }
                    else {
                        break;
                    }
                }

                if (pq.empty()) { return {}; }

                const auto [count, c] = pq.top();
                pq.pop();

                s[pos] = c;
                ++pos;

                if (count > 1) {
                    q.push({{count - 1, c}, pos - 1});
                }
            }

            return s;
        }
    };
}

#endif //CPPNOTESMAIN_REARRANGE_STRING_WITH_K_DISTANCE_HPP
