#ifndef CPPNOTESMAIN_CONSTRUCT_BST_FROM_PREORDER_TRAVERSAL_HPP
#define CPPNOTESMAIN_CONSTRUCT_BST_FROM_PREORDER_TRAVERSAL_HPP

/*
https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of
node.left has a value < node.val, and any descendant of node.right has a value > node.val.
Also recall that a preorder traversal displays the value of the node first, then traverses
node.left, then traverses node.right.)

It's guaranteed that for the given test cases there is always possible to find a binary search
tree with the given requirements.

Example 1:
Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]
         8
       /   \
      5     10
     / \      \
    1   7      12

Constraints:
* 1 <= preorder.length <= 100
* 1 <= preorder[i] <= 10^8
* The values of preorder are distinct.
*/

#include <vector>
#include <stack>

#include "types/ds/binary_tree_nodes.hpp"

namespace Algo::DS::BT {
    class ConstructBTFromPreorderTraversal {
        Types::DS::NodeBT<int>* insert_recursively(Types::DS::NodeBT<int>* root, int x)
        {
            if (!root) { return new Types::DS::NodeBT<int>(x); }

            if (x > root->val) { root->right = insert_recursively(root->right, x); }
            else { root->left = insert_recursively(root->left, x); }

            return root;
        }

    public:
        Types::DS::NodeBT<int>* recursive(const std::vector<int>& preorder)
        {
            Types::DS::NodeBT<int>* root = nullptr;
            for (int i = 0; i < preorder.size(); ++i)
            {
                root = insertInBST(root, preorder[i]);
            }

            return root;
        }

        Types::DS::NodeBT<int>* iterative(const std::vector<int>& preorder) {
            if (preorder.empty()) { return nullptr; }

            size_t i = 0;
            auto* root = new Types::DS::NodeBT<int>(preorder[i++]);
            std::stack<Types::DS::NodeBT<int>*> stack;
            stack.push(root);
            for (; i < preorder.size(); ++i) {
                auto* child = new Types::DS::NodeBT<int>(preorder[i]);
                auto* parent = sack.top();
                if (child->val < parent->val) {
                    parent->left = child;
                    stack.push(child);
                }
                else {
                    while (!stack.empty()) {
                        stack.pop();
                        if (stack.empty()) {
                            parent->right = child;
                            stack.push(child);
                            break;
                        }

                        auto* pp = stack.top();
                        if (pp->val > child->val) {
                            parent->right = child;
                            stack.push(child);
                            break;
                        }

                        parent = pp;
                    }
                }
            }

            return root;
        }
    };
}

#endif //CPPNOTESMAIN_CONSTRUCT_BST_FROM_PREORDER_TRAVERSAL_HPP
