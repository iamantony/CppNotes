#ifndef FIND_MIDDLE_OF_SLL_HPP
#define FIND_MIDDLE_OF_SLL_HPP

// Find middle of the Singly Linked List

#include "types/ds/singly_linked_list_nodes.hpp"

namespace Algo::DS::SLL {

class FindMiddleElement {
public:
    template<typename T>
    static NodeSLL<T>* Find(NodeSLL<T>* head) {
        if (nullptr == head) {
            return nullptr;
        }

        NodeSLL<T>* slowPtr = head;
        NodeSLL<T>* fastPtr = head;
        while(fastPtr != nullptr && fastPtr->next != nullptr) {
            fastPtr = fastPtr->next->next; // move by two elements
            slowPtr = slowPtr->next; // move by one element
        }

        return slowPtr;
    }
};

}

#endif // FIND_MIDDLE_OF_SLL_HPP
