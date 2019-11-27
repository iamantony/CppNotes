#include <boost/test/unit_test.hpp>
#include "algorithms/data_structures/sll/cyclic_sll.hpp"

BOOST_AUTO_TEST_SUITE(CyclicSLL)

BOOST_AUTO_TEST_CASE(empty_list)
{
    NodeSLL<int>* sll = nullptr;
    BOOST_CHECK(false == Algo::DS::SLL::DetectCycle::HasCycle(sll));
    DeleteSLL(&sll);
}

BOOST_AUTO_TEST_CASE(no_cycle)
{
    {
        NodeSLL<int>* sll = CreateSLL<int>({10});
        BOOST_CHECK(false == Algo::DS::SLL::DetectCycle::HasCycle(sll));
        DeleteSLL(&sll);
    }

    {
        NodeSLL<int>* sll = CreateSLL<int>({10, 9, 9, 10});
        BOOST_CHECK(false == Algo::DS::SLL::DetectCycle::HasCycle(sll));
        DeleteSLL(&sll);
    }
}

BOOST_AUTO_TEST_SUITE_END()
