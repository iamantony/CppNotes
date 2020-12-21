#ifndef CPPNOTESMAIN_CONSTRUCT_BT_FROM_PREORDER_AND_INORDER_TRAVERSALS_HPP
#define CPPNOTESMAIN_CONSTRUCT_BT_FROM_PREORDER_AND_INORDER_TRAVERSALS_HPP

/*
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given
preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]

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
    class ConstructBTFromInAndPreOrderTraversals {
        static Types::DS::NodeBT<T>* recursive_helper(
            const std::vector<int>& preorder,
            const std::vector<int>& inorder,
            const std::unordered_map<T, size_t>& map,
            size_t start,
            size_t end,
            size_t &p_index)
        {
            using Types::DS::NodeBT;

            if (start >= end) { return nullptr; }

            auto* root = new NodeBT<T>(preorder[p_index++]);
            const auto pos = map.at(root->value);
            root->left = recursive_helper(preorder,inorder, map, start, pos, p_index);
            root->right = recursive_helper(preorder,inorder, map, pos+1, end, p_index);
            return root;
        }

    public:
        static Types::DS::NodeBT<T>* construct_recursive(
            const std::vector<T>& preorder, const std::vector<T>& inorder)
        {
            if (preorder.empty() || preorder.size() != inorder.size()) { return nullptr; }

            std::unordered_map<T, size_t> map;
            for (size_t i = 0; i < inorder.size(); ++i) { map[inorder[i]] = i; }

            size_t p_index = 0;
            return recursive_helper(preorder, inorder, map, 0, preorder.size(), p_index);
        }


        static Types::DS::NodeBT<T>* construct_iterative_my(
            const std::vector<T>& preorder, const std::vector<T>& inorder)
        {
            using Types::DS::NodeBT;

            if (preorder.empty() || preorder.size() != inorder.size()) { return nullptr; }

            std::unordered_map<T, size_t> map;
            for (size_t i = 0; i < inorder.size(); ++i) { map[inorder[i]] = i; }

            auto* root = new NodeBT<T>(preorder.front());
            std::stack<NodeBT<T>*> st;
            st.push(root);
            for (size_t i = 1; i < preorder.size(); ++i) {
                auto* child = new NodeBT<T>(preorder[i]);
                auto* parent = st.top();
                if (map[child->value] < map[parent->value]) {
                    parent->left = child;
                    st.push(child);
                }
                else {
                    while (!st.empty()) {
                        auto* prev_parent = parent;
                        st.pop();
                        if (st.empty()) {
                            while (prev_parent->right != nullptr) {
                                st.push(prev_parent);
                                prev_parent = prev_parent->right;
                            }

                            prev_parent->right = child;
                            st.push(prev_parent);
                            st.push(child);
                            break;
                        }

                        parent = st.top();
                        if (map[child->value] > map[prev_parent->value] &&
                            map[child->value] < map[parent->value]) {
                            while (prev_parent->right != nullptr) {
                                st.push(prev_parent);
                                prev_parent = prev_parent->right;
                            }

                            prev_parent->right = child;
                            st.push(prev_parent);
                            st.push(child);
                            break;
                        }
                    }

                }
            }

            return root;
        }

        static Types::DS::NodeBT<T>* construct_iterative_fast(
            const std::vector<T>& preorder, const std::vector<T>& inorder) {
            using Types::DS::NodeBT;

            if (preorder.empty() || preorder.size() != inorder.size()) { return nullptr; }

            std::stack<NodeBT<T>*> st;
            size_t pre_idx = 0;
            size_t in_idx = 0;
            auto* cur = new NodeBT<T>(preorder[pre_idx++]);
            auto* root = cur;
            st.push(cur);
            while (!st.empty()) {
                while (st.top()->value != inorder[in_idx]) {
                    // dfs in left subtree by visiting preorder
                    // break when reaching the left most node
                    st.top()->left = new NodeBT<T>(preorder[pre_idx++]);
                    st.push(st.top()->left);
                }
                while (!st.empty() && st.top()->value == inorder[in_idx]) {
                    // while no right child, preorder is just the reverse order of inorder
                    // break when inorder[idx] is the left most node in cur's right
                    // subtree, and stk.top() is the parent of cur
                    cur = st.top();
                    st.pop();
                    ++in_idx;
                }
                if (pre_idx < preorder.size()) {
                    // preorder[pre_idx] is the right child of cur
                    cur->right = new NodeBT<T>(preorder[pre_idx++]);
                    cur = cur->right;
                    st.push(cur);
                }
            }

            return root;
        }
    };
}

#endif //CPPNOTESMAIN_CONSTRUCT_BT_FROM_PREORDER_AND_INORDER_TRAVERSALS_HPP
