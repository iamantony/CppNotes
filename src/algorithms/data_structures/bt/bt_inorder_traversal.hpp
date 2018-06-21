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

namespace Algo::DS::BT {

class InorderTraversal {
public:
    template <typename T>
    static std::vector<T> InorderRecursive(NodeBT<T>* root) {
        std::vector<T> result;
        InorderRecursiveImpl(root, result);
        return result;
    }

    template <typename T>
    static std::vector<T> InorderIterative(NodeBT<T>* root) {
        std::vector<T> result;
        if (root == nullptr) {
            return result;
        }

        std::stack<NodeBT<T>*> nodesStack;
        NodeBT<T>* current = root;
        while (current != nullptr || !nodesStack.empty()) {
            if (current != nullptr) {
                nodesStack.push(current);
                current = current->left;
            }
            else {
                NodeBT<T>* node = nodesStack.top();
                nodesStack.pop();
                result.push_back(node->value);
                current = node->right;
            }
        }

        return result;
    }

    template <typename T>
    static std::vector<T> InorderIterativeMorris(NodeBT<T>* root) {
        std::vector<T> result;
        if (root == nullptr) {
            return result;
        }

        NodeBT<T>* current = root;
        NodeBT<T>* pre = nullptr;
        while(current != nullptr) {
            if(current->left == nullptr) {
                result.push_back(current->value);
                current = current->right;
            }
            else {
                // Find the inorder predecessor of current
                pre = current->left;
                while(pre->right != nullptr && pre->right != current) {
                    pre = pre->right;
                }

                // Make current as right child of its inorder predecessor
                if(pre->right == nullptr) {
                    pre->right = current;
                    current = current->left;
                }
                else {
                    // Revert the changes made in if part to restore the original
                    // tree i.e., fix the right child of predecssor
                    pre->right = nullptr;

                    result.push_back(current->value);
                    current = current->right;
                }
            }
        }

        return result;
    }

private:
    template <typename T>
    static void InorderRecursiveImpl(NodeBT<T>* root, std::vector<T>& v) {
        if (root == nullptr) {
            return;
        }

        InorderRecursiveImpl(root->left, v);
        v.push_back(root->value);
        InorderRecursiveImpl(root->right, v);
    }
};

}

#endif // BT_INORDER_TRAVERSAL_HPP
