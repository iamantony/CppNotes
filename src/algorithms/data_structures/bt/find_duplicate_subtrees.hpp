#ifndef CPPNOTESMAIN_FIND_DUPLICATE_SUBTREES_HPP
#define CPPNOTESMAIN_FIND_DUPLICATE_SUBTREES_HPP

/*
https://leetcode.com/problems/find-duplicate-subtrees/
Given a binary tree, return all duplicate subtrees. For each kind of duplicate subtrees, you only
need to return the root node of any one of them.

Two trees are duplicate if they have the same structure with same node values.

Example 1:

        1
       / \
      2   3
     /   / \
    4   2   4
       /
      4

The following are two duplicate subtrees:

      2
     /
    4

and

    4

Therefore, you need to return above trees' root in the form of a list.
*/

#include <set>
#include <unordered_map>
#include "types/ds/binary_tree_nodes.hpp"

namespace Algo::DS::BT {
    class FindDuplicateSubtrees {
        using Node = Types::DS::NodeBT<int>;
        std::unordered_map<std::string, std::pair<Node*, size_t>> m_nodes_map;

        std::string traverse(Types::DS::NodeBT<int>* head) {
            if (head == nullptr) { return "#"; }

            const auto left_pattern = traverse(head->left);
            const auto right_pattern = traverse(head->right);
            const auto node_pattern = std::to_string(head->value);

            const auto pattern = left_pattern + "-" + right_pattern + "-" + node_pattern;
            const auto iter = m_nodes_map.find(pattern);
            if (iter == m_nodes_map.end()) {
                m_nodes_map[pattern] = {head, 1};
            }
            else {
                m_nodes_map[pattern].second += 1;
            }

            return pattern;
        }

    public:
        std::vector<Types::DS::NodeBT<int>*> find(Types::DS::NodeBT<int>* head) {
            traverse(head);

            std::vector<Types::DS::NodeBT<int>*> result;
            for (const auto& [_, pair] : m_nodes_map) {
                if (pair.second > 1) {
                    result.push_back(pair.first);
                }
            }

            return result;
        }
    };
}

#endif //CPPNOTESMAIN_FIND_DUPLICATE_SUBTREES_HPP
