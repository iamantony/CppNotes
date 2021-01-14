#ifndef CPPNOTESMAIN_CONSTRUCT_WORD_SQUARES_HPP
#define CPPNOTESMAIN_CONSTRUCT_WORD_SQUARES_HPP

/*
https://leetcode.com/problems/word-squares/
Given a set of words (without duplicates), find all word squares you can build from them.

A sequence of words forms a valid word square if the kth row and column read the exact same string,
where 0 ≤ k < max(numRows, numColumns).

For example, the word sequence ["ball","area","lead","lady"] forms a word square because each word
reads the same both horizontally and vertically.

b a l l
a r e a
l e a d
l a d y

Note:
* There are at least 1 and at most 1000 words.
* All words will have the exact same length.
* Word length is at least 1 and at most 5.
* Each word contains only lowercase English alphabet a-z.

Example 1:
Input:
["area","lead","wall","lady","ball"]

Output:
[
  [ "wall",
    "area",
    "lead",
    "lady"
  ],
  [ "ball",
    "area",
    "lead",
    "lady"
  ]
]

Explanation:
The output consists of two word squares. The order of output does not matter (just the order of
words in each word square matters).

Example 2:
Input:
["abat","baba","atan","atal"]

Output:
[
  [ "baba",
    "abat",
    "baba",
    "atan"
  ],
  [ "baba",
    "abat",
    "baba",
    "atal"
  ]
]

Explanation:
The output consists of two word squares. The order of output does not matter (just the order of
words in each word square matters).
*/

#include <vector>
#include <string>
#include <unordered_map>
#include <limits>

namespace Algo::DS::Tree {
    class WordSquaresConstructor {
        struct Node {
            size_t dict_pos = std::numeric_limits<size_t>::max();
            std::unordered_map<char, Node*> map;
        };

        Node root;
        size_t max_word_size = 0;
        std::vector<std::string> dict;
        std::vector<std::vector<size_t>> squares;

        void insert_word(const size_t dict_pos) {
            Node* node = &root;
            const auto& w = dict[dict_pos];
            for (const auto& c : w) {
                if (node->map.count(c) == 0) {
                    node->map[c] = new Node();
                }

                node = node->map[c];
            }

            node->dict_pos = dict_pos;
        }

        void collect_words(Node* node, const std::string& s, std::vector<size_t>& v) {
            if (node->map.empty()) {
                v.push_back(node->dict_pos);
                return;
            }

            for (const auto [c, n] : node->map) {
                collect_words(n, s + c, v);
            }
        }

        std::vector<size_t> get_words_that_begin_with(const std::string& s) {
            Node* node = &root;
            for (const auto& c : s) {
                if (node->map.count(c) == 0) { return {}; }

                node = node->map[c];
            }

            std::vector<size_t> res;
            collect_words(node, s, res);
            return res;
        }

        void create_word_square(const std::vector<size_t>& ws, const std::string& prefix) {
            if (prefix.size() == max_word_size) {
                squares.push_back(ws);
                return;
            }

            const auto found_words = get_words_that_begin_with(prefix);
            for (const auto& fw : found_words) {
                auto new_ws = ws;
                new_ws.push_back(fw);

                const auto ind = prefix.size() + 1;
                std::string new_prefix;
                for (size_t r = 0; r < ind; ++r) {
                    new_prefix += dict[new_ws[r]][ind];
                }

                create_word_square(new_ws, new_prefix);
            }
        }

        std::vector<std::vector<std::string>> transform_squares() {
            std::vector<std::vector<std::string>> res;
            for (const auto& sq : squares) {
                std::vector<std::string> transformed(sq.size(), "");
                for (size_t i = 0; i < sq.size(); ++i) {
                    transformed[i] = dict[sq[i]];
                }

                res.push_back(transformed);
            }

            return res;
        }

    public:
        std::vector<std::vector<std::string>> construct(const std::vector<std::string>& words) {
            if (words.empty()) { return {}; }

            max_word_size = words.front().size();
            dict = words;
            squares.clear();

            for (size_t i = 0; i < dict.size(); ++i) {
                insert_word(i);
            }

            for (size_t i = 0; i < dict.size(); ++i) {
                const auto& w = dict[i];
                if (w.empty()) { continue; }

                std::vector<size_t> ws;
                ws.push_back(i);
                if (w.size() == 1) {
                    squares.push_back(ws);
                    continue;
                }

                std::string prefix = {w[1]};
                create_word_square(ws, prefix);
            }

            return transform_squares();
        }
    };
}

#endif //CPPNOTESMAIN_CONSTRUCT_WORD_SQUARES_HPP
