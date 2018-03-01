#ifndef DELETE_K_TO_LAST_ELEM_IN_SLL_HPP
#define DELETE_K_TO_LAST_ELEM_IN_SLL_HPP

// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
// Given a linked list, remove the nth node from the end of list and return
// its head.

// For example:
// Given linked list: 1->2->3->4->5, and n = 2.
// After removing the second node from the end, the linked list becomes
// 1->2->3->5.

#include "types/ds/singly_linked_list_nodes.hpp"

namespace DeleteKToLastElem {
class Solution {
public:
    template<typename T>
    NodeSLL<T>* deleteKthFromEnd(NodeSLL<T>* head, int k) {
        // Create dummy node and put it ahead of the start of the list.
        // It will be start point in our node couting process
        NodeSLL<T> dummy = NodeSLL<T>(0);
        dummy.next = head;

        NodeSLL<T>* current = &dummy;
        NodeSLL<T>* match = &dummy;
        // Advances 'current' pointer so that the gap between 'current' and
        // 'match' is n nodes apart
        for (int i = 1; i <= k + 1; ++i) {
            current = current->next;
        }

        // Move 'current' to the end, maintaining the gap
        while(current != nullptr) {
            current = current->next;
            match = match->next;
        }

        NodeSLL<T>* nodeToDelete = match->next;
        match->next = match->next->next;
        delete nodeToDelete;

        return dummy.next;
    }
};
}

#endif // DELETE_K_TO_LAST_ELEM_IN_SLL_HPP
