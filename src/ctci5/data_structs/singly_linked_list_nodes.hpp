#ifndef SINGLY_LINKED_LIST_NODES_HPP_
#define SINGLY_LINKED_LIST_NODES_HPP_

#include <iostream>
#include <vector>

template<typename T>
class NodeSLL
{
public:
    NodeSLL(const T& d) : data(d), next(nullptr) {}

    ~NodeSLL()
    {
//        std::cout << "Delete NodeSLL with data " << data << std::endl;
    }

    T data;
    NodeSLL<T>* next;
};

template<typename T>
void AppendToSLL(NodeSLL<T>* node, const T& value)
{
    if (nullptr == node)
    {
        return;
    }

    NodeSLL<T>* newNode = new NodeSLL<T>(value);
    NodeSLL<T>* current = node;
    while(current->next != nullptr)
    {
        current = current->next;
    }

    current->next = newNode;
}

template<typename T>
void DeleteSLL(NodeSLL<T>* head)
{
    NodeSLL<T>* current = head;
    while(current != nullptr)
    {
        NodeSLL<T>* next = current->next;
        delete current;

        current = next;
    }
}

template<typename T>
std::vector<T> ValuesInSLL(NodeSLL<T>* head)
{
    NodeSLL<T>* current = head;
    std::vector<T> values;
    while(current != nullptr)
    {
        values.push_back(current->data);
        current = current->next;
    }

    return values;
}

#endif /* SINGLY_LINKED_LIST_NODES_HPP_ */
