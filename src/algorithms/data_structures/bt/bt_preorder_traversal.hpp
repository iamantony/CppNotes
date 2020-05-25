#ifndef BT_PREORDER_TRAVERSAL_HPP
#define BT_PREORDER_TRAVERSAL_HPP

// https://leetcode.com/problems/binary-tree-preorder-traversal/description/

// Given a binary tree, return the preorder traversal of its nodes' values.
// Pre-order traversal is to visit the root first. Then traverse the left
// subtree. Finally, traverse the right subtree.

/*
 Example: input = [1,null,2,3]
   1
    \
     2
    /
   3
*/

//Output: [1,2,3]
//Follow up: Recursive solution is trivial, could you do it iteratively?

#include <vector>
#include <stack>

#include "types/ds/binary_tree_nodes.hpp"

namespace Algo::DS::BT {

class PreorderTraversal {
public:
    template<typename T>
    static std::vector<T> PreorderRecursive(Types::DS::NodeBT<T>* root) {
        std::vector<T> result;
        if (root == nullptr) {
            return result;
        }

        PreorderImpl(root, result);
        return result;
    }

    template<typename T>
    static std::vector<T> PreorderIterative(Types::DS::NodeBT<T>* root) {
        std::vector<T> result;
        if (root == nullptr) {
            return result;
        }

        std::stack<Types::DS::NodeBT<T>*> nodesStack;
        nodesStack.push(root);
        while (!nodesStack.empty()) {
            Types::DS::NodeBT<T>* node = nodesStack.top();
            result.push_back(node->value);
            nodesStack.pop();

            if (node->right != nullptr) {
                nodesStack.push(node->right);
            }

            if (node->left != nullptr) {
                nodesStack.push(node->left);
            }
        }

        return result;
    }

private:
    template<typename T>
    static void PreorderImpl(Types::DS::NodeBT<T>* root, std::vector<T>& v) {
        if (root == nullptr) {
            return;
        }

        v.push_back(root->value);
        PreorderImpl(root->left, v);
        PreorderImpl(root->right, v);
    }
};

}

#endif // BT_PREORDER_TRAVERSAL_HPP
