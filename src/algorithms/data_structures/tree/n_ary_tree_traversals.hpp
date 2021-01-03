#ifndef CPPNOTESMAIN_N_ARY_TREE_PREORDER_TRAVERSAL_HPP
#define CPPNOTESMAIN_N_ARY_TREE_PREORDER_TRAVERSAL_HPP

#include "types/ds/n_ary_tree_nodes.hpp"
#inlcude <stack>

namespace Algo::DS::Tree {
    template <typename T>
    class NAryTreeTraversals {
    public:
        /*
        https://leetcode.com/problems/n-ary-tree-preorder-traversal/
        Given an n-ary tree, return the preorder traversal of its nodes' values.
        Example:
                             1
                          /  |  \
                        3    2   4
                      /   \
                     5     6

        Input: root = [1,null,3,2,4,null,5,6]
        Output: [1,3,5,6,2,4]
        */
        static std::vector<T> preorder(Types::DS::NAryTreeNode<T>* root) {
            if (root == nullptr) { return {}; }

            std::stack<Types::DS::NAryTreeNode<T>*> st;
            st.push(root);

            std::vector<T> res;
            while (!st.empty()) {
                auto* n = st.top();
                st.pop();

                res.push_back(n->val);
                for (auto iter = n->children.rbegin(); iter != n->children.rend(); ++iter) {
                    st.push(*iter);
                }
            }

            return res;
        }

        /*
        https://leetcode.com/problems/n-ary-tree-postorder-traversal/
        Given an n-ary tree, return the postorder traversal of its nodes' values.
        Example:
        Input: root = [1,null,3,2,4,null,5,6]
        Output: [5,6,3,2,4,1]
        */
        static std::vector<T> postorder(Types::DS::NAryTreeNode<T>* root) {
            if (root == nullptr) { return {}; }

            std::stack<Types::DS::NAryTreeNode<T>*> st;
            st.push(root);

            std::vector<T> res;
            while (!stp.empty()) {
                auto* n = stp.top();
                stp.pop();

                res.push_back(n->val);
                for (auto c : n->children) { stp.push(c); }
            }

            std::reverse(res.begin(), res.end());
            return res;
        }

        /*
        https://leetcode.com/problems/n-ary-tree-level-order-traversal/
        Given an n-ary tree, return the level order traversal of its nodes' values.
        Example:
        Input: root = [1,null,3,2,4,null,5,6]
        Output: [[1],[3,2,4],[5,6]]
        */
        static std::vector<std::vector<T>> level_order(Types::DS::NAryTreeNode<T>* root) {
            if (root == nullptr) { return {}; }

            std::vector<Types::DS::NAryTreeNode<T>*> lvl;
            lvl.push_back(root);

            std::vector<std::vector<T>> res;
            while (!lvl.empty()) {
                std::vector<T> lvl_res;
                std::vector<Types::DS::NAryTreeNode<T>*> next_lvl;
                for (auto n : lvl) {
                    lvl_res.push_back(n->val);
                    next_lvl.insert(next_lvl.end(), n->children.begin(), n->children.end());
                }

                res.push_back(lvl_res);
                lvl = next_lvl;
            }

            return res;
        }
    };
}

#endif //CPPNOTESMAIN_N_ARY_TREE_PREORDER_TRAVERSAL_HPP
