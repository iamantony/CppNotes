#ifndef BT_POSTORDER_TRAVERSAL_HPP
#define BT_POSTORDER_TRAVERSAL_HPP

// https://leetcode.com/problems/binary-tree-postorder-traversal/description/
// Given a binary tree, return the postorder traversal of its nodes' values.
// Post-order traversal is to traverse the left subtree, then traverse the
// right subtree, and finally visit a root.

/*
Example: input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [3,2,1]
*/

// Follow up: Recursive solution is trivial, could you do it iteratively?

#include <vector>
#include <stack>
#include <set>

#include "types/ds/binary_tree_nodes.hpp"

namespace Algo::DS::BT {

class PostorderTraversal {
public:
    template<typename T>
    static std::vector<T> PostorderRecursive(NodeBT<T>* root) {
        std::vector<T> result;
        if (root == nullptr) {
            return result;
        }

        PostorderImpl(root, result);
        return result;
    }

    // The postorder traversal can easily be done using two stacks.
    // The idea is to push reverse postorder traversal to a stack. Once we have
    // reverse postorder traversal in a stack, we can just pop all items
    // one by one from the stack and print them, this order of printing will be
    // in postorder because of LIFO property of stacks. Now the question is,
    // how to get reverse post order elements in a stack – the other stack is
    // used for this purpose. We can do something like iterative preorder
    // traversal with following differences.
    // a) Instead of printing an item, we push it to a stack.
    // b) We push left subtree before right subtree.
    template<typename T>
    static std::vector<T> PostorderIterStack(NodeBT<T>* root) {
        std::vector<T> result;
        if (root == nullptr) {
            return result;
        }

        std::stack<NodeBT<T>*> s1, s2;
        s1.push(root);
        while (!s1.empty()) {
            NodeBT<T>* node = s1.top();
            s1.pop();
            s2.push(node);

            if (node->left != nullptr) {
                s1.push(node->left);
            }

            if (node->right != nullptr) {
                s1.push(node->right);
            }
        }

        while (!s2.empty()) {
            result.push_back(s2.top()->value);
            s2.pop();
        }

        return result;
    }

private:
    template<typename T>
    static void PostorderImpl(NodeBT<T>* root, std::vector<T>& v) {
        if (root == nullptr) {
            return;
        }

        PostorderImpl(root->left, v);
        PostorderImpl(root->right, v);
        v.push_back(root->value);
    }
};

}

#endif // BT_POSTORDER_TRAVERSAL_HPP
