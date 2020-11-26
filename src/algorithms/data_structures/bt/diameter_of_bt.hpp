#ifndef CPPNOTESMAIN_DIAMETER_OF_BT_HPP
#define CPPNOTESMAIN_DIAMETER_OF_BT_HPP

/*
https://leetcode.com/problems/diameter-of-binary-tree/
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of
a binary tree is the length of the longest path between any two nodes in a tree. This path may or
may not pass through the root.

Example:
Given a binary tree
          1
         / \
        2   3
       / \
      4   5

Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.
*/

#include "types/ds/binary_tree_nodes.hpp"

namespace Algo::DS::BT {
    template <typename T>
    class DiameterOfBT {
        static size_t postOrderTraversal(Types::DS::NodeBT<T>* root, size_t& max) {
            if (root == nullptr) { return 0; }
            if (root->left == nullptr && root->right == nullptr) { return 0; }

            auto left_path = postOrderTraversal(root->left);
            auto right_path = postOrderTraversal(root->right);
            if (root->left != nullptr && root->right != nullptr) {
                max = std::max(max, left_path + right_path + 2);
            }

            return 1 + std::max(left_path, right_path);
        }

    public:
        static size_t calc(Types::DS::NodeBT<T>* root) {
            size_t max = 0;
            max = std::max(max, postOrderTraversal(root, max));
            return max;
        }
    };
}

#endif //CPPNOTESMAIN_DIAMETER_OF_BT_HPP
