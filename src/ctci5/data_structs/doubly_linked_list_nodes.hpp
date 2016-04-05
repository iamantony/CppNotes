#ifndef DOUBLY_LINKED_LIST_NODES_HPP_
#define DOUBLY_LINKED_LIST_NODES_HPP_

template <typename T>
class NodeDLL
{
public:
    NodeDLL(const T& d) : data(d), prev(nullptr) next(nullptr) {}

    T data;
    NodeDLL* prev, next;
};



#endif /* DOUBLY_LINKED_LIST_NODES_HPP_ */
