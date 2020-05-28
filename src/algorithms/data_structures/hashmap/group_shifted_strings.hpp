#ifndef CPPNOTESMAIN_GROUP_SHIFTED_STRINGS_HPP
#define CPPNOTESMAIN_GROUP_SHIFTED_STRINGS_HPP

/*
https://leetcode.com/problems/group-shifted-strings/
Given a string, we can "shift" each of its letter to its successive letter, for example:
"abc" -> "bcd". We can keep "shifting" which forms the sequence:

"abc" -> "bcd" -> ... -> "xyz"

Given a list of strings which contains only lowercase alphabets, group all strings that belong
to the same shifting sequence.

Example:
Input: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],
Output:
[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]
*/

#include <unordered_map>
#include <vector>

namespace Algo::DS::HashMap {
    class ShiftedStrings {
        std::unordered_map<std::string, std::vector<std::string>> m_groups;

        std::string get_base(std::string str) {
            if (str.empty()) { return {}; }

            const auto distance = str.front() - 'a';
            for (auto& c : str) {
                const auto c_distance = c - 'a';
                if (c_distance >= distance) {
                    c -= distance;
                }
                else {
                    const auto shift = distance - c_distance - 1;
                    c = 'z' - shift;
                }
            }

            return str;
        }

    public:
        std::vector<std::vector<std::string>> group(const std::vector<std::string>& strings) {
            for (const auto& str : strings) {
                const auto base = get_base(str);
                m_groups[base].push_back(str);
            }

            std::vector<std::vector<std::string>> result;
            for (const auto& [_, group] : m_groups) {
                result.push_back(group);
            }

            return result;
        }
    };
}

#endif //CPPNOTESMAIN_GROUP_SHIFTED_STRINGS_HPP
