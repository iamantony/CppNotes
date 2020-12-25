#ifndef CPPNOTESMAIN_ROTATE_SLL_BY_K_HPP
#define CPPNOTESMAIN_ROTATE_SLL_BY_K_HPP

/*
https://leetcode.com/problems/rotate-list/
Given the head of a linked list, rotate the list to the right by k places.

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Example 2:
Input: head = [0,1,2], k = 4
Output: [2,0,1]

Constraints:
* The number of nodes in the list is in the range [0, 500].
* -100 <= Node.val <= 100
* 0 <= k <= 2 * 10^9

*/

#include "types/ds/singly_linked_list_nodes.hpp"

namespace Algo::DS::SLL {
    class RotateSLL {
    public:
        static NodeSLL<T>* rotate_by_k(NodeSLL<T>* head, int k) {
            if (head == nullptr || head->next == nullptr || k <= 0) { return head; }

            size_t size = 0;
            {
                auto* cur = head;
                while (cur != nullptr) {
                    cur = cur->next;
                    ++size;
                }
            }

            size_t kk = static_cast<size_t>(k) % size;
            if (kk == 0) { return head; }

            const auto skip_num = size - kk - 1;
            size_t count = 0;
            auto* cur = head;
            while (count != skip_num) {
                cur = cur->next;
                ++count;
            }

            auto* new_head = cur->next;
            cur->next = nullptr;
            cur = new_head;
            while (cur->next != nullptr) {
                cur = cur->next;
            }

            cur->next = head;
            return new_head;
        }
    };
}

#endif //CPPNOTESMAIN_ROTATE_SLL_BY_K_HPP
