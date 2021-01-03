#ifndef CPPNOTESMAIN_ADD_AND_SEARCH_WORD_SYSTEM_HPP
#define CPPNOTESMAIN_ADD_AND_SEARCH_WORD_SYSTEM_HPP

/*
https://leetcode.com/problems/design-add-and-search-words-data-structure/
Design a data structure that supports adding new words and finding if a string matches any
previously added string.

Implement the WordDictionary class:
* WordDictionary() Initializes the object.
* void addWord(word) Adds word to the data structure, it can be matched later.
* bool search(word) Returns true if there is any string in the data structure that matches word
or false otherwise. word may contain dots '.' where dots can be matched with any letter.


Example:
Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True

Constraints:
* 1 <= word.length <= 500
* word in addWord consists lower-case English letters.
* word in search consist of  '.' or lower-case English letters.
* At most 50000 calls will be made to addWord and search.
*/

#include <string>
#include <unordered_map>

namespace Algo::DS::Tree {
    class AddAndSearchSystem {
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

        Node root;

        bool search_impl(Node* n, const std::string& word, size_t pos) {
            if (pos >= word.size() && n->is_word) { return true; }

            if (word[pos] == '.') {
                for (const auto [c, pn] : n->children) {
                    if (search_impl(pn, word, pos + 1)) { return true; }
                }
            }
            else {
                auto iter = n->children.find(word[pos]);
                if (iter != n->children.end()) {
                    return search_impl(iter->second, word, pos + 1);
                }
            }

            return false;
        }

    public:
        AddAndSearchSystem() = default;

        void add_word(const std::string& word) {
            Node* n = &root;
            for (size_t i = 0; i < word.size(); ++i) {
                auto iter = n->children.find(word[i]);
                if (iter == n->children.end()) {
                    auto new_node = new Node(i == word.size() - 1);
                    auto [new_iter, _] = n->children.insert({word[i], new_node});
                    iter = new_iter;
                }
                else {
                    if (i == word.size() - 1) {
                        iter->second->is_word = true;
                    }
                }

                n = iter->second;
            }
        }

        bool search(const std::string& word) {
            return search_impl(&root, word, 0);
        }
    };
}

#endif //CPPNOTESMAIN_ADD_AND_SEARCH_WORD_SYSTEM_HPP
