#ifndef FIND_K_TO_LAST_ELEM_IN_SLL_HPP_
#define FIND_K_TO_LAST_ELEM_IN_SLL_HPP_

// Implement an algorithm to find the k-th to last element of a
// singly linked list.

// If k = 0 or k = 1 - return last element in list

#include <functional>

#include "types/singly_linked_list_nodes.hpp"

template<typename T>
NodeSLL<T>* FindKToLastElemRecursion(NodeSLL<T>* head, const int& k)
{
    std::function<NodeSLL<T>*(NodeSLL<T>*, const int&, int&)> findElem;
    findElem = [&findElem](NodeSLL<T>* node, const int& kth, int& i) -> NodeSLL<T>*
    {
        if (nullptr == node)
        {
            return nullptr;
        }

        NodeSLL<T>* foundNode = findElem(node->next, kth, i);
        ++i;
        if (i == kth)
        {
            // This is k-th to last element
            return node;
        }

        return foundNode;
    };

    int i = 0;
    return findElem(head, k, i);
}

template<typename T>
NodeSLL<T>* FindKToLastElemIteration(NodeSLL<T>* head, const int& k)
{
    if (nullptr == head)
    {
        return nullptr;
    }

    NodeSLL<T>* p1 = head;
    NodeSLL<T>* p2 = head;

    // Move second pointer to K position
    for (int i = 0; i < k -1; ++i)
    {
        if (nullptr == p2->next)
        {
            return nullptr;
        }

        p2 = p2->next;
    }

    // Move both pointers till p2 will not get to the end. p1 will point to
    // k-th to last element
    while(nullptr != p2->next)
    {
        p2 = p2->next;
        p1 = p1->next;
    }

    return p1;
}

#endif /* FIND_K_TO_LAST_ELEM_IN_SLL_HPP_ */
