#ifndef MAX_DEPTH_OF_BT_HPP
#define MAX_DEPTH_OF_BT_HPP

// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

// Given a binary tree, find its maximum depth.

// The maximum depth is the number of nodes along the longest path from the
// root node down to the farthest leaf node.

// For example:
// Given binary tree [3,9,20,null,null,15,7],

/*
     3
    / \
   9  20
   /   \
  15    7
*/

// return its depth = 3.

#include "types/ds/binary_tree_nodes.hpp"

namespace Algo { namespace DS { namespace BT {

class MaxDepth {
public:
    template<typename T>
    static int Depth(NodeBT<T>* root) {
        return DepthHelper(root);
    }

private:
    template<typename T>
    static int DepthHelper(NodeBT<T>* root) {
        if (root == nullptr) {
            return 0;
        }

        return 1 + std::max(DepthHelper(root->left),
                            DepthHelper(root->right));
    }
};

} } }

#endif // MAX_DEPTH_OF_BT_HPP
