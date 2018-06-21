#ifndef REVERSE_SLL_HPP
#define REVERSE_SLL_HPP

// https://leetcode.com/problems/reverse-linked-list/description/
// Reserse singly linked list

#include "types/ds/singly_linked_list_nodes.hpp"

namespace Algo::DS::SLL {

class Reverse {
public:

    // Time complexity: O(n)
    // Space complexity: O(1)
    template<typename T>
    static NodeSLL<T>* ReverseIterative(NodeSLL<T>* head) {
        NodeSLL<T>* current = head;
        NodeSLL<T>* prev = nullptr;
        while(nullptr != current) {
            NodeSLL<T>* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }

    // Time complexity: O(n). Assume that n is the list's length
    // Space complexity: O(n). The extra space comes from implicit stack space
    // due to recursion. The recursion could go up to n levels deep.
    template<typename T>
    static NodeSLL<T>* ReverseRecursive(NodeSLL<T>* head) {
        if (nullptr == head || nullptr == head->next) {
            return head;
        }

        NodeSLL<T>* node = ReverseRecursive(head->next);
        head->next->next = head;
        head->next = nullptr;
        return node;
    }
};

}

#endif // REVERSE_SLL_HPP

