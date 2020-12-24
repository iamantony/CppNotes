#ifndef CPPNOTESMAIN_SERIALIZE_AND_DESERIALIZE_BT_HPP
#define CPPNOTESMAIN_SERIALIZE_AND_DESERIALIZE_BT_HPP

/*
https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
Serialization is the process of converting a data structure or object into a sequence of bits so
that it can be stored in a file or memory buffer, or transmitted across a network connection link
to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your
serialization/deserialization algorithm should work. You just need to ensure that a binary tree
can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You
do not necessarily need to follow this format, so please be creative and come up with different
approaches yourself.

Example 1:
      1
     / \
    2   3
       / \
      4   5

Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]

Example 2:
Input: root = []
Output: []

Example 3:
Input: root = [1]
Output: [1]

Example 4:
Input: root = [1,2]
Output: [1,2]

Constraints:
* The number of nodes in the tree is in the range [0, 10^4].
* -1000 <= Node.val <= 1000
*/

#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <numeric>
#include <sstream>
#include "types/ds/binary_tree_nodes.hpp"

namespace Algo::DS::BT {
    class Serializator {
        std::string join(const std::vector<std::string>& elements) {
            if (elements.empty()) { return {}; }

            return std::accumulate(
                std::next(elements.begin()),
                elements.end(),
                *elements.begin(),
                [this](const auto& left, const auto& right) { return left + SEPARATOR + right; });
        }

        std::vector<std::string> split(const std::string& str) {
            if (str.empty()) { return {}; }

            std::istringstream ss{str};
            std::vector<std::string> result;
            for (std::string e; std::getline(ss, e, SEPARATOR); ) {
                result.push_back(e);
            }

            return result;
        }

        Types::DS::NodeBT<int>* str_to_node(const std::string& str) {
            if (str.empty() || str == NO_NODE) { return nullptr; }

            return new Types::DS::NodeBT<int>(std::atoi(str.c_str()));
        }

    public:
        const std::string NO_NODE = {"n"};
        const std::string END_NODE = {"e"};
        const char SEPARATOR = {','};

        std::string serialize(Types::DS::NodeBT<int>* root) {
            std::vector<std::string> elements;
            std::queue<Types::DS::NodeBT<int>*> q;
            q.push(root);
            while (!q.empty()) {
                auto* n = q.front();
                q.pop();

                if (n == nullptr) {
                    elements.push_back(NO_NODE);
                    continue;
                }

                elements.push_back(std::to_string(n->value));
                if (n->left == nullptr && n->right == nullptr) {
                    elements.push_back(END_NODE);
                }
                else {
                    q.push(n->left);
                    q.push(n->right);
                }
            }

            return join(elements);
        }

        Types::DS::NodeBT<int>* deserialize(const std::string& str) {
            const auto elements = split(str);
            if (elements.empty() || elements.front() == NO_NODE || elements.front() == END_NODE) {
                return nullptr;
            }

            auto* root = str_to_node(elements.front());
            std::vector<Types::DS::NodeBT<int>*> level_nodes;
            level_nodes.push_back(root);
            for (size_t i = 1; i < elements.size() && !level_nodes.empty(); ) {
                std::vector<Types::DS::NodeBT<int>*> next_level;
                for (auto* n : level_nodes) {
                    if (elements[i] == END_NODE) {
                        ++i;
                        continue;
                    }

                    n->left = str_to_node(elements[i++]);
                    if (n->left != nullptr && i < elements.size()) {
                        if (elements[i] == END_NODE) {
                            ++i;
                        }
                        else {
                            next_level.push_back(n->left);
                        }
                    }

                    n->right = str_to_node(elements[i++]);
                    if (n->right != nullptr && i < elements.size()) {
                        if (elements[i] == END_NODE) {
                            ++i;
                        }
                        else {
                            next_level.push_back(n->right);
                        }
                    }
                }

                level_nodes = std::move(next_level);
            }

            return root;
        }
    };
}

#endif //CPPNOTESMAIN_SERIALIZE_AND_DESERIALIZE_BT_HPP
