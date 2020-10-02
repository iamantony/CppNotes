#ifndef CPPNOTESMAIN_CHECK_IF_TREE_CONTAINS_SUBTREE_HPP
#define CPPNOTESMAIN_CHECK_IF_TREE_CONTAINS_SUBTREE_HPP

/*
Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and
node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this
node's descendants. The tree s could also be considered as a subtree of itself.

Example 1:
Given tree s:
     3
    / \
   4   5
  / \
 1   2

Given tree t:
   4
  / \
 1   2

Return true, because t has the same structure and node values with a subtree of s.

Example 2:
Given tree s:
     3
    / \
   4   5
  / \
 1   2
    /
   0

Given tree t:
   4
  / \
 1   2

Return false.
*/

#include "types/ds/binary_tree_nodes.hpp"

namespace Algo::DS::BT {
    class CheckTree {

        template<typename T>
        static bool equal(Types::DS::NodeBT<T>* s, Types::DS::NodeBT<T>* t){
            if(s == nullptr && t == nullptr) { return true; }
            if(s == nullptr || t == nullptr) { return false; }

            return s->value == t->value && equal(s->left, t->left) && equal(s->right, t->right);
        }

        template<typename T>
        static bool traverse(Types::DS::NodeBT<T>* s, Types::DS::NodeBT<T>* t){
            return s != nullptr && (equal(s,t) || traverse(s->left, t) || traverse(s->right, t));
        }

    public:
        template<typename T>
        static bool contains_subtree(Types::DS::NodeBT<T>* t, Types::DS::NodeBT<T>* s) {
            return traverse<T>(t, s);
        }
    };
}

#endif //CPPNOTESMAIN_CHECK_IF_TREE_CONTAINS_SUBTREE_HPP
