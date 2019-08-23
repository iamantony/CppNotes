#ifndef ADD_TWO_NUMBERS_AS_LINKED_LISTS_HPP
#define ADD_TWO_NUMBERS_AS_LINKED_LISTS_HPP

// https://leetcode.com/problems/add-two-numbers/description/
// You are given two non-empty linked lists representing two non-negative
// integers. The digits are stored in reverse order and each of their nodes
// contain a single digit. Add the two numbers and return it as a linked list.

// You may assume the two numbers do not contain any leading zero, except the
// number 0 itself.

// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8

#include <algorithm>

#include "types/ds/singly_linked_list_nodes.hpp"

namespace Algo::DS::SLL {

template <typename T>
class AddNumbersSLL {
public:
    static NodeSLL<T>* Add(NodeSLL<T>* l1, NodeSLL<T>* l2) {
        NodeSLL<T>* start = nullptr;
        NodeSLL<T>* node = nullptr;
        int carry = 0;
        while(true) {
            if (l1 == nullptr && l2 == nullptr && carry == 0) {
                break;
            }
            else {
                NodeSLL<T>* nextNode = new NodeSLL<T>(0);
                if (start == nullptr) {
                    start = node = nextNode;
                }
                else {
                    node->next = nextNode;
                    node = node->next;
                }
            }

            int sum = (l1 == nullptr ? 0 : l1->value) +
                        (l2 == nullptr ? 0 : l2->value) +
                        carry;

            node->value = sum % 10;
            carry = sum / 10;

            l1 != nullptr ? l1 = l1->next : l1;
            l2 != nullptr ? l2 = l2->next : l2;
        }

        return start;
    }
};

}

#endif // ADD_TWO_NUMBERS_AS_LINKED_LISTS_HPP
