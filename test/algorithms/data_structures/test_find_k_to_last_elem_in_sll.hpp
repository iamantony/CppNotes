#ifndef TEST_FIND_K_TO_LAST_ELEM_IN_SLL_HPP_
#define TEST_FIND_K_TO_LAST_ELEM_IN_SLL_HPP_

#include <boost/test/unit_test.hpp>

#include "types/singly_linked_list_nodes.hpp"
#include "algorithms/data_structures/find_k_to_last_elem_in_sll.hpp"

BOOST_AUTO_TEST_CASE(test_fkesll_short_sll)
{
    NodeSLL<int>* sll = new NodeSLL<int>(0);
    AppendToSLL(&sll, 1);

    BOOST_CHECK(nullptr == FindKToLastElemRecursion(sll, 5));
    BOOST_CHECK(nullptr == FindKToLastElemIteration(sll, 5));
    DeleteSLL(&sll);
}

BOOST_AUTO_TEST_CASE(test_fkesll_sll_k_size)
{
    NodeSLL<int>* sll = CreateSLL<int>({0, 1, 2, 3});

    BOOST_CHECK(sll == FindKToLastElemRecursion(sll, 4));
    BOOST_CHECK(sll == FindKToLastElemIteration(sll, 4));
    DeleteSLL(&sll);
}

BOOST_AUTO_TEST_CASE(test_fkesll_long_sll)
{
    NodeSLL<int>* sll = CreateSLL<int>({0, 1, 2, 3, 4, 5});

    NodeSLL<int>* expected = sll;
    while(expected != nullptr && expected->value != 4)
    {
        expected = expected->next;
    }

    BOOST_CHECK(expected == FindKToLastElemRecursion(sll, 2));
    BOOST_CHECK(expected == FindKToLastElemIteration(sll, 2));
    DeleteSLL(&sll);
}

#endif /* TEST_FIND_K_TO_LAST_ELEM_IN_SLL_HPP_ */
