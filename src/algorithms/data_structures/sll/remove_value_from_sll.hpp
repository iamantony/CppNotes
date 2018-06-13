#ifndef REMOVE_VALUE_FROM_SLL_HPP
#define REMOVE_VALUE_FROM_SLL_HPP

// https://leetcode.com/problems/remove-linked-list-elements/description/

//Remove all elements from a linked list of integers that have value val.

//Example:
//Input:  1->2->6->3->4->5->6, val = 6
//Output: 1->2->3->4->5

#include "types/ds/singly_linked_list_nodes.hpp"

namespace Algo { namespace DS { namespace SLL {

class RemoveValue {
public:
    template<typename T>
    static NodeSLL<T>* remove(NodeSLL<T>* node, const T& value) {
        NodeSLL<T> dummy = NodeSLL<T>(0);
        dummy.next = node;

        NodeSLL<T>* prev = &dummy;
        NodeSLL<T>* current = node;
        while (current != nullptr) {
            if (current->value == value) {
                prev->next = current->next;
                delete current;
                current = prev->next;
            }
            else {
                current = current->next;
                prev = prev->next;
            }
        }

        return dummy.next;
    }
};

} } }

#endif // REMOVE_VALUE_FROM_SLL_HPP
