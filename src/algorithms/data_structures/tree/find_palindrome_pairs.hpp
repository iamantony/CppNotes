#ifndef CPPNOTESMAIN_FIND_PALINDROME_PAIRS_HPP
#define CPPNOTESMAIN_FIND_PALINDROME_PAIRS_HPP

/*
https://leetcode.com/problems/palindrome-pairs/
Given a list of unique words, return all the pairs of the distinct indices (i, j) in the given
list, so that the concatenation of the two words words[i] + words[j] is a palindrome.

Example 1:
Input: words = ["abcd","dcba","lls","s","sssll"]
Output: [[0,1],[1,0],[3,2],[2,4]]
Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]

Example 2:
Input: words = ["bat","tab","cat"]
Output: [[0,1],[1,0]]
Explanation: The palindromes are ["battab","tabbat"]

Example 3:
Input: words = ["a",""]
Output: [[0,1],[1,0]]

Constraints:
* 1 <= words.length <= 5000
* 0 <= words[i].length <= 300
* words[i] consists of lower-case English letters.
*/

#include <vector>
#include <string>
#include <unordered_map>
#include <limits>
#include <algorithm>

namespace Algo::DS::Tree {
    class FindPalindromePairs {
        static const size_t INVALID_POS = std::numeric_limits<size_t>::max();
        struct Node {
            size_t pos = INVALID_POS;
            std::unordered_map<char, Node*> map;

            ~Node() {
                for (auto iter = map.begin(); iter != map.end(); ++iter) {
                    delete iter->second;
                }
            }
        };

        Node root;
        std::vector<std::string> w;

        void insert_word(size_t pos) {
            Node* node = &root;
            const auto& word = w[pos];
            for (const auto& c : word) {
                if (node->map.count(c) == 0) {
                    node->map[c] = new Node();
                }

                node = node->map[c];
            }

            node->pos = pos;
        }

        size_t find_word(const std::string& word) const {
            auto node = &root;
            if (word.empty()) { return node->pos; }

            for (const auto& c : word) {
                auto iter = node->map.find(c);
                if (iter == node->map.end()) { return INVALID_POS; }

                node = iter->second;
            }

            return node->pos;
        }

        bool is_palindrome(const std::string& s) const {
            if (s.size() < 2) { return true; }

            auto mid = s.size() / 2;
            auto left = mid - 1;
            auto right = s.size() % 2 == 0 ? mid: mid + 1;
            for (; right < s.size(); --left, ++right) {
                if (s.at(left) != s.at(right)) { return false; }
            }

            return true;
        }

        std::vector<std::vector<int>> find_from_beginning(const size_t word_pos) const {
            auto rev_word = w[word_pos];
            std::reverse(rev_word.begin(), rev_word.end());

            size_t chars_to_delete = 0;
            std::vector<std::vector<int>> pairs;
            while (true) {
                auto beginning = rev_word;
                beginning.resize(rev_word.size() - chars_to_delete);

                if (is_palindrome(beginning + w[word_pos])) {
                    auto pos = find_word(beginning);
                    if (pos != INVALID_POS && pos != word_pos) {
                        pairs.push_back({static_cast<int>(pos), static_cast<int>(word_pos)}); }
                }

                ++chars_to_delete;
                if (beginning.size() == 0) { break; }
            }

            return pairs;
        }

        std::vector<std::vector<int>> find_from_end(const size_t word_pos) const {
            auto rev_word = w[word_pos];
            std::reverse(rev_word.begin(), rev_word.end());

            size_t skip_chars_num = 0;
            std::vector<std::vector<int>> pairs;
            while (true) {
                auto end = rev_word.substr(skip_chars_num);
                if (is_palindrome(w[word_pos] + end)) {
                    auto pos = find_word(end);
                    if (pos != INVALID_POS && pos != word_pos) {
                        pairs.push_back({static_cast<int>(word_pos), static_cast<int>(pos)});
                    }
                }

                ++skip_chars_num;
                if (end.size() == 0) { break; }
            }

            return pairs;
        }

    public:
        std::vector<std::vector<int>> find(std::vector<std::string>& words) {
            w = words;
            for (size_t i = 0; i < w.size(); ++i) {
                insert_word(i);
            }

            std::vector<std::vector<int>> pairs;
            for (size_t i = 0; i < w.size(); ++i) {
                const auto beg_pairs = find_from_beginning(i);
                const auto end_pairs = find_from_end(i);

                pairs.insert(pairs.end(), beg_pairs.begin(), beg_pairs.end());
                pairs.insert(pairs.end(), end_pairs.begin(), end_pairs.end());
            }

            std::sort(
                pairs.begin(),
                pairs.end(),
                [](const auto& left, const auto& right) {
                    if (left[0] == right[0]) {
                        return left[1] < right[1];
                    }

                    return left[0] < right[0];
                });

            auto last_iter = std::unique(pairs.begin(), pairs.end());
            pairs.erase(last_iter, pairs.end());
            return pairs;
        }
    };
}

#endif //CPPNOTESMAIN_FIND_PALINDROME_PAIRS_HPP
