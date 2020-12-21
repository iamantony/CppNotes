#ifndef CPPNOTESMAIN_CONSTR_BT_FROM_IN_AND_POST_ORDER_TRAVRLS_HPP
#define CPPNOTESMAIN_CONSTR_BT_FROM_IN_AND_POST_ORDER_TRAVRLS_HPP

/*
https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given
inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
*/

#include <vector>
#include <stack>
#include <unordered_map>
#include "types/ds/binary_tree_nodes.hpp"

namespace Algo::DS::BT {
    template <typename T>
    class ConstructBTFromInorderAndPostorderTraversals {
        static Types::DS::NodeBT<T>* recursive_helper(
            const std::vector<T>& inorder,
            const std::vector<T>& postorder,
            const std::unordered_map<T, size_t>& in_map,
            size_t in_start,
            size_t in_end,
            size_t& p_index)
        {
            if (in_start > in_end) {
                return nullptr;
            }

            auto* node = new Types::DS::NodeBT<T>(postorder[p_index]);
            const auto parent_in_pos = in_map.at(node->value);
            if (p_index > 0) {
                --p_index;
                node->right = recursive_helper(
                    inorder, postorder, in_map, parent_in_pos + 1, in_end, p_index);
            }

            if (parent_in_pos > 0) {
                node->left = recursive_helper(
                    inorder, postorder, in_map, in_start, parent_in_pos - 1, p_index);
            }

            return node;
        }

    public:
        static Types::DS::NodeBT<T>* construct_recursive(
            const std::vector<T>& inorder, const std::vector<T>& postorder)
        {
            if (inorder.empty() || inorder.size() != postorder.size()) { return nullptr; }

            std::unordered_map<T, size_t> in_map;
            for (size_t i = 0; i < inorder.size(); ++i) { in_map[inorder[i]] = i; }

            size_t p_index = postorder.size() - 1;
            return recursive_helper(
                inorder, postorder, in_map, 0, postorder.size() - 1, p_index);
        }

        static Types::DS::NodeBT<T>* construct_iterative(
            const std::vector<T>& inorder, const std::vector<T>& postorder)
        {
            if (inorder.empty() || inorder.size() != postorder.size()) { return nullptr; }
            if (postorder.size() == 1) { return new Types::DS::NodeBT<T>(postorder.front()); }

            auto ip = inorder.size() - 1;
            auto pp = postorder.size() - 1;

            std::stack<Types::DS::NodeBT<T>*> st;
            Types::DS::NodeBT<T>* prev = nullptr;
            auto* root = new Types::DS::NodeBT<T>(postorder[pp]);
            st.push(root);
            --pp;

            while (pp >= 0) {
                while (!st.empty() && st.top()->value == inorder[ip]) {
                    prev = st.top();
                    st.pop();
                    --ip;
                }

                auto* node = new Types::DS::NodeBT<T>(postorder[pp]);
                if (prev != nullptr) {
                    prev->left = node;
                } else if (!st.empty()) {
                    st.top()->right = node;
                }

                st.push(node);
                prev = nullptr;
                if (pp == 0) { break; }

                --pp;
            }

            return root;
        }
    };
}

#endif //CPPNOTESMAIN_CONSTR_BT_FROM_IN_AND_POST_ORDER_TRAVRLS_HPP
