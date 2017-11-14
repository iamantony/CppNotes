#ifndef TEST_REVERSE_SLL_HPP
#define TEST_REVERSE_SLL_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/data_structures/reverse_sll.hpp"

BOOST_AUTO_TEST_CASE(test_revsll_no_elem)
{
    NodeSLL<int>* sll = nullptr;

    ReverseSLL::Solution solution;
    NodeSLL<int>* result = solution.ReverseSLL(sll);

    BOOST_CHECK(result == nullptr);
}

BOOST_AUTO_TEST_CASE(test_revsll_one_elem)
{
    NodeSLL<int>* sll = new NodeSLL<int>(0);

    ReverseSLL::Solution solution;
    NodeSLL<int>* result = solution.ReverseSLL(sll);

    std::vector<int> expectedValues = {0};
    BOOST_CHECK(expectedValues == ValuesInSLL(&result));
    DeleteSLL(&result);
}

BOOST_AUTO_TEST_CASE(test_revsll_several_elem)
{
    NodeSLL<int>* sll = CreateSLL<int>({0, 1, 2, 3, 4});

    ReverseSLL::Solution solution;
    NodeSLL<int>* result = solution.ReverseSLL(sll);

    std::vector<int> expectedValues = {4, 3, 2, 1, 0};
    BOOST_CHECK(expectedValues == ValuesInSLL(&result));
    DeleteSLL(&result);
}

BOOST_AUTO_TEST_CASE(test_revsll_rec_no_elem)
{
    NodeSLL<int>* sll = nullptr;

    ReverseSLL::Solution solution;
    NodeSLL<int>* result = solution.ReverseSLLRecursive(sll);

    BOOST_CHECK(result == nullptr);
}

BOOST_AUTO_TEST_CASE(test_revsll_rec_one_elem)
{
    NodeSLL<int>* sll = new NodeSLL<int>(0);

    ReverseSLL::Solution solution;
    NodeSLL<int>* result = solution.ReverseSLLRecursive(sll);

    std::vector<int> expectedValues = {0};
    BOOST_CHECK(expectedValues == ValuesInSLL(&result));
    DeleteSLL(&result);
}

BOOST_AUTO_TEST_CASE(test_revsll_rec_several_elem)
{
    NodeSLL<int>* sll = CreateSLL<int>({0, 1, 2, 3, 4});

    ReverseSLL::Solution solution;
    NodeSLL<int>* result = solution.ReverseSLLRecursive(sll);

    std::vector<int> expectedValues = {4, 3, 2, 1, 0};
    BOOST_CHECK(expectedValues == ValuesInSLL(&result));
    DeleteSLL(&result);
}

#endif // TEST_REVERSE_SLL_HPP

