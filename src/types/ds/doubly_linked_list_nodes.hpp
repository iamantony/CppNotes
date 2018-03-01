#ifndef DOUBLY_LINKED_LIST_NODES_HPP_
#define DOUBLY_LINKED_LIST_NODES_HPP_

#include <vector>

template <typename T>
class NodeDLL
{
public:
    NodeDLL(const T& d) : data(d), prev(nullptr), next(nullptr) {}

    T data;
    NodeDLL* prev, next;
};

template<typename T>
void DeleteDLL(NodeDLL<T>* head)
{
    NodeDLL<T>* current = head;
    while(current->prev != nullptr)
    {
        current = current->prev;
    }

    while(current != nullptr)
    {
        NodeDLL<T>* next = current->next;
        delete current;

        current = next;
    }
}

template<typename T>
std::vector<T> ValuesInDLL(NodeDLL<T>* head)
{
    NodeDLL<T>* current = head;
    while(current->prev != nullptr)
    {
        current = current->prev;
    }

    std::vector<T> values;
    while(current != nullptr)
    {
        values.push_back(current->data);
        current = current->next;
    }

    return values;
}

#endif /* DOUBLY_LINKED_LIST_NODES_HPP_ */
