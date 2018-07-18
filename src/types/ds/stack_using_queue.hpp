#ifndef STACK_USING_QUEUE_HPP
#define STACK_USING_QUEUE_HPP

// https://leetcode.com/problems/implement-stack-using-queues/description/

/*
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.

Example:
MyStack stack = new MyStack();
stack.push(1);
stack.push(2);
stack.top();   // returns 2
stack.pop();   // returns 2
stack.empty(); // returns false

Notes:
You must use only standard operations of a queue -- which means only push to
back, peek/pop from front, size, and is empty operations are valid.

Depending on your language, queue may not be supported natively. You may
simulate a queue by using a list or deque (double-ended queue), as long as you
use only standard operations of a queue.

You may assume that all operations are valid (for example, no pop or top
operations will be called on an empty stack).
*/

#include <queue>

namespace Types::DS {

class StackUQ {
    std::queue<int> m_queue;

public:
    StackUQ() {

    }

    void push(int x) {
        std::queue<int> tmp;
        tmp.push(x);

        while(!m_queue.empty()) {
            tmp.push(m_queue.front());
            m_queue.pop();
        }

        m_queue = tmp;
    }

    int pop() {
        int result = m_queue.front();
        m_queue.pop();
        return result;
    }

    int top() {
        return m_queue.front();
    }

    bool empty() {
        return m_queue.empty();
    }
};

}

#endif // STACK_USING_QUEUE_HPP
