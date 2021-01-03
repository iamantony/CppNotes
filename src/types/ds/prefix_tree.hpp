#ifndef CPPNOTESMAIN_PREFIX_TREE_HPP
#define CPPNOTESMAIN_PREFIX_TREE_HPP

/*
https://leetcode.com/problems/implement-trie-prefix-tree/
Implement a trie with insert, search, and startsWith methods.

Example:
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");
trie.search("app");     // returns true

Note:
* You may assume that all inputs are consist of lowercase letters a-z.
* All inputs are guaranteed to be non-empty strings.
*/

#include <unordered_map>
#include <string>

namespace Types::DS {
    class PrefixTree {
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

    public:
        PrefixTree() = default;

        void insert(const std::string& word) {
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
            Node* n = &root;
            for (size_t i = 0; i < word.size(); ++i) {
                auto iter = n->children.find(word[i]);
                if (iter == n->children.end()) { return false; }

                n = iter->second;
            }

            return n->is_word;
        }

        bool starts_with(const std::string& prefix) {
            Node* n = &root;
            for (size_t i = 0; i < prefix.size(); ++i) {
                auto iter = n->children.find(prefix[i]);
                if (iter == n->children.end()) { return false; }

                n = iter->second;
            }

            return true;
        }
    };
}

#endif //CPPNOTESMAIN_PREFIX_TREE_HPP
