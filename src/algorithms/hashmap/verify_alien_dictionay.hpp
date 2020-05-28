#ifndef CPPNOTESMAIN_VERIFY_ALIEN_DICTIONAY_HPP
#define CPPNOTESMAIN_VERIFY_ALIEN_DICTIONAY_HPP

/*
https://leetcode.com/problems/verifying-an-alien-dictionary/
In an alien language, surprisingly they also use english lowercase letters, but possibly in a
different order. The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet,
return true if and only if the given words are sorted lexicographicaly in this alien language.

Example 1:
Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.

Example 2:
Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence
is unsorted.

Example 3:
Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size).
According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as
the blank character which is less than any other character (More info).

Constraints:
- 1 <= words.length <= 100
- 1 <= words[i].length <= 20
- order.length == 26
- All characters in words[i] and order are English lowercase letters.
*/

#include <string>
#include <vector>
#include <unordered_map>

namespace Algo::HashMap {
    class AlienDictionary {
    public:
        bool isAlienSorted(std::vector<std::string>& words, std::string order) {
            if (words.size() < 2) { return true; }

            std::unordered_map<char, size_t> m_alphabet;
            for (size_t i = 0; i < order.size(); ++i) {
                m_alphabet[order[i]] = i;
            }

            for (size_t i = 1; i < words.size(); ++i) {
                auto& w1 = words[i - 1];
                auto& w2 = words[i];

                const auto max_length = std::max(w1.size(), w2.size());
                for (size_t j = 0; j < max_length; ++j) {
                    if (w1.size() <= j) { break; }
                    if (w2.size() <= j) { return false; }
                    if (m_alphabet[w1[j]] < m_alphabet[w2[j]]) { break; }
                    if (m_alphabet[w1[j]] > m_alphabet[w2[j]]) { return false; }
                }
            }

            return true;
        }
    };
}

#endif //CPPNOTESMAIN_VERIFY_ALIEN_DICTIONAY_HPP
