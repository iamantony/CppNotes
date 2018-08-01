#ifndef CIRCULAR_QUEUE_HPP
#define CIRCULAR_QUEUE_HPP

/*
https://leetcode.com/problems/design-circular-queue/description/
Design your implementation of the circular queue. The circular queue is
a linear data structure in which the operations are performed based on
FIFO (First In First Out) principle and the last position is connected
back to the first position to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of
the spaces in front of the queue. In a normal queue, once the queue
becomes full, we cannot insert the next element even if there is a
space in front of the queue. But using the circular queue, we can
use the space to store new values.

Your implementation should support following operations:

MyCircularQueue(k): Constructor, set the size of the queue to be k.
Front: Get the front item from the queue. If the queue is empty, return -1.
Rear: Get the last item from the queue. If the queue is empty, return -1.
enQueue(value): Insert an element into the circular queue. Return
true if the operation is successful.
deQueue(): Delete an element from the circular queue. Return true
if the operation is successful.
isEmpty(): Checks whether the circular queue is empty or not.
isFull(): Checks whether the circular queue is full or not.


Example:

MyCircularQueue circularQueue = new MycircularQueue(3); // set the size to be 3
circularQueue.enQueue(1);  // return true
circularQueue.enQueue(2);  // return true
circularQueue.enQueue(3);  // return true
circularQueue.enQueue(4);  // return false, the queue is full
circularQueue.Rear();  // return 3
circularQueue.isFull();  // return true
circularQueue.deQueue();  // return true
circularQueue.enQueue(4);  // return true
circularQueue.Rear();  // return 4

Note:

All values will be in the range of [0, 1000].
The number of operations will be in the range of [1, 1000].
Please do not use the built-in Queue library.
*/

#include <vector>
#include <exception>

namespace Types::DS {

// TODO: add tests
template <typename T>
class CircularQueue {
    std::vector<T> m_data;
    bool m_full = false;
    // Position of first element
    size_t m_start = 0;
    // Position one past the last element
    size_t m_end = 0;

public:
    CircularQueue(const size_t& size) {
        m_data.resize(size, 0);
    }

    bool push(const T& value) {
        if (m_data.size() == 0 || isFull()) {
            return false;
        }

        // Check base case - queue is empty
        if (m_start == m_end) {
            m_data[m_start] = value;
            m_end = 1;
        }
        else {
            // Otherwise insert element to the end of the queue
            m_data[m_end++] = value;

            // Check if we need to move end position to the start of the vector
            m_end = (m_end >= m_data.size()) ? 0 : m_end;

            // Check if queue become full
            if (m_start == m_end) {
                m_full = true;
            }
        }

        return true;
    }

    bool pop() {
        if (isEmpty()) {
            return false;
        }

        ++m_start;
        m_full = false;
        if (m_start >= m_data.size()) {
            m_start = 0;
        }

        if (m_start == m_end) {
            m_start = m_end = 0;
        }

        return true;
    }

    T front() {
        if (isEmpty()) {
            throw std::logic_error("Circular queue is empty");
        }

        return m_data[m_start];
    }

    T back() {
        if (isEmpty()) {
            throw std::logic_error("Circular queue is empty");
        }

        return (m_end > 0) ? m_data[m_end - 1] : m_data[m_data.size() - 1];
    }

    bool isEmpty() {
        return m_data.size() == 0 || (!isFull() && m_start == m_end);
    }

    bool isFull() {
        return m_data.size() == 0 || m_full;
    }
};

}

#endif // CIRCULAR_QUEUE_HPP
