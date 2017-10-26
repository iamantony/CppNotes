#ifndef TEST_ADD_TWO_NUMBERS_AS_LINKED_LIST_HPP
#define TEST_ADD_TWO_NUMBERS_AS_LINKED_LIST_HPP

#define BOOST_TEST_MODULE CppNotes test
#include <boost/test/unit_test.hpp>

#include <memory>

#include "algorithms/add_two_numbers_as_linked_lists.hpp"

BOOST_AUTO_TEST_CASE(test_atn_empty_lists)
{
    Solution solution;
    BOOST_CHECK(solution.addTwoNumbers(nullptr, nullptr) == nullptr);

    std::shared_ptr<ListNode> result(solution.addTwoNumbers(nullptr, &ListNode(0)));
    BOOST_CHECK(result->val == 0);

    result.reset(solution.addTwoNumbers(&ListNode(5), nullptr));
    BOOST_CHECK(result->val == 5);
}

#endif // TEST_ADD_TWO_NUMBERS_AS_LINKED_LIST_HPP
