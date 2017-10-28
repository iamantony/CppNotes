#ifndef TEST_ADD_TWO_NUMBERS_AS_LINKED_LIST_HPP
#define TEST_ADD_TWO_NUMBERS_AS_LINKED_LIST_HPP

#define BOOST_TEST_MODULE CppNotes test
#include <boost/test/unit_test.hpp>

#include <memory>

#include "algorithms/add_two_numbers_as_linked_lists.hpp"

BOOST_AUTO_TEST_CASE(test_atn_empty_lists)
{
    AddTwoNumbers::Solution solution;
    BOOST_CHECK(solution.addTwoNumbers(nullptr, nullptr) == nullptr);

    AddTwoNumbers::ListNode shortList(0);
    std::shared_ptr<AddTwoNumbers::ListNode> result(solution.addTwoNumbers(nullptr, &shortList));
    BOOST_CHECK(result->val == 0);

    shortList.val = 5;
    result.reset(solution.addTwoNumbers(&shortList, nullptr));
    BOOST_CHECK(result->val == 5);
}

BOOST_AUTO_TEST_CASE(test_atn_equal_size_lists)
{
    std::vector<int> valuesForFirstList = {0, 1, 2, 3, 4};
    std::vector<int> valuesForSecondList = {8, 7, 9, 9, 4};
    std::vector<int> valuesForExpectedList = {8, 8, 1, 3, 9};

    std::shared_ptr<AddTwoNumbers::ListNode> firstList(
                AddTwoNumbers::CreateLinkedList(valuesForFirstList));

    std::shared_ptr<AddTwoNumbers::ListNode> secondList(
                AddTwoNumbers::CreateLinkedList(valuesForSecondList));

    AddTwoNumbers::Solution solution;
    std::shared_ptr<AddTwoNumbers::ListNode> result(
                solution.addTwoNumbers(firstList.get(), secondList.get()));

    BOOST_CHECK(valuesForExpectedList ==
                AddTwoNumbers::LinkedListToVector(result.get()));
}

BOOST_AUTO_TEST_CASE(test_atn_equal_size_lists_with_carry)
{
    std::vector<int> valuesForFirstList = {0, 1, 2, 3, 4};
    std::vector<int> valuesForSecondList = {8, 7, 9, 9, 9};
    std::vector<int> valuesForExpectedList = {8, 8, 1, 3, 4, 1};

    std::shared_ptr<AddTwoNumbers::ListNode> firstList(
                AddTwoNumbers::CreateLinkedList(valuesForFirstList));

    std::shared_ptr<AddTwoNumbers::ListNode> secondList(
                AddTwoNumbers::CreateLinkedList(valuesForSecondList));

    AddTwoNumbers::Solution solution;
    std::shared_ptr<AddTwoNumbers::ListNode> result(
                solution.addTwoNumbers(firstList.get(), secondList.get()));

    BOOST_CHECK(valuesForExpectedList ==
                AddTwoNumbers::LinkedListToVector(result.get()));
}

BOOST_AUTO_TEST_CASE(test_atn_diff_size_lists)
{
    std::vector<int> valuesForFirstList = {0, 1, 2};
    std::vector<int> valuesForSecondList = {8, 7, 9, 9, 4};
    std::vector<int> valuesForExpectedList = {8, 8, 1, 0, 5};

    std::shared_ptr<AddTwoNumbers::ListNode> firstList(
                AddTwoNumbers::CreateLinkedList(valuesForFirstList));

    std::shared_ptr<AddTwoNumbers::ListNode> secondList(
                AddTwoNumbers::CreateLinkedList(valuesForSecondList));

    AddTwoNumbers::Solution solution;
    std::shared_ptr<AddTwoNumbers::ListNode> result(
                solution.addTwoNumbers(firstList.get(), secondList.get()));

    BOOST_CHECK(valuesForExpectedList == AddTwoNumbers::LinkedListToVector(result.get()));
}

#endif // TEST_ADD_TWO_NUMBERS_AS_LINKED_LIST_HPP
