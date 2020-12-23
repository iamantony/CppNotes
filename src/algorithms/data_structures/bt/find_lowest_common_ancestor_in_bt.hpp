#ifndef CPPNOTESMAIN_FIND_LOWEST_COMMON_ANCESTOR_IN_BT_HPP
#define CPPNOTESMAIN_FIND_LOWEST_COMMON_ANCESTOR_IN_BT_HPP

#include <typle>
#include <unordered_set>
#include <vector>
#include "types/ds/binary_tree_nodes.hpp"

namespace Algo::DS::BT {
    template <typename T>
    class FindLowestCommonAncestor {
    public:
        /*
        https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
        Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes
        in the BST.

        According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined
        between two nodes p and q as the lowest node in T that has both p and q as descendants
        (where we allow a node to be a descendant of itself).”

        Example 1:
                3
             /     \
            5       1
           / \     / \
          6   2   0   8
             / \
            7   4

        Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
        Output: 6
        Explanation: The LCA of nodes 2 and 8 is 6.

        Example 2:
                3
             /     \
            5       1
           / \     / \
          6   2   0   8
             / \
            7   4

        Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
        Output: 2
        Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself
        according to the LCA definition.

        Example 3:
        Input: root = [2,1], p = 2, q = 1
        Output: 2

        Constraints:
        * The number of nodes in the tree is in the range [2, 10^5].
        * -10^9 <= Node.val <= 10^9
        * All Node.val are unique.
        * p != q
        * p and q will exist in the BST.
        */

        static Types::DS::NodeBT<T>* search_lca_of_two_nodes_in_bst(
            Types::DS::NodeBT<T>* root, Types::DS::NodeBT<T>* p, Types::DS::NodeBT<T>* q) {
            do {
                if (root == p) { return p; }
                if (root == q) { return q; }

                if (root->val > p->val && root->val > q->val) { root = root->left; }
                else if (root->val < p->val && root->val < q->val) { root = root->right; }
                else { return root; }
            }
            while (root != nullptr);

            return nullptr;
        }

        /*
        https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
        Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

        According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined
        between two nodes p and q as the lowest node in T that has both p and q as descendants
        (where we allow a node to be a descendant of itself).”

        Example 1:
                3
             /     \
            5       1
           / \     / \
          6   2   0   8
             / \
            7   4

        Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
        Output: 3
        Explanation: The LCA of nodes 5 and 1 is 3.

        Example 2:
                3
             /     \
            5       1
           / \     / \
          6   2   0   8
             / \
            7   4
        Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
        Output: 5
        Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself
        according to the LCA definition.

        Example 3:
        Input: root = [1,2], p = 1, q = 2
        Output: 1

        Constraints:
        * The number of nodes in the tree is in the range [2, 10^5].
        * -10^9 <= Node.val <= 10^9
        * All Node.val are unique.
        * p != q
        * p and q will exist in the tree.
        */

        static bool search_node(Types::DS::NodeBT<T>* root, Types::DS::NodeBT<T>* q) {
            if (root == nullptr) { return false; }
            if (root->left == q || root->right == q) { return true; }

            return search_node(root->left, q) || search_node(root->right, q);
        }

        static std::tuple<Types::DS::NodeBT<T>*, bool, bool> search_lca_ten_helper(
            Types::DS::NodeBT<T>* r,
            const Types::DS::NodeBT<T>* const p,
            const Types::DS::NodeBT<T>* const q)
        {
            if (r == nullptr) { return {nullptr, false, false}; }

            auto [left, lfp, lfq] = search_lca_ten_helper(r->left, p, q);
            if (left != nullptr && lfp && lfq) { return {left, true, true}; }

            auto [right, rfp, rfq] = search_lca_ten_helper(r->right, p, q);
            if (right != nullptr && rfp && rfq) { return {right, true, true}; }

            if ((lfp || rfp) && (lfq || rfq)) { return {r, true, true}; }

            return {nullptr, (lfp || rfp || r == p), (lfq || rfq || r == q)};
        }

        static Types::DS::NodeBT<T>* search_lca_of_two_existent_nodes(
            Types::DS::NodeBT<T>* root,
            Types::DS::NodeBT<T>* p,
            Types::DS::NodeBT<T>* q)
        {
            if (root == nullptr) { return nullptr; }
            if (root == p || root == q) { return root; }

            if (search_node(p, q)) { return p; }
            if (search_node(q, p)) { return q; }

            auto [node, fp, fq] = search_lca_ten_helper(root, p, q);
            return node;
        }

        /*
        https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-ii/
        Given the root of a binary tree, return the lowest common ancestor (LCA) of two given nodes,
        p and q. If either node p or q does not exist in the tree, return null. All values of the
        nodes in the tree are unique.

        According to the definition of LCA on Wikipedia: "The lowest common ancestor of two nodes
        p and q in a binary tree T is the lowest node that has both p and q as descendants (where
        we allow a node to be a descendant of itself)". A descendant of a node x is a node y that
        is on the path from node x to some leaf node.

        Example 1:
                3
             /     \
            5       1
           / \     / \
          6   2   0   8
             / \
            7   4

        Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
        Output: 3
        Explanation: The LCA of nodes 5 and 1 is 3.

        Example 2:
                3
             /     \
            5       1
           / \     / \
          6   2   0   8
             / \
            7   4
        Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
        Output: 5
        Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself
        according to the LCA definition.

        Example 3:
                3
             /     \
            5       1
           / \     / \
          6   2   0   8
             / \
            7   4
        Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 10
        Output: null
        Explanation: Node 10 does not exist in the tree, so return null.

        Constraints:
        * The number of nodes in the tree is in the range [2, 10^5].
        * -10^9 <= Node.val <= 10^9
        * All Node.val are unique.
        * p != q
        */

        static Types::DS::NodeBT<T>* search_lca_tnmne_helper(
            Types::DS::NodeBT<T>* r,
            const Types::DS::NodeBT<T>* const p,
            const Types::DS::NodeBT<T>* const q,
            size_t& counter)
        {
            if (r == nullptr) { return nullptr; }

            auto* left = search_lca_tnmne_helper(r->left, p, q, counter);
            auto* right = search_lca_tnmne_helper(r->right, p, q, counter);
            if (r == p || r == q) {
                ++counter;
                return r;
            }

            if (left != nullptr && right != nullptr) { return r; }
            if (left != nullptr) { return left; }
            if (right != nullptr) { return right; }

            return nullptr;
        }

        static Types::DS::NodeBT<T>* search_lca_of_two_nodes_that_may_not_exist(
            Types::DS::NodeBT<T>* root,
            Types::DS::NodeBT<T>* p,
            Types::DS::NodeBT<T>* q)
        {
            if (root == nullptr) { return nullptr; }

            size_t counter = 0;
            auto* node = search_lca_tnmne_helper(root, p, q, counter);
            return counter == 2 ? node : nullptr;
        }

        /*
        https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii/
        Given two nodes of a binary tree p and q, return their lowest common ancestor (LCA).

        Each node will have a reference to its parent node. The definition for Node is below:

        class Node {
            public int val;
            public Node left;
            public Node right;
            public Node parent;
        }

        According to the definition of LCA on Wikipedia: "The lowest common ancestor of two nodes
        p and q in a tree T is the lowest node that has both p and q as descendants (where we allow
        a node to be a descendant of itself)."

        Example 1:
                    3
                 /     \
                5       1
               / \     / \
              6   2   0   8
                 / \
                7   4

        Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
        Output: 3
        Explanation: The LCA of nodes 5 and 1 is 3.

        Example 2:
                    3
                 /     \
                5       1
               / \     / \
              6   2   0   8
                 / \
                7   4

        Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
        Output: 5
        Explanation: The LCA of nodes 5 and 4 is 5 since a node can be a descendant of itself
        according to the LCA definition.

        Example 3:
        Input: root = [1,2], p = 1, q = 2
        Output: 1

        Constraints:
        * The number of nodes in the tree is in the range [2, 10^5].
        * -10^9 <= Node.val <= 10^9
        * All Node.val are unique.
        * p != q
        * p and q exist in the tree.
        */
        struct Node {
            int value;
            Node* left = nullptr;
            Node* right = nullptr;
            Node* parent = nullptr;
        };

        static Node* search_lca_of_nodes_with_parent_pointer(Node* p, Node * q) {
            Node* pp = p;
            Node* pq = q;
            while (pp != pq) {
                pp = pp->parent;
                pq = pq->parent;
                if (pp == pq) { return pp; }
                if (!pp) { pp = q; }
                if (!pq) { pq = p; }
            }

            return pp;
        }

        /*
        https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iv/
        Given the root of a binary tree and an array of TreeNode objects nodes, return the lowest
        common ancestor (LCA) of all the nodes in nodes. All the nodes will exist in the tree, and all
        values of the tree's nodes are unique.

        Extending the definition of LCA on Wikipedia: "The lowest common ancestor of n nodes
        p1, p2, ..., pn in a binary tree T is the lowest node that has every pi as a descendant
        (where we allow a node to be a descendant of itself) for every valid i". A descendant of a
        node x is a node y that is on the path from node x to some leaf node.

        Example 1:
                    3
                 /     \
                5       1
               / \     / \
              6   2   0   8
                 / \
                7   4

        Input: root = [3,5,1,6,2,0,8,null,null,7,4], nodes = [4,7]
        Output: 2
        Explanation: The lowest common ancestor of nodes 4 and 7 is node 2.

        Example 2:
                    3
                 /     \
                5       1
               / \     / \
              6   2   0   8
                 / \
                7   4

        Input: root = [3,5,1,6,2,0,8,null,null,7,4], nodes = [1]
        Output: 1
        Explanation: The lowest common ancestor of a single node is the node itself.

        Example 3:
                    3
                 /     \
                5       1
               / \     / \
              6   2   0   8
                 / \
                7   4

        Input: root = [3,5,1,6,2,0,8,null,null,7,4], nodes = [7,6,2,4]
        Output: 5
        Explanation: The lowest common ancestor of the nodes 7, 6, 2, and 4 is node 5.

        Example 4:
                    3
                 /     \
                5       1
               / \     / \
              6   2   0   8
                 / \
                7   4

        Input: root = [3,5,1,6,2,0,8,null,null,7,4], nodes = [0,1,2,3,4,5,6,7,8]
        Output: 3
        Explanation: The lowest common ancestor of all the nodes is the root node.

        Constraints:
        * The number of nodes in the tree is in the range [1, 10^4].
        * -10^9 <= Node.val <= 10^9
        * All Node.val are unique.
        * All nodes[i] will exist in the tree.
        * All nodes[i] are distinct.
        */
        static Types::DS::NodeBT<T>* search_lca_sn_helper(
            Types::DS::NodeBT<T>* root, const std::unordered_set<T>& set)
        {
            if (root == nullptr) { return nullptr; }
            if (set.count(root->val) > 0) { return root; }

            auto* left = search(root->left, set);
            auto* right = search(root->right, set);
            if (left == nullptr && right == nullptr) { return nullptr; }
            if (left != nullptr && right != nullptr) { return root; }

            return left == nullptr ? right : left;
        }

        static Types::DS::NodeBT<T>* search_lca_of_several_nodes(
            Types::DS::NodeBT<T>* root, std::vector<Types::DS::NodeBT<T>*>& nodes)
        {
            if (nodes.empty()) { return nullptr; }
            if (nodes.size() == 1) { return nodes.front(); }

            std::unordered_set<int> set;
            for (auto n : nodes) { set.insert(n->val); }

            return search_lca_sn_helper(root, set);
        }
    };
}

#endif //CPPNOTESMAIN_FIND_LOWEST_COMMON_ANCESTOR_IN_BT_HPP
