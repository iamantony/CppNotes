#ifndef DELETE_NODE_FROM_SLL_HPP_
#define DELETE_NODE_FROM_SLL_HPP_

// Implement an algorithm to delete a node in the middle of a singly
// linked list, given only access to that node.

#include "ctci5/data_structs/singly_linked_list_nodes.hpp"

template<typename T>
void DeleteNodeFromSLL(NodeSLL<T>* node)
{
    if (nullptr == node)
    {
        return;
    }

    NodeSLL<T>* current = node;
    NodeSLL<T>* previous = node;
    while(current != nullptr)
    {
        // Is current node last node?
        if (nullptr == current->next)
        {
            // If we don't know who is previous node, then we can not delete
            // this node. All we can is to reset data in it.
            if (current == previous)
            {
                current->data = T();
                break;
            }
            else
            {
                // Else we just delete current node
                delete current;
                current = nullptr;
                previous->next = nullptr;
            }
        }
        else
        {
            current->data = current->next->data;
            if (current != previous)
            {
                previous = current;
            }

            current = current->next;
        }
    }
}

#endif /* DELETE_NODE_FROM_SLL_HPP_ */
