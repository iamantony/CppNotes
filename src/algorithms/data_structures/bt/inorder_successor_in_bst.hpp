#ifndef CPPNOTESMAIN_INORDER_SUCCESSOR_IN_BST_HPP
#define CPPNOTESMAIN_INORDER_SUCCESSOR_IN_BST_HPP

#include "types/ds/binary_tree_nodes.hpp"

namespace Algo::DS::BT {
    template <typename T>
    class InorderSuccessorInBST {
    public:
        /*
        https://leetcode.com/problems/inorder-successor-in-bst/
        Given a binary search tree and a node in it, find the in-order successor of that node in
        the BST. The successor of a node p is the node with the smallest key greater than p.val.

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

        /*
        https://leetcode.com/problems/inorder-successor-in-bst-ii/
        Given a node in a binary search tree, find the in-order successor of that node in the BST.
        If that node has no in-order successor, return null.
        The successor of a node is the node with the smallest key greater than node.val.
        You will have direct access to the node but not to the root of the tree. Each node will
        have a reference to its parent node. Below is the definition for Node:

        class Node {
            public int val;
            public Node left;
            public Node right;
            public Node parent;
        }


        Follow up: could you solve it without looking up any of the node's values?

        Example 1:
        Input: tree = [2,1,3], node = 1
        Output: 2
        Explanation: 1's in-order successor node is 2. Note that both the node and the return value
        is of Node type.

        Example 2:
        Input: tree = [5,3,6,2,4,null,null,1], node = 6
        Output: null
        Explanation: There is no in-order successor of the current node, so the answer is null.

        Example 3:
        Input: tree = [15,6,18,3,7,17,20,2,4,null,13,null,null,null,null,null,null,null,null,9],
        node = 15
        Output: 17

        Example 4:
        Input: tree = [15,6,18,3,7,17,20,2,4,null,13,null,null,null,null,null,null,null,null,9],
        node = 13
        Output: 15

        Example 5:
        Input: tree = [0], node = 0
        Output: null

        Constraints:
        * -10^5 <= Node.val <= 10^5
        * 1 <= Number of Nodes <= 10^4
        * All Nodes will have unique values.
        */
        class Node {
        public:
            int T = 0;
            Node* left = nullptr;
            Node* right = nullptr;
            Node* parent = nullptr;
        };

        Node* find_in_bst_with_parents(Node* node) {
            Node* next = node->right;
            if (next != nullptr) {
                while (next->left != nullptr) {
                    next = next->left;
                }

                return next;
            }

            Node* parent = node->parent;
            Node* current = node;
            while (parent != nullptr) {
                if (parent->left == current) {
                    return parent;
                }

                current = parent;
                parent = current->parent;
            }

            return nullptr;
        }
    };
}

#endif //CPPNOTESMAIN_INORDER_SUCCESSOR_IN_BST_HPP
