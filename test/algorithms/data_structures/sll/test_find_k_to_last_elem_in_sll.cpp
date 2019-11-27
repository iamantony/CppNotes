#include <boost/test/unit_test.hpp>
#include "algorithms/data_structures/sll/find_k_to_last_elem_in_sll.hpp"

BOOST_AUTO_TEST_SUITE(FindKToLastElementInSLL)

BOOST_AUTO_TEST_CASE(test_fkesll_short_sll)
{
    NodeSLL<int>* sll = new NodeSLL<int>(0);
    AppendToSLL(&sll, 1);
    BOOST_CHECK(nullptr == Algo::DS::SLL::FindKthToLast::FindRecursive(sll, 5));
    BOOST_CHECK(nullptr == Algo::DS::SLL::FindKthToLast::FindIterative(sll, 5));
    DeleteSLL(&sll);
}

BOOST_AUTO_TEST_CASE(test_fkesll_sll_k_size)
{
    NodeSLL<int>* sll = CreateSLL<int>({0, 1, 2, 3});
    BOOST_CHECK(sll == Algo::DS::SLL::FindKthToLast::FindRecursive(sll, 4));
    BOOST_CHECK(sll == Algo::DS::SLL::FindKthToLast::FindIterative(sll, 4));
    DeleteSLL(&sll);
}

BOOST_AUTO_TEST_CASE(test_fkesll_long_sll)
{
    NodeSLL<int>* sll = CreateSLL<int>({0, 1, 2, 3, 4, 5});

    NodeSLL<int>* expected = sll;
    while(expected != nullptr && expected->value != 4) {
        expected = expected->next;
    }

    BOOST_CHECK(expected == Algo::DS::SLL::FindKthToLast::FindRecursive(sll, 2));
    BOOST_CHECK(expected == Algo::DS::SLL::FindKthToLast::FindIterative(sll, 2));
    DeleteSLL(&sll);
}

BOOST_AUTO_TEST_SUITE_END()
