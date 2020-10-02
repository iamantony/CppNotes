#ifndef CPPNOTESMAIN_FIND_MOST_COMMON_WORD_HPP
#define CPPNOTESMAIN_FIND_MOST_COMMON_WORD_HPP

/*
https://leetcode.com/problems/most-common-word/
Given a paragraph and a list of banned words, return the most frequent word that is not in the
list of banned words.  It is guaranteed there is at least one word that isn't banned, and that
the answer is unique.

Words in the list of banned words are given in lowercase, and free of punctuation.  Words in
the paragraph are not case sensitive.  The answer is in lowercase.

Example:
Input:
paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
banned = ["hit"]
Output: "ball"
Explanation:
"hit" occurs 3 times, but it is a banned word.
"ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph.

Note that words in the paragraph are not case sensitive,
that punctuation is ignored (even if adjacent to words, such as "ball,"),
and that "hit" isn't the answer even though it occurs more because it is banned.


Note:
- 1 <= paragraph.length <= 1000.
- 0 <= banned.length <= 100.
- 1 <= banned[i].length <= 10.
- The answer is unique, and written in lowercase (even if its occurrences in paragraph may have
uppercase symbols, and even if it is a proper noun.)
- paragraph only consists of letters, spaces, or the punctuation symbols !?',;.
- There are no hyphens or hyphenated words.
- Words only consist of letters, never apostrophes or other punctuation symbols.
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <strstream>
#include <cctype>

namespace Algo::DS::HashMap {
    class FindMostCommonWord {
        std::vector<std::string> split(const std::string& s, const char delimeter) {
            std::vector<std::string> result;
            std::istringstream iss(s);
            for (std::string word; std::getline(iss, word, delimeter); ) {
                if (!word.empty()) { result.push_back(word); }
            }

            return result;
        }

    public:
        std::string find(std::string paragraph, const std::vector<std::string>& banned_words) {
            for (auto& c : paragraph) {
                if (std::isalpha(c)) {
                    c = std::tolower(c);
                }
                else {
                    c = ' ';
                }
            }

            auto words = split(paragraph, ' ');
            std::unordered_map<std::string, size_t> words_map;
            for (auto& w : words) {
                ++words_map[w];
            }

            for (const auto& word : banned_words) {
                words_map[word] = 0;
            }

            std::string result;
            size_t max_count = 0;
            for (const auto& [w, c] : words_map) {
                if (max_count < c) {
                    max_count = c;
                    result = w;
                }
            }

            return result;
        }
    };
}

#endif //CPPNOTESMAIN_FIND_MOST_COMMON_WORD_HPP
