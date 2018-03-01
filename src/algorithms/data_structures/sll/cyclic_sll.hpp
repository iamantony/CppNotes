#ifndef CYCLIC_SLL_HPP
#define CYCLIC_SLL_HPP

// https://leetcode.com/problems/linked-list-cycle/description/

// Given a linked list, determine if it has a cycle in it.

// Follow up:
// Can you solve it without using extra space?

// Easy solution - use hash set. Iterate over SLL, putting new nodes into set,
// and check if it already have same node. Time complexity: O(n); space
// complexity: O(n)

// More interesting solution - is to use two pointers: slow and fast.
// If SLL is not cyclic, fast pointer will reach end of SLL.
// If SLL is cyclic, fast pointer will catch up slow pointer.
// Time complexity: O(n); space complexity: O(1)

#include "types/ds/singly_linked_list_nodes.hpp"

namespace CyclicSLL {

class Solution {
public:

    template<typename T>
    bool hasCycle(NodeSLL<T>* head) {
        if (head == nullptr) {
            return false;
        }

        NodeSLL<T>* slow = head;
        NodeSLL<T>* fast = head->next;
        while(fast != nullptr && fast->next != nullptr) {
            if (slow == fast) {
                return true;
            }

            slow = slow->next;
            fast = fast->next->next;
        }

        return false;
    }
};

}

#endif // CYCLIC_SLL_HPP
