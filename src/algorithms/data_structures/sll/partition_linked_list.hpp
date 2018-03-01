#ifndef PARTITION_LINKED_LIST_HPP_
#define PARTITION_LINKED_LIST_HPP_

// Write code to partition a linked list around a value x, such that all nodes
// less than x come before all nodes greater than or equal to x.

#include <iostream>

#include "types/ds/singly_linked_list_nodes.hpp"

template<typename T>
void PartitionSLLOnePass(NodeSLL<T>** head, const T& value)
{
    if (nullptr == head) {
        return;
    }

    NodeSLL<T>* beforeStart = nullptr;
    NodeSLL<T>* beforeEnd = nullptr;

    NodeSLL<T>* afterStart = nullptr;
    NodeSLL<T>* afterEnd = nullptr;

    NodeSLL<T>* current = *head;
    while(nullptr != current) {
        NodeSLL<T>* next = current->next;
        current->next = nullptr;
        if (current->value < value) {
            if (nullptr == beforeStart) {
                beforeStart = current;
                beforeEnd = beforeStart;
            }
            else {
                beforeEnd->next = current;
                beforeEnd = current;
            }
        }
        else {
            if (nullptr == afterStart) {
                afterStart = current;
                afterEnd = afterStart;
            }
            else {
                afterEnd->next = current;
                afterEnd = current;
            }
        }

        current = next;
    }

    // Set up head node
    if (nullptr == beforeStart) {
        *head = afterStart;
    }
    else {
        beforeEnd->next = afterStart;
        *head = beforeStart;
    }

    // Set up next to the last node to nullptr
    if (nullptr != afterEnd) {
        afterEnd->next = nullptr;
    }
}

template<typename T>
void PartitionSLLTwoPass(NodeSLL<T>*& head, const T& value) {
    NodeSLL<T>* beforeStart = nullptr;
    NodeSLL<T>* afterStart = nullptr;

    NodeSLL<T>* current = head;
    while(nullptr != current) {
        NodeSLL<T>* next = current->next;
        if (current->value < value) {
            current->next = beforeStart;
            beforeStart = current;
        }
        else {
            current->next = afterStart;
            afterStart = current;
        }

        current = next;
    }

    if (nullptr == beforeStart) {
        head = afterStart;
    }
    else {
        NodeSLL<T>* beforeEnd = beforeStart;
        while(nullptr != beforeEnd->next) {
            beforeEnd = beforeEnd->next;
        }

        beforeEnd->next = afterStart;
        head = beforeStart;
    }
}

#endif /* PARTITION_LINKED_LIST_HPP_ */
