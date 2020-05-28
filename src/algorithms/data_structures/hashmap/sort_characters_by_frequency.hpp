#ifndef SORT_CHARACTERS_BY_FREQUENCY_HPP
#define SORT_CHARACTERS_BY_FREQUENCY_HPP

/*
https://leetcode.com/problems/sort-characters-by-frequency/
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:
Input:
"tree"
Output:
"eert"
Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

Example 2:
Input:
"cccaaa"
Output:
"cccaaa"
Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.

Example 3:
Input:
"Aabb"
Output:
"bbAa"
Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/

#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>

namespace Algo::DS::HashMap {
    class SortByFrequency {
    public:
        static std::string sort(const std::string& s) {
            std::unordered_map<char, size_t> chars_map;
            for (const auto& c : s) { ++chars_map[c]; }

            std::multimap<size_t, char> count_map;
            for (const auto& [c, num] : chars_map) { count_map.insert({num, c}); }

            std::string result;
            for (const auto& [num, c] : count_map) {
                result += std::string(num, c);
            }

            std::reverse(result.begin(), result.end());
            return result;
        }
    };
}

#endif //SORT_CHARACTERS_BY_FREQUENCY_HPP
