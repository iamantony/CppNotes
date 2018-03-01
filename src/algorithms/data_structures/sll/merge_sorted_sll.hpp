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

namespace MergeSLL {

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr && l2 == nullptr) {
            return nullptr;
        }
        else if (l1 == nullptr) {
            return l2;
        }
        else if (l2 == nullptr) {
            return l1;
        }

        ListNode* start = nullptr;
        if (l1->value > l2->value) {
            start = l2;
            l2 = l2->next;
        }
        else {
            start = l1;
            l1 = l1->next;
        }

        ListNode* tail = start;
        while(l1 != nullptr || l2 != nullptr) {
            if (l1 == nullptr) {
                tail->next = l2;
                l2 = l2->next;
            }
            else if (l2 == nullptr) {
                tail->next = l1;
                l1 = l1->next;
            }
            else {
                if (l1->value > l2->value) {
                    tail->next = l2;
                    l2 = l2->next;
                }
                else {
                    tail->next = l1;
                    l1 = l1->next;
                }
            }

            tail = tail->next;
        }


        return start;
    }
};

}

#endif // MERGE_SORTED_SLL_HPP
