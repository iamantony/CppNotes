#ifndef TYPES_STACK_HPP_
#define TYPES_STACK_HPP_

#include <stack>
#include <vector>
#include <list>
#include <iostream>

// http://www.cplusplus.com/reference/stack/stack/
// Stacks are a type of container adaptor, specifically designed to operate in
// a LIFO context (last-in first-out), where elements are inserted and
// extracted only from one end of the container.

// stacks are implemented as containers adaptors, which are classes that use an
// encapsulated object of a specific container class as its underlying
// container, providing a specific set of member functions to access its
// elements. Elements are pushed/popped from the "back" of the specific
// container, which is known as the top of the stack.

// The underlying container may be any of the standard container class
// templates or some other specifically designed container class. The container
// shall support the following operations:
// - empty
// - size
// - back
// - push_back
// - pop_back
//
// The standard container classes vector, deque and list fulfill these
// requirements. By default, if no container class is specified for a
// particular stack class instantiation, the standard container deque is used.

void Introduction()
{
    std::stack<int> stack;
    std::cout << "Check if stack is empty: " << std::boolalpha <<
                    stack.empty() << std::endl;

    // Insert values to the stack
    stack.push(1);
    stack.push(2);
    stack.push(3);
    std::cout << "Size of the stack: " << stack.size() << std::endl;

    // Access top (last inserted) element
    std::cout << "Top element: " << stack.top() << std::endl;

    // Modification of the top element
    stack.top() += 10;
    std::cout << "Modification of the top element: " << stack.top() <<
                    std::endl;

    // Pop top element from the stack
    stack.pop();
    std::cout << "Next top element: " << stack.top() << std::endl;

    // Pop all elements
    stack.pop();
    stack.pop();
    std::cout << "Size of the stack: " << stack.size() << std::endl;
    // Underflow of the stack. Undefined effect, probably bad.
    // stack.pop();
}

void BaseContainer()
{
    // Standard container - deque
    std::stack<int> stack;
    std::stack<int, std::deque<int>> stackDeque;

    std::stack<int, std::vector<int>> stackVector;
    std::stack<int, std::list<int>> stackList;
}

void StartStack()
{
    Introduction();
    BaseContainer();
}

#endif /* TYPES_STACK_HPP_ */
