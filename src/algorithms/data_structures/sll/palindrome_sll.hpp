#ifndef PALINDROME_SLL_HPP
#define PALINDROME_SLL_HPP

// https://leetcode.com/problems/palindrome-linked-list/description/

// Given a singly linked list, determine if it is a palindrome.

// Follow up:
// Could you do it in O(n) time and O(1) space?

#include "types/ds/singly_linked_list_nodes.hpp"

namespace PalindromeSLL {

class Solution {
public:

    template<typename T>
    bool isPalindrome(NodeSLL<T>* head) {
        NodeSLL<T>* pre = nullptr;
        NodeSLL<T>* fast = head;
        NodeSLL<T>* slow = head;

        //reverse list
        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            NodeSLL<T>* tmp = slow;
            slow = slow->next;
            tmp->next = pre;
            pre = tmp;
        }

        if(fast != nullptr) {
            slow = slow->next;
        }

        return isSameList(pre, slow);
    }

private:

    template<typename T>
    bool isSameList(NodeSLL<T>* firstSLL, NodeSLL<T>* secondSLL) {
        while(firstSLL != nullptr && secondSLL != nullptr) {
            if (firstSLL->value != secondSLL->value) {
                return false;
            }

            firstSLL = firstSLL->next;
            secondSLL = secondSLL->next;
        }

        return true;
    }
};

}

#endif // PALINDROME_SLL_HPP
