#ifndef CPPNOTESMAIN_REPLACE_WORDS_IN_SENTENCE_HPP
#define CPPNOTESMAIN_REPLACE_WORDS_IN_SENTENCE_HPP

/*
https://leetcode.com/problems/replace-words/
n English, we have a concept called root, which can be followed by some other word to form another
longer word - let's call this word successor. For example, when the root "an" is followed by the
successor word "other", we can form a new word "another".

Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces,
replace all the successors in the sentence with the root forming it. If a successor can be
replaced by more than one root, replace it with the root that has the shortest length.

Return the sentence after the replacement.

Example 1:
Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"

Example 2:
Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
Output: "a a b c"

Example 3:
Input: dictionary = ["a", "aa", "aaa", "aaaa"],
sentence = "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa"
Output: "a a a a a a a a bbb baba a"

Example 4:
Input: dictionary = ["catt","cat","bat","rat"], sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"

Example 5:
Input: dictionary = ["ac","ab"], sentence = "it is abnormal that this solution is accepted"
Output: "it is ab that this solution is ac"

Constraints:
* 1 <= dictionary.length <= 1000
* 1 <= dictionary[i].length <= 100
* dictionary[i] consists of only lower-case letters.
* 1 <= sentence.length <= 10^6
* sentence consists of only lower-case letters and spaces.
* The number of words in sentence is in the range [1, 1000]
* The length of each word in sentence is in the range [1, 1000]
* Each two consecutive words in sentence will be separated by exactly one space.
* sentence does not have leading or trailing spaces.
*/

#include <vector>
#include <string>
#include <unordered_map>

namespace Algo::DS::Tree {
    class ReplaceWordsInSentence {
        struct Node {
            bool is_word = false;
            std::unordered_map<char, Node*> children;

            Node() = default;
            Node(bool word_end) : is_word(word_end) {}
            ~Node() {
                for (auto iter = children.begin(); iter != children.end(); ++iter) {
                    delete iter->second;
                }
            }
        };

        Node create_dict_tree(const std::vector<std::string>& dictionary) {
            Node dict;
            for (const auto& word : dictionary) {
                Node* n = &dict;
                for (const auto& c : word) {
                    auto iter = n->children.find(c);
                    if (iter == n->children.end()) {
                        auto [new_iter, _] = n->children.insert({c, new Node()});
                        iter = new_iter;
                    }

                    n = iter->second;
                }

                n->is_word = true;
            }

            return dict;
        }

        std::string find_parent(const Node& dict, const std::string_view& word) {
            const Node* n = &dict;
            for (size_t i = 0; i < word.size(); ++i) {
                auto iter = n->children.find(word[i]);
                if (iter == n->children.end()) { break; }
                else {
                    if (iter->second->is_word) {
                        return std::string(word.data(), i + 1);
                    }
                }

                n = iter->second;
            }

            return std::string(word.data(), word.size());
        }

        std::vector<std::string_view> split(const std::string& str) {
            if (str.empty()) { return {}; }

            std::vector<std::string_view> words;
            size_t pos = 0;
            do {
                auto p = str.find(' ', pos);
                if (p == std::string::npos) { p = str.size(); }

                words.push_back({str.c_str() + pos, p - pos});
                pos = p + 1;

            } while (pos < str.size());

            return words;
        }

        std::string replace_words(const Node& dict, const std::vector<std::string_view>& words) {
            std::string res;
            for (size_t i = 0; i < words.size(); ++i) {
                res += find_parent(dict, words[i]);
                if (i < words.size() - 1) { res += ' '; }
            }

            return res;
        }

    public:
        std::string replace(const std::vector<std::string>& dictionary, std::string sentence) {
            if (dictionary.empty() || sentence.empty()) { return sentence; }

            const auto dict = create_dict_tree(dictionary);
            const auto words = split(sentence);
            return replace_words(dict, words);
        }
    };
}

#endif //CPPNOTESMAIN_REPLACE_WORDS_IN_SENTENCE_HPP
