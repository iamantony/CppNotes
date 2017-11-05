#ifndef TEST_REMOVE_DUP_LINKED_LIST_HPP_
#define TEST_REMOVE_DUP_LINKED_LIST_HPP_

#define BOOST_TEST_MODULE CppNotes test
#include <boost/test/unit_test.hpp>

#include "algorithms/data_structures/singly_linked_list_nodes.hpp"
#include "algorithms/data_structures/remove_duplicates_linked_list.hpp"

BOOST_AUTO_TEST_CASE(test_rdll_set_one_elem)
{
    NodeSLL<int>* sll = new NodeSLL<int>(0);
    std::vector<int> expectedValues = {0};
    RemoveDuplicatesSLLSet(sll);

    BOOST_CHECK(expectedValues == ValuesInSLL(sll));
    DeleteSLL(sll);
}

BOOST_AUTO_TEST_CASE(test_rdll_set_no_duplicates)
{
    NodeSLL<int>* sll = new NodeSLL<int>(0);
    AppendToSLL(sll, 1);
    AppendToSLL(sll, 2);
    AppendToSLL(sll, 3);
    AppendToSLL(sll, 4);

    std::vector<int> expectedValues = {0, 1, 2, 3, 4};
    RemoveDuplicatesSLLSet(sll);

    BOOST_CHECK(expectedValues == ValuesInSLL(sll));
    DeleteSLL(sll);
}

BOOST_AUTO_TEST_CASE(test_rdll_set_with_duplicates)
{
    NodeSLL<int>* sll = new NodeSLL<int>(0);
    AppendToSLL(sll, 1);
    AppendToSLL(sll, 0);
    AppendToSLL(sll, 3);
    AppendToSLL(sll, 3);

    std::vector<int> expectedValues = {0, 1, 3};
    RemoveDuplicatesSLLSet(sll);

    BOOST_CHECK(expectedValues == ValuesInSLL(sll));
    DeleteSLL(sll);
}

BOOST_AUTO_TEST_CASE(test_rdll_runner_one_elem)
{
    NodeSLL<int>* sll = new NodeSLL<int>(0);
    std::vector<int> expectedValues = {0};
    RemoveDuplicatesSLLRunner(sll);

    BOOST_CHECK(expectedValues == ValuesInSLL(sll));
    DeleteSLL(sll);
}

BOOST_AUTO_TEST_CASE(test_rdll_runner_no_duplicates)
{
    NodeSLL<int>* sll = new NodeSLL<int>(0);
    AppendToSLL(sll, 1);
    AppendToSLL(sll, 2);
    AppendToSLL(sll, 3);
    AppendToSLL(sll, 4);

    std::vector<int> expectedValues = {0, 1, 2, 3, 4};
    RemoveDuplicatesSLLRunner(sll);

    BOOST_CHECK(expectedValues == ValuesInSLL(sll));
    DeleteSLL(sll);
}

BOOST_AUTO_TEST_CASE(test_rdll_runner_with_duplicates)
{
    NodeSLL<int>* sll = new NodeSLL<int>(0);
    AppendToSLL(sll, 1);
    AppendToSLL(sll, 0);
    AppendToSLL(sll, 3);
    AppendToSLL(sll, 3);

    std::vector<int> expectedValues = {0, 1, 3};
    RemoveDuplicatesSLLRunner(sll);

    BOOST_CHECK(expectedValues == ValuesInSLL(sll));
    DeleteSLL(sll);
}

#endif /* TEST_REMOVE_DUP_LINKED_LIST_HPP_ */
