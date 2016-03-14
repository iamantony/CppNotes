#ifndef TYPE_QUEUE_HPP_
#define TYPE_QUEUE_HPP_

#include <queue>
#include <list>
#include <iostream>

//http://www.cplusplus.com/reference/queue/queue/
//FIFO queue
//queues are a type of container adaptor, specifically designed to operate in
//a FIFO context (first-in first-out), where elements are inserted into one end
//of the container and extracted from the other.
//
//queues are implemented as containers adaptors, which are classes that use
//an encapsulated object of a specific container class as its underlying
//container, providing a specific set of member functions to access its elements.
//Elements are pushed into the "back" of the specific container and popped
//from its "front".
//
//The underlying container may be one of the standard container
//class template or some other specifically designed container class.
//This underlying container shall support at least the following operations:
//- empty
//- size
//- front
//- back
//- push_back
//- pop_front
//
//The standard container classes deque and list fulfill these requirements.
//By default, if no container class is specified for a particular queue class
//instantiation, the standard container deque is used.

void Introduction()
{
    std::queue<int> queue;
    std::cout << "Check if queue is empty: " << std::boolalpha <<
            queue.empty() << std::endl;

    // Insert values to the queue
    queue.push(1);
    queue.push(2);
    queue.push(3);
    std::cout << "Size of the queue: " << queue.size() << std::endl;

    // Access the first element
    std::cout << "First element: " << queue.front() << std::endl;

    // Modification of the front element
    queue.front() += 10;
    std::cout << "Modification of the front element: " << queue.front() <<
                    std::endl;

    // Pop first element from the queue
    queue.pop();
    std::cout << "Next front element: " << queue.front() << std::endl;

    // Pop all elements
    queue.pop();
    queue.pop();
    std::cout << "Size of the queue: " << queue.size() << std::endl;

    // Underflow of the queue. Undefined effect, probably bad.
    // queue.pop();
}

void BaseContainer()
{
    // Standard container - deque
    std::queue<int> queue;
    std::queue<int, std::deque<int>> queueDeque;

    std::queue<int, std::list<int>> queueList;

    std::list<int> numbers = {1, 4, 7, 14};
    std::queue<int, std::list<int>> queueNumbers(numbers);

    std::cout << "Queue container based on list: ";
    const size_t queueSize = queueNumbers.size();
    for (size_t i = 0; i < queueSize; ++i, queueNumbers.pop())
    {
        std::cout << queueNumbers.front() << ", ";
    }
}

void StartQueue()
{
    Introduction();
    BaseContainer();
}

#endif /* TYPE_QUEUE_HPP_ */
