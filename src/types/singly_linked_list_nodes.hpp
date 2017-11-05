#ifndef SINGLY_LINKED_LIST_NODES_HPP
#define SINGLY_LINKED_LIST_NODES_HPP

#include <vector>

template<typename T>
struct NodeSLL
{
    T value;
    NodeSLL *next;

    NodeSLL(T x) : value(x), next(nullptr) {}
    ~NodeSLL()
    {
        if (next != nullptr)
        {
            delete next;
        }
    }
};

template<typename T>
NodeSLL<T>* CreateSLL(const std::vector<T>& values)
{
    NodeSLL<T>* start = nullptr;
    NodeSLL<T>* node = nullptr;

    std::for_each(values.begin(), values.end(),
                  [&start, &node](const int& value){
        if (nullptr == start)
        {
            start = new NodeSLL(value);
            node = start;
        }
        else
        {
            node->next = new NodeSLL(value);
            node = node->next;
        }
    });

    return start;
}

template<typename T>
std::vector<T> ValuesInSLL(NodeSLL<T>* node)
{
    std::vector<T> result;
    while(node != nullptr)
    {
        result.push_back(node->value);
        node = node->next;
    }

    return result;
}

#endif // SINGLY_LINKED_LIST_NODES_HPP

