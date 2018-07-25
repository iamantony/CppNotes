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

// TODO: refactoring, add tests
class MyCircularQueue {
    std::vector<int> m_v;
    // Position with first element
    size_t start = 0;
    // Position one past the last element
    size_t end = 0;
    bool full = false;
    
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        if (k <= 0) {
            throw std::invalid_argument("Invalid arg");
        }
        
        m_v.resize(static_cast<size_t>(k), 0);
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        
        // Check base case - queue is empty
        if (start == end) {
            m_v[start] = value;
            end = 1;
        }
        else {
            m_v[end++] = value;
            end = (end >= m_v.size()) ? 0 : end;
            
            if (start == end) {
                full = true;
            }
        }
        
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        
        ++start;
        full = false;
        if (start >= m_v.size()) {
            start = 0;
        }
        
        if (start == end) {
            start = end = 0;
        }
        
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        
        return m_v[start];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        
        return (end > 0) ? m_v[end - 1] : m_v[m_v.size() - 1];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return !isFull() && start == end;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return full;
    }
};
