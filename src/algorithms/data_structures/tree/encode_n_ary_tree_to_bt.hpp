#ifndef CPPNOTESMAIN_ENCODE_N_ARY_TREE_TO_BT_HPP
#define CPPNOTESMAIN_ENCODE_N_ARY_TREE_TO_BT_HPP

/*
https://leetcode.com/problems/encode-n-ary-tree-to-binary-tree/
Design an algorithm to encode an N-ary tree into a binary tree and decode the binary tree to get
the original N-ary tree. An N-ary tree is a rooted tree in which each node has no more than
N children. Similarly, a binary tree is a rooted tree in which each node has no more than
2 children. There is no restriction on how your encode/decode algorithm should work. You just
need to ensure that an N-ary tree can be encoded to a binary tree and this binary tree can be
decoded to the original N-nary tree structure.

For example, you may encode the following 3-ary tree to a binary tree in this way:
                1                       1
             /  |  \                   / \
           3    2   4     --->        3   2
         /   \                       /     \
        5     6                     5       4
                                     \
                                      6

Input: root = [1,null,3,2,4,null,5,6]

Note that the above is just an example which might or might not work. You do not necessarily
need to follow this format, so please be creative and come up with different approaches yourself.

Constraints:
* The height of the n-ary tree is less than or equal to 1000
* The total number of nodes is between [0, 10^4]
* Do not use class member/global/static variables to store states. Your encode and decode
algorithms should be stateless.
*/

#include "types/ds/binary_tree_nodes.hpp"
#include "types/ds/n_ary_tree_nodes.hpp"

namespace Algo::DS::Tree {
    template <typename T>
    class NAryTreeEncoder {
    public:
        static Types::DS::NodeBT<T>* encode(Types::DS::NAryTreeNode<T>* root) {
            if (root == nullptr) { return nullptr; }

            auto* r = new Types::DS::NodeBT<T>(root->val);
            auto* cur = r;
            bool first_child = true;
            for (auto c : root->children) {
                if (first_child) {
                    cur->left = encode(c);
                    cur = cur->left;
                    first_child = false;
                }
                else {
                    cur->right = encode(c);
                    cur = cur->right;
                }
            }

            return r;
        }

        static Types::DS::NAryTreeNode<T>* decode(Types::DS::NodeBT<T>* root) {
            if (root == nullptr) { return nullptr; }

            auto* r = new Types::DS::NAryTreeNode<T>(root->val);
            if (root->left == nullptr) { return r; }

            auto* cur = root->left;
            while (cur != nullptr) {
                r->children.push_back(decode(cur));
                cur = cur->right;
            }

            return r;
        }
    };
}

#endif //CPPNOTESMAIN_ENCODE_N_ARY_TREE_TO_BT_HPP
