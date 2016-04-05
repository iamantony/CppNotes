#ifndef SINGLY_LINKED_LIST_NODES_HPP_
#define SINGLY_LINKED_LIST_NODES_HPP_

template <typename T>
class NodeSLL
{
public:
    NodeSLL(const T& d) : data(d), next(nullptr) {}

    T data;
    NodeSLL* next;
};

template <typename T>
void AppendToSLLN(NodeSLL<T>* node, const T& value)
{
    if (nullptr == node)
    {
        return;
    }

    NodeSLL<T>* newNode = new NodeSLL<T>(value);
    NodeSLL* current = node;
    while(current->next != nullptr)
    {
        current = current->next;
    }

    current->next = newNode;
}

#endif /* SINGLY_LINKED_LIST_NODES_HPP_ */
