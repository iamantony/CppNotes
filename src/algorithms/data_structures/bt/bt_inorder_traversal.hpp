#ifndef BT_INORDER_TRAVERSAL_HPP
#define BT_INORDER_TRAVERSAL_HPP

// https://leetcode.com/problems/binary-tree-inorder-traversal/description/

// Given a binary tree, return the inorder traversal of its nodes' values.
// In-order traversal is to traverse the left subtree first. Then visit the
// root. Finally, traverse the right subtree.

/*
Example: input = [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
*/

// Follow up: Recursive solution is trivial, could you do it iteratively?

#include <vector>
#include <stack>

#include "types/ds/binary_tree_nodes.hpp"

namespace DataStructures { namespace BT { namespace Inorder {

class Solution {
public:
    template <typename T>
    std::vector<T> InorderTraversalRecursive(NodeBT<T>* root) {
        std::vector<T> result;

        return result;
    }

    template <typename T>
    std::vector<T> InorderTraversalIterative(NodeBT<T>* root) {
        std::vector<T> result;

        return result;
    }
};

} } }

#endif // BT_INORDER_TRAVERSAL_HPP
