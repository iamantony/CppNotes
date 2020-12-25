#ifndef CPPNOTESMAIN_BALANCED_BT_HPP
#define CPPNOTESMAIN_BALANCED_BT_HPP

/*
https://leetcode.com/problems/balanced-binary-tree/
Given a binary tree, determine if it is height-balanced.
 For this problem, a height-balanced binary tree is defined as: a binary tree in which the left
and right subtrees of every node differ in height by no more than 1.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: true

Example 2:
Input: root = [1,2,2,3,3,null,null,4,4]
Output: false

Example 3:
Input: root = []
Output: true

Constraints:
* The number of nodes in the tree is in the range [0, 5000].
* -10^4 <= Node.val <= 10^4
*/

#include "types/ds/binary_tree_nodes.hpp"

namespace Algo::DS::BT {
    template <typename T>
    class BalancedBT {
        static std::pair<bool, size_t> helper(Types::DS::NodeBT<T>* node) {
            if (node == nullptr) { return {true, 0}; }

            const auto [lb, lh] = helper(node->left);
            const auto [rb, rh] = helper(node->right);
            if (!lb || !rb || std::max(lh, rh) - std::min(lh, rh) > 1) {
                return {false, std::max(lh, rh) + 1};
            }

            return {true, std::max(lh, rh) + 1};
        }

    public:
        static bool is_balanced(Types::DS::NodeBT<T>* root) {
            const auto [res, h] = helper(root);
            return res;
        }
    };
}

#endif //CPPNOTESMAIN_BALANCED_BT_HPP
