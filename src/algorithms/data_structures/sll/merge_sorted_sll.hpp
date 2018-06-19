#ifndef MERGE_SORTED_SLL_HPP
#define MERGE_SORTED_SLL_HPP

// https://leetcode.com/problems/merge-two-sorted-lists/description/

// Merge two sorted linked lists and return it as a new list.
// The new list should be made by splicing together the nodes of
// the first two lists.

// Example:
// Input: 1->2->4, 1->3->4
// Output: 1->1->2->3->4->4

#include "types/ds/singly_linked_list_nodes.hpp"

namespace Algo::DS::SLL {

class MergeSortedLists {
public:
    template <typename T>
    static NodeSLL<T>* Merge(NodeSLL<T>* left, NodeSLL<T>* right) {
        if (left == nullptr && right == nullptr) {
            return nullptr;
        }
        else if (left == nullptr) {
            return right;
        }
        else if (right == nullptr) {
            return left;
        }

        NodeSLL<T>* start = nullptr;
        if (left->value < right->value) {
            start = left;
            left = left->next;
        }
        else {
            start = right;
            right = right->next;
        }

        NodeSLL<T>* tail = start;
        while(left != nullptr || right != nullptr) {
            if (left != nullptr &&
                    (right == nullptr || left->value < right->value))
            {
                tail->next = left;
                left = left->next;
            }
            else {
                tail->next = right;
                right = right->next;
            }

            tail = tail->next;
        }

        return start;
    }
};

}

#endif // MERGE_SORTED_SLL_HPP
