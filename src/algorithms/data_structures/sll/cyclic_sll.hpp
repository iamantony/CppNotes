#ifndef CYCLIC_SLL_HPP
#define CYCLIC_SLL_HPP

#include "types/ds/singly_linked_list_nodes.hpp"

namespace Algo::DS::SLL {
    template <typename T>
    class CyclicSLL {
    public:
        /*
        https://leetcode.com/problems/linked-list-cycle/
        Given head, the head of a linked list, determine if the linked list has a cycle in it.

        There is a cycle in a linked list if there is some node in the list that can be reached
        again by continuously following the next pointer. Internally, pos is used to denote the
        index of the node that tail's next pointer is connected to. Note that pos is not passed
        as a parameter.

        Return true if there is a cycle in the linked list. Otherwise, return false.

        Constraints:
        * The number of the nodes in the list is in the range [0, 104].
        * -10^5 <= Node.val <= 10^5
        * pos is -1 or a valid index in the linked-list.

        Follow up: Can you solve it using O(1) (i.e. constant) memory?
        */
        static bool HasCycle(NodeSLL<T>* head) {
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

        /*
        https://leetcode.com/problems/linked-list-cycle-ii/
        Given a linked list, return the node where the cycle begins. If there is no cycle,
        return null.

        There is a cycle in a linked list if there is some node in the list that can be reached
        again by continuously following the next pointer. Internally, pos is used to denote the
        index of the node that tail's next pointer is connected to. Note that pos is not passed
        as a parameter.

        Notice that you should not modify the linked list.

        Constraints:
        * The number of the nodes in the list is in the range [0, 104].
        * -10^5 <= Node.val <= 10^5
        * pos is -1 or a valid index in the linked-list.

        Follow up: Can you solve it using O(1) (i.e. constant) memory?
        */
        static NodeSLL<T>* get_node_that_starts_cycle(NodeSLL<T>* head) {
            if (head == nullptr || head->next == nullptr) { return nullptr; }

            auto* slow  = head;
            auto* fast  = head;
            auto* entry = head;

            while (fast->next && fast->next->next) {
                slow = slow->next;
                fast = fast->next->next;
                if (slow == fast) {
                    while(slow != entry) {
                        slow  = slow->next;
                        entry = entry->next;
                    }
                    return entry;
                }
            }
            return nullptr;
        }
    };
}

#endif // CYCLIC_SLL_HPP
