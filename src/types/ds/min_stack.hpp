#ifndef MIN_STACK_HPP
#define MIN_STACK_HPP

/*
https://leetcode.com/problems/min-stack/
Design a stack that supports push, pop, top, and retrieving the minimum element
in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/

#include <stack>
#include <limits>

namespace Types::DS::Stack {

template <typename T>
class MinStack {
    std::stack<T> m_data;
    std::stack<T> m_min_data;

public:
    void push(const int x) {
        m_data.push(x);
        const auto min_value =
            m_min_data.empty() ? std::numeric_limits<T>::max() : m_min_data.top();
        m_min_data.push(std::min(x, min_value));
    }

    void pop() {
        if (m_data.empty()) { return; }

        m_data.pop();
        m_min_data.pop();
    }

    int top() {
        return m_data.top();
    }

    int getMin() {
        return m_min_data.top();
    }
};
}

#endif // MIN_STACK_HPP
