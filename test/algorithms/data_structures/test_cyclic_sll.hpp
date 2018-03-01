#ifndef TEST_CYCLIC_SLL_HPP
#define TEST_CYCLIC_SLL_HPP

#include <boost/test/unit_test.hpp>

#include <algorithm>

#include "types/singly_linked_list_nodes.hpp"
#include "algorithms/data_structures/cyclic_sll.hpp"

BOOST_AUTO_TEST_CASE(test_cyclicsll_empty_list)
{
    NodeSLL<int>* sll = nullptr;
    CyclicSLL::Solution solution;
    BOOST_CHECK(false == solution.hasCycle(sll));
    DeleteSLL(&sll);
}

BOOST_AUTO_TEST_CASE(test_cyclicsll_no_cycle)
{
    {
        NodeSLL<int>* sll = CreateSLL<int>({10});
        CyclicSLL::Solution solution;
        BOOST_CHECK(false == solution.hasCycle(sll));
        DeleteSLL(&sll);
    }

    {
        NodeSLL<int>* sll = CreateSLL<int>({10, 9, 9, 10});
        CyclicSLL::Solution solution;
        BOOST_CHECK(false == solution.hasCycle(sll));
        DeleteSLL(&sll);
    }
}

#endif // TEST_CYCLIC_SLL_HPP
