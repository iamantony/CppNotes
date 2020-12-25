#ifndef CPPNOTESMAIN_INORDER_SUCCESSOR_IN_BST_HPP
#define CPPNOTESMAIN_INORDER_SUCCESSOR_IN_BST_HPP

/*
https://leetcode.com/problems/inorder-successor-in-bst/
Given a binary search tree and a node in it, find the in-order successor of that node in the BST.
The successor of a node p is the node with the smallest key greater than p.val.

Example 1:
Input: root = [2,1,3], p = 1
Output: 2
Explanation: 1's in-order successor node is 2. Note that both p and the return value is of
TreeNode type.

Example 2:
Input: root = [5,3,6,2,4,null,null,1], p = 6
Output: null
Explanation: There is no in-order successor of the current node, so the answer is null.

Note:
* If the given node has no in-order successor in the tree, return null.
* It's guaranteed that the values of the tree are unique.
*/

#include "types/ds/binary_tree_nodes.hpp"

namespace Algo::DS::BT {
    template <typename T>
    class InorderSuccessorInBST {
    public:
        static Types::DS::NodeBT<T>* find(Types::DS::NodeBT<T>* root, Types::DS::NodeBT<T>* p) {
            if (root == nullptr || p == nullptr) { return nullptr; }

            Types::DS::NodeBT<T>* res = nullptr;
            if (p->right != nullptr) {
                res = p->right;
                while (true) {
                    if (res->left == nullptr) { break; }

                    res = res->left;
                }

                return res;
            }

            if (root == p) { return res; }

            auto* cur = root;
            Types::DS::NodeBT<T>* prev_largest = nullptr;
            while (true) {
                if (cur->val < p->val) {
                    if (cur->right == nullptr || cur->right == p) { return prev_largest; }

                    cur = cur->right;
                }
                else {
                    prev_largest = cur;
                    if (cur->left == nullptr || cur->left == p) { return prev_largest; }

                    cur = cur->left;
                }
            }

            return cur;
        }
    };
}

#endif //CPPNOTESMAIN_INORDER_SUCCESSOR_IN_BST_HPP
