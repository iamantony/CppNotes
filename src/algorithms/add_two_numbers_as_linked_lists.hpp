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

#include <vector>
#include <algorithm>

namespace AddTwoNumbers
{

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ~ListNode()
    {
        if (next != nullptr)
        {
            delete next;
        }
    }
};

ListNode* CreateLinkedList(const std::vector<int>& values);
std::vector<int> LinkedListToVector(ListNode* node);

class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* start = nullptr;
        ListNode* node = nullptr;
        int carry = 0;
        while(true)
        {
            if (l1 == nullptr &&
                    l2 == nullptr &&
                    carry == 0)
            {
                break;
            }
            else
            {
                ListNode* nextNode = new ListNode(0);
                if (start == nullptr)
                {
                    start = nextNode;
                    node = start;
                }
                else
                {
                    node->next = nextNode;
                    node = nextNode;
                }
            }

            int sum = (l1 == nullptr ? 0 : l1->val) +
                        (l2 == nullptr ? 0 : l2->val) +
                        carry;

            node->val = sum % 10;
            carry = sum / 10;

            l1 != nullptr ? l1 = l1->next : l1;
            l2 != nullptr ? l2 = l2->next : l2;
        }

        return start;
    }
};

ListNode* CreateLinkedList(const std::vector<int>& values)
{
    ListNode* start = nullptr;
    ListNode* node = nullptr;

    std::for_each(values.begin(), values.end(),
                  [&start, &node](const int& value){
        if (nullptr == start)
        {
            start = new ListNode(value);
            node = start;
        }
        else
        {
            node->next = new ListNode(value);
            node = node->next;
        }
    });

    return start;
}

std::vector<int> LinkedListToVector(ListNode* node)
{
    std::vector<int> result;
    while(node != nullptr)
    {
        result.push_back(node->val);
        node = node->next;
    }

    return result;
}

}

#endif // ADD_TWO_NUMBERS_AS_LINKED_LISTS_HPP
