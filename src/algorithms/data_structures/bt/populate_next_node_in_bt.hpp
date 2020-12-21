#ifndef CPPNOTESMAIN_POPULATE_NEXT_NODE_IN_BT_HPP
#define CPPNOTESMAIN_POPULATE_NEXT_NODE_IN_BT_HPP

/*
https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
Given a binary tree

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}

Populate each next pointer to point to its next right node. If there is no next right node,
the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Follow up:
- You may only use constant extra space.
- Recursive approach is fine, you may assume implicit stack space does not count as extra space
for this problem.

Example 1:
       1               1
      / \             /  \
     2   3           2 -> 3 -> null
    / \   \        /  \    \
   5   6   7      5 -> 6 -> 7

    Figure A        Figure B

Input: root = [1,2,3,4,5,null,7]
Output: [1,#,2,3,#,4,5,7,#]
Explanation: Given the above binary tree (Figure A), your function should populate each next
pointer to point to its next right node, just like in Figure B. The serialized output is
in level order as connected by the next pointers, with '#' signifying the end of each level.

Constraints:
* The number of nodes in the given tree is less than 6000.
* -100 <= node.val <= 100
*/

namespace Algo::DS::BT {
    class PopulateNextNodeInBT {
    public:
        struct Node {
            int val = 0;
            Node* left = nullptr;
            Node* right = nullptr;
            Node* next = nullptr;

            Node() {}
            Node(int _val) : val(_val) {}
            Node(int _val, Node* _left, Node* _right, Node* _next)
                : val(_val), left(_left), right(_right), next(_next) {}
        };

        static Node* connect_next_nodes(Node* root) {
            auto* node = root;

            const auto get_right_child = [](Node* n) -> Node* {
                if (n == nullptr) { return nullptr; }
                if (n->right != nullptr) { return n->right; }

                while (n != nullptr) {
                    n = n->next;
                    if (n == nullptr) { return nullptr; }
                    if (n->left != nullptr) { return n->left; }
                    if (n->right != nullptr) { return n->right; }
                }

                return nullptr;
            };

            const auto get_next = [](Node* n) -> Node* {
                while (n != nullptr) {
                    if (n->left != nullptr) { return n->left; }
                    if (n->right != nullptr) { return n->right; }

                    n = n->next;
                }

                return nullptr;
            };

            while (node != nullptr) {
                auto* t = node;
                while (t != nullptr) {
                    if (t->left != nullptr) {
                        t->left->next = get_right_child(t);
                    }
                    if (t->right != nullptr) {
                        t->right->next = get_next(t->next);
                    }

                    t = t->next;
                }

                node = get_next(node);
            }

            return root;
        }
    };
}

#endif //CPPNOTESMAIN_POPULATE_NEXT_NODE_IN_BT_HPP
