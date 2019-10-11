#ifndef TEST_MIN_STACK_HPP
#define TEST_MIN_STACK_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/data_structures/stack/min_stack.hpp"

BOOST_AUTO_TEST_CASE(test_minstack_simple)
{
    Algo::DS::Stack::MinStack<int> stack;
    stack.push(-2);
    stack.push(0);
    stack.push(-3);
    BOOST_CHECK(-3 == stack.getMin());
    stack.pop();
    BOOST_CHECK(0 == stack.top());
    BOOST_CHECK(-2 == stack.getMin());
}

#endif // TEST_MIN_STACK_HPP
