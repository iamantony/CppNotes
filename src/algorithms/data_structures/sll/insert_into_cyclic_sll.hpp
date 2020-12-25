#ifndef CPPNOTESMAIN_INSERT_INTO_CYCLIC_SLL_HPP
#define CPPNOTESMAIN_INSERT_INTO_CYCLIC_SLL_HPP

/*
https://leetcode.com/problems/insert-into-a-sorted-circular-linked-list/
Given a node from a Circular Linked List which is sorted in ascending order, write a function to
insert a value insertVal into the list such that it remains a sorted circular list. The given node
can be a reference to any single node in the list, and may not be necessarily the smallest value
in the circular list.

If there are multiple suitable places for insertion, you may choose any place to insert the new
value. After the insertion, the circular list should remain sorted.

If the list is empty (i.e., given node is null), you should create a new single circular list
and return the reference to that single node. Otherwise, you should return the original given node.

Example 1:
Input: head = [3,4,1], insertVal = 2
Output: [3,4,1,2]
Explanation: In the figure above, there is a sorted circular list of three elements.
You are given a reference to the node with value 3, and we need to insert 2 into the list.
The new node should be inserted between node 1 and node 3. After the insertion, the list should
look like this, and we should still return node 3.

Example 2:
Input: head = [], insertVal = 1
Output: [1]
Explanation: The list is empty (given head is null). We create a new single circular list and
return the reference to that single node.

Example 3:
Input: head = [1], insertVal = 0
Output: [1,0]
*/

#include "types/ds/singly_linked_list_nodes.hpp"

namespace Algo::DS::SLL {
    template <typename T>
    class InsertIntoSLL {
    public:
        static NodeSLL<T>* insert(NodeSLL<T>* head, T insertVal) {
            auto* new_node = new NodeSLL<T>(insertVal);
            if (head == nullptr) {
                head = new_node;
                head->next = head;
                return head;
            }

            if (head == head->next) {
                head->next = new_node;
                new_node->next = head;
                return head;
            }

            bool insert = false;
            auto* cur = head;
            auto* next = head->next;
            do {
                auto& c = cur->val;
                auto& n = next->val;
                if (c <= insertVal && insertVal <= n) {
                    insert = true;
                } else if (c > n && (insertVal >= c || insertVal <= n)) {
                    insert = true;
                }

                if (insert) {
                    cur->next = new_node;
                    new_node->next = next;
                    return head;
                }

                cur = cur->next;
                next = next->next;
            } while (cur != head);

            cur->next = new_node;
            new_node->next = next;
            return head;
        }
    };
}

#endif //CPPNOTESMAIN_INSERT_INTO_CYCLIC_SLL_HPP
