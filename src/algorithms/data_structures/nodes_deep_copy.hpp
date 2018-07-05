#ifndef NODES_DEEP_COPY_HPP_
#define NODES_DEEP_COPY_HPP_

// Write a method that takes a pointer to a Node structure as a parameter and
// returns a complete copy of the passed in data structure. The Node data
// structure contains two pointers to other Nodes.

namespace Algo::DS {

class Node {
public:
    Node(const Node* first, const Node* second) :
        m_first(first), m_second(second) { }

    ~Node() {
        if (nullptr != m_first) {
            delete m_first;
        }

        if (nullptr != m_second) {
            delete m_second;
        }
    }

    Node* m_first = nullptr;
    Node* m_second = nullptr;
};

Node* DeepCopyOfNode(const Node* const node) {
    if (nullptr == node) {
        return nullptr;
    }

    Node* result = new Node;
    if (nullptr != node->m_first) {
        result->m_first = DeepCopyOfNode(node->m_first);
    }

    if (nullptr != node->m_second) {
        result->m_second = DeepCopyOfNode(node->m_second);
    }

    return result;
}

}

#endif /* NODES_DEEP_COPY_HPP_ */
