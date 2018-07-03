#ifndef DELETE_NODE_FROM_SLL_HPP_
#define DELETE_NODE_FROM_SLL_HPP_

// Implement an algorithm to delete a node in the middle of a singly
// linked list, given only access to that node.

#include "types/ds/singly_linked_list_nodes.hpp"

namespace Algo::DS::SLL {

class DeleteNode {
public:
    template<typename T>
    static void Delete(NodeSLL<T>* node) {
        if (nullptr == node) {
            return;
        }

        if (node->next == nullptr) {
            node->value = T();
        }
        else {
            NodeSLL<T>* nodeToDelete = node->next;
            node->value = nodeToDelete->value;
            node->next = nodeToDelete->next;
            delete nodeToDelete;
        }
    }
};

}

#endif /* DELETE_NODE_FROM_SLL_HPP_ */
