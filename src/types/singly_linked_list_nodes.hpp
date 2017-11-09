#ifndef SINGLY_LINKED_LIST_NODES_HPP
#define SINGLY_LINKED_LIST_NODES_HPP

#include <vector>

template<typename T>
class NodeSLL {
public:
    NodeSLL(T x) : value(x), next(nullptr) {}

    T value;
    NodeSLL* next;
};

template<typename T>
void AppendToSLL(NodeSLL<T>** head, const T& value) {
    if (nullptr == head) {
        return;
    }

    NodeSLL<T>* newNode = new NodeSLL<T>(value);
    NodeSLL<T>* current = *head;

    // Move to the last node
    while(current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;
}

template<typename T>
NodeSLL<T>* CreateSLL(const std::vector<T>& values) {
    NodeSLL<T>* start = nullptr;
    NodeSLL<T>* node = nullptr;

    std::for_each(values.begin(), values.end(),
                  [&start, &node](const int& value){
        if (nullptr == start) {
            start = new NodeSLL<T>(value);
            node = start;
        }
        else {
            node->next = new NodeSLL<T>(value);
            node = node->next;
        }
    });

    return start;
}

template<typename T>
std::vector<T> ValuesInSLL(NodeSLL<T>** head) {
    if (nullptr == head) {
        return std::vector<T>();
    }

    std::vector<T> result;
    NodeSLL<T>* current = *head;
    while(current != nullptr) {
        result.push_back(current->value);
        current = current->next;
    }

    return result;
}

template<typename T>
void DeleteSLL(NodeSLL<T>** head) {
    if (nullptr == head) {
        return;
    }

    NodeSLL<T>* current = *head;
    while(nullptr != current) {
        NodeSLL<T>* next = current->next;
        delete current;
        current = next;
    }

    *head = nullptr;
}

#endif // SINGLY_LINKED_LIST_NODES_HPP

