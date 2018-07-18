#ifndef QUEUE_USING_STACKS_HPP
#define QUEUE_USING_STACKS_HPP

// https://leetcode.com/problems/implement-queue-using-stacks/description/

/*
Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.

Example:

MyQueue queue = new MyQueue();
queue.push(1);
queue.push(2);
queue.peek();  // returns 1
queue.pop();   // returns 1
queue.empty(); // returns false

Notes:
You must use only standard operations of a stack -- which means only push to
top, peek/pop from top, size, and is empty operations are valid.

Depending on your language, stack may not be supported natively. You may
simulate a stack by using a list or deque (double-ended queue), as long as you
use only standard operations of a stack.

You may assume that all operations are valid (for example, no pop or peek
operations will be called on an empty queue).
*/

#include <stack>

namespace Types::DS {

class QueueUT {
    std::stack<int> m_input, m_output;

public:
    QueueUT() {

    }

    void push(int x) {
        m_input.push(x);
    }

    int pop() {
        MoveElements();

        int result = m_output.top();
        m_output.pop();
        return result;
    }

    int peek() {
        MoveElements();
        return m_output.top();
    }

    bool empty() {
        return m_input.empty() && m_output.empty();
    }

private:
    void MoveElements() {
        if (m_output.empty()) {
            while(!m_input.empty()) {
                m_output.push(m_input.top());
                m_input.pop();
            }
        }
    }
};

}

#endif // QUEUE_USING_STACKS_HPP
