#ifndef REMOVE_DUPLICATES_LINKED_LIST_HPP_
#define REMOVE_DUPLICATES_LINKED_LIST_HPP_

#include <unordered_set>

#include "ctci5/data_structs/singly_linked_list_nodes.hpp"

template<typename T>
void RemoveDuplicatesSLLSet(NodeSLL<T>* head)
{
    if (nullptr == head)
    {
        return;
    }

    std::unordered_set<T> set;
    NodeSLL<T>* current = head;
    NodeSLL<T>* previous = nullptr;
    while(current != nullptr)
    {
        if (0 < set.count(current->data))
        {
            NodeSLL<T>* toDelete = current;
            previous->next = current->next;
            current = current->next;

            delete toDelete;
        }
        else
        {
            set.insert(current->data);
            previous = current;
            current = current->next;
        }
    }
}

template<typename T>
void RemoveDuplicatesSLLRunner(NodeSLL<T>* head)
{
    if (nullptr == head)
    {
        return;
    }

    NodeSLL<T>* current = head;
    while(current != nullptr)
    {
        NodeSLL<T>* runner = current->next;
        NodeSLL<T>* previous = current;
        while(runner != nullptr)
        {
            if (runner->data == current->data)
            {
                NodeSLL<T>* toDelete = runner;
                previous->next = runner->next;
                runner = runner->next;

                delete toDelete;
            }
            else
            {
                previous = runner;
                runner = runner->next;
            }
        }

        current = current->next;
    }
}

#endif /* REMOVE_DUPLICATES_LINKED_LIST_HPP_ */
