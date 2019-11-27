#include <boost/test/unit_test.hpp>
#include "algorithms/data_structures/sll/find_middle_of_sll.hpp"

BOOST_AUTO_TEST_SUITE(FindMiddleOfSLL)

BOOST_AUTO_TEST_CASE(empty_sll)
{
    NodeSLL<int>* sll = nullptr;
    BOOST_CHECK(nullptr == Algo::DS::SLL::FindMiddleElement::Find(sll));
}

BOOST_AUTO_TEST_CASE(short_sll)
{
    NodeSLL<int>* sll = new NodeSLL<int>(0);
    NodeSLL<int>* result = Algo::DS::SLL::FindMiddleElement::Find(sll);

    BOOST_CHECK(nullptr != result);
    BOOST_CHECK(0 == result->value);
    DeleteSLL(&sll);
}

BOOST_AUTO_TEST_CASE(sll_even_size)
{
    NodeSLL<int>* sll = CreateSLL<int>({0, 1, 2, 3});
    NodeSLL<int>* result = Algo::DS::SLL::FindMiddleElement::Find(sll);

    BOOST_CHECK(nullptr != result);
    BOOST_CHECK(2 == result->value);
    DeleteSLL(&sll);
}

BOOST_AUTO_TEST_CASE(sll_odd_size)
{
    NodeSLL<int>* sll = CreateSLL<int>({0, 1, 2, 3, 4, 5, 6});
    NodeSLL<int>* result = Algo::DS::SLL::FindMiddleElement::Find(sll);

    BOOST_CHECK(nullptr != result);
    BOOST_CHECK(3 == result->value);
    DeleteSLL(&sll);
}

BOOST_AUTO_TEST_SUITE_END()
