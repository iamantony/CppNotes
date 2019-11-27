#include <boost/test/unit_test.hpp>

#include "types/ds/min_stack.hpp"

BOOST_AUTO_TEST_SUITE(MinStack)

BOOST_AUTO_TEST_CASE(simple)
{
    Types::DS::Stack::MinStack<int> stack;
    stack.push(-2);
    stack.push(0);
    stack.push(-3);
    BOOST_CHECK(-3 == stack.getMin());
    stack.pop();
    BOOST_CHECK(0 == stack.top());
    BOOST_CHECK(-2 == stack.getMin());
}

BOOST_AUTO_TEST_SUITE_END()
