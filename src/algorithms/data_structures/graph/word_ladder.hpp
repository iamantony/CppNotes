#ifndef CPPNOTESMAIN_WORD_LADDER_HPP
#define CPPNOTESMAIN_WORD_LADDER_HPP

/*
https://leetcode.com/problems/word-ladder/

Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest
transformation sequence from beginWord to endWord, such that:
- Only one letter can be changed at a time.
- Each transformed word must exist in the word list.

Note:
- Return 0 if there is no such transformation sequence.
- All words have the same length.
- All words contain only lowercase alphabetic characters.
- You may assume no duplicates in the word list.
- You may assume beginWord and endWord are non-empty and are not the same.

Example 1:
Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Example 2:
Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
*/

#include <string>
#include <vector>

namespace Algo::DS::Graph {
    class WordLadder {
        static const int NOT_FOUND = 0;

        static int find_min_changes(
            const std::string& word,
            const std::string& end_word,
            const std::vector<std::string>& words_dict,
            std::vector<bool> used_words,
            const int count)
        {
            if (word == end_word) { return count; }

            int res_count = std::numeric_limits<int>::max();
            for (size_t i = 0; i < words_dict.size(); ++i) {
                if (used_words[i] || word.size() != words_dict.at(i).size()) { continue; }

                size_t diff_chars = 0;
                for (size_t c = 0; c < word.size(); ++c) {
                    if (word[c] != words_dict.at(i).at(c)) { ++diff_chars; }
                }

                if (diff_chars != 1) { continue; }

                auto new_used_words = used_words;
                new_used_words[i] = true;
                const auto new_count = find_min_changes(
                    words_dict.at(i), end_word, words_dict, std::move(new_used_words), count + 1);
                if (new_count > count) {
                    res_count = std::min(res_count, new_count);
                }
            }

            return (res_count < std::numeric_limits<int>::max() && res_count > count) ?
                res_count : NOT_FOUND;
        }

    public:
        static int find_min_steps_naive(
            const std::string& begin_word,
            const std::string& end_word,
            const std::vector<std::string>& words_dict)
        {
            if (begin_word == end_word || words_dict.empty()) { return NOT_FOUND; }

            std::vector<bool> used_words(words_dict.size(), false);
            return find_min_changes(begin_word, end_word, words_dict, used_words, 1);
        }
    };
}

#endif //CPPNOTESMAIN_WORD_LADDER_HPP
