#ifndef BT_LEVEL_ORDER_TRAVERSAL_HPP
#define BT_LEVEL_ORDER_TRAVERSAL_HPP

// https://leetcode.com/problems/binary-tree-level-order-traversal/description/

/*
Given a binary tree, return the level order traversal of its nodes' values.
(ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7

return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
*/

#include <queue>

#include "types/ds/binary_tree_nodes.hpp"

namespace Algo::DS::BT {

class LevelOrderTraversal {
public:
    template<typename T>
    static std::vector<std::vector<T>> Traverse(Types::DS::NodeBT<T>* root) {
        std::vector<std::vector<T>> result;
        if (root == nullptr) {
            return result;
        }

        std::queue< Types::DS::NodeBT<T>* > nodesQueue;
        nodesQueue.push(root);
        while (!nodesQueue.empty()) {
            std::queue< Types::DS::NodeBT<T>* > nextLevelNodes;
            std::vector<T> levelElements;
            while (!nodesQueue.empty()) {
                Types::DS::NodeBT<T>* node = nodesQueue.front();
                nodesQueue.pop();

                levelElements.push_back(node->value);

                if (node->left != nullptr) {
                    nextLevelNodes.push(node->left);
                }

                if (node->right != nullptr) {
                    nextLevelNodes.push(node->right);
                }
            }

            result.push_back(levelElements);
            nodesQueue = nextLevelNodes;
        }

        return result;
    }
};

}

#endif // BT_LEVEL_ORDER_TRAVERSAL_HPP
