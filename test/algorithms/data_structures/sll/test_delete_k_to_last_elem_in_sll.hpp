#ifndef TEST_DELETE_K_TO_LAST_ELEM_IN_SLL_HPP
#define TEST_DELETE_K_TO_LAST_ELEM_IN_SLL_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/data_structures/sll/delete_k_to_last_elem_in_sll.hpp"

BOOST_AUTO_TEST_CASE(test_dktlesll_one_elem) {
    NodeSLL<int>* sll = new NodeSLL<int>(10);

    DeleteKToLastElem::Solution solution;
    NodeSLL<int>* result = solution.deleteKthFromEnd(sll, 1);

    BOOST_CHECK(nullptr == result);
}

BOOST_AUTO_TEST_CASE(test_dktlesll_delete_last)
{
    NodeSLL<int>* sll = CreateSLL<int>({1, 2, 3, 4});

    DeleteKToLastElem::Solution solution;
    NodeSLL<int>* result = solution.deleteKthFromEnd(sll, 1);

    std::vector<int> expectedValues = {1, 2, 3};
    BOOST_CHECK(expectedValues == ValuesInSLL(&result));
    DeleteSLL(&result);
}

BOOST_AUTO_TEST_CASE(test_dktlesll_delete_one_before_last)
{
    NodeSLL<int>* sll = CreateSLL<int>({1, 2, 3, 4});

    DeleteKToLastElem::Solution solution;
    NodeSLL<int>* result = solution.deleteKthFromEnd(sll, 2);

    std::vector<int> expectedValues = {1, 2, 4};
    BOOST_CHECK(expectedValues == ValuesInSLL(&result));
    DeleteSLL(&result);
}

BOOST_AUTO_TEST_CASE(test_dktlesll_delete_three_before_last)
{
    NodeSLL<int>* sll = CreateSLL<int>({1, 2, 3, 4});

    DeleteKToLastElem::Solution solution;
    NodeSLL<int>* result = solution.deleteKthFromEnd(sll, 3);

    std::vector<int> expectedValues = {1, 3, 4};
    BOOST_CHECK(expectedValues == ValuesInSLL(&result));
    DeleteSLL(&result);
}

#endif // TEST_DELETE_K_TO_LAST_ELEM_IN_SLL_HPP
