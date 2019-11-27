#include <boost/test/unit_test.hpp>
#include "algorithms/data_structures/sll/reverse_sll.hpp"

BOOST_AUTO_TEST_SUITE(ReverseSLL)

BOOST_AUTO_TEST_CASE(no_elem)
{
    {
        NodeSLL<int>* sll = nullptr;
        NodeSLL<int>* result = Algo::DS::SLL::Reverse::ReverseIterative(sll);
        BOOST_CHECK(result == nullptr);
    }

    {
        NodeSLL<int>* sll = nullptr;
        NodeSLL<int>* result = Algo::DS::SLL::Reverse::ReverseRecursive(sll);
        BOOST_CHECK(result == nullptr);
    }
}

BOOST_AUTO_TEST_CASE(one_elem)
{
    {
        NodeSLL<int>* sll = new NodeSLL<int>(0);
        NodeSLL<int>* result = Algo::DS::SLL::Reverse::ReverseIterative(sll);

        std::vector<int> expectedValues = {0};
        BOOST_CHECK(expectedValues == ValuesInSLL(&result));
        DeleteSLL(&result);
    }

    {
        NodeSLL<int>* sll = new NodeSLL<int>(0);
        NodeSLL<int>* result = Algo::DS::SLL::Reverse::ReverseRecursive(sll);

        std::vector<int> expectedValues = {0};
        BOOST_CHECK(expectedValues == ValuesInSLL(&result));
        DeleteSLL(&result);
    }
}

BOOST_AUTO_TEST_CASE(several_elem)
{
    {
        NodeSLL<int>* sll = CreateSLL<int>({0, 1, 2, 3, 4});
        NodeSLL<int>* result = Algo::DS::SLL::Reverse::ReverseIterative(sll);

        std::vector<int> expectedValues = {4, 3, 2, 1, 0};
        BOOST_CHECK(expectedValues == ValuesInSLL(&result));
        DeleteSLL(&result);
    }

    {
        NodeSLL<int>* sll = CreateSLL<int>({0, 1, 2, 3, 4});
        NodeSLL<int>* result = Algo::DS::SLL::Reverse::ReverseRecursive(sll);

        std::vector<int> expectedValues = {4, 3, 2, 1, 0};
        BOOST_CHECK(expectedValues == ValuesInSLL(&result));
        DeleteSLL(&result);
    }
}

BOOST_AUTO_TEST_SUITE_END()
