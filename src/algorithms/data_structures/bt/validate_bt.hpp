#ifndef VALIDATE_BT_HPP
#define VALIDATE_BT_HPP

// https://leetcode.com/problems/validate-binary-search-tree/description/

// Given a binary tree, determine if it is a valid binary search tree (BST).

// Assume a BST is defined as follows:
// The left subtree of a node contains only nodes with keys less than the
// node's key. The right subtree of a node contains only nodes with keys
// greater than the node's key. Both the left and right subtrees must also
// be binary search trees.

/*
Example 1:
   2
  / \
 1   3
Binary tree [2,1,3], return true.

Example 2:
   1
  / \
 2   3
Binary tree [1,2,3], return false.
*/

#include <limits>

#include "types/ds/binary_tree_nodes.hpp"

namespace ValidateBT {

class Solution {
public:

    template<typename T>
    bool isValidBST(NodeBT<T>* root) {
        return false;
    }

private:

    template<typename T>
    bool validateNodeValue(NodeBT<T>* node, const T& min, const T& max) {
        if (nullptr == node) {
            return true;
        }

        if (node->value < min || node->value >= max) {
            return false;
        }

        return validateNodeValue(node->left, min, node->value) &&
                validateNodeValue(node->right, node->value, max);
    }
};

template<>
bool Solution::isValidBST<int>(NodeBT<int>* root) {
    return validateNodeValue(root,
                             std::numeric_limits<int>::min(),
                             std::numeric_limits<int>::max());
}

}

#endif // VALIDATE_BT_HPP
