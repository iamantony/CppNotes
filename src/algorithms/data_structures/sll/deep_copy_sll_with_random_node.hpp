#ifndef DEEP_COPY_SLL_WITH_RANDOM_NODE_HPP
#define DEEP_COPY_SLL_WITH_RANDOM_NODE_HPP

/*
https://leetcode.com/problems/copy-list-with-random-pointer/
A linked list is given such that each node contains an additional random pointer which could point
to any node in the list or null.

Return a deep copy of the list.

The Linked List is represented in the input/output as a list of n nodes. Each node is represented
as a pair of [val, random_index] where:
- val: an integer representing Node.val
- random_index: the index of the node (range from 0 to n-1) where random pointer points to, or
null if it does not point to any node.
*/

namespace Algo::DS::SLL {
    class DeepCopySLLWithRandomNode {
    public:
        class Node {
        public:
            int val;
            Node* next;
            Node* random;

            Node(const int value) {
                val = value;
                next = nullptr;
                random = nullptr;
            }
        };

        static Node* copy(Node* head) {
            if (head == nullptr) { return nullptr; }

            Node* current = head;
            Node* dc_head = nullptr;
            Node* dc_current = nullptr;
            std::unordered_map<Node*, Node*> nodes_map;
            while (current != nullptr) {
                Node* copy_node = new Node(current->val);
                if (dc_current == nullptr) {
                    dc_current = copy_node;
                    dc_head = copy_node;
                }
                else {
                    dc_current->next = copy_node;
                    dc_current = copy_node;
                }

                nodes_map[current] = copy_node;
                current = current->next;
            }

            current = head;
            dc_current = dc_head;
            while (current != nullptr) {
                Node* random_node = current->random;
                if (random_node != nullptr) {
                    dc_current->random = nodes_map[random_node];
                }

                current = current->next;
                dc_current = dc_current->next;
            }

            return dc_head;
        }
    };
}

#endif //DEEP_COPY_SLL_WITH_RANDOM_NODE_HPP
