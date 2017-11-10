#ifndef TEST_PARTITION_LINKED_LIST_HPP_
#define TEST_PARTITION_LINKED_LIST_HPP_

#define BOOST_TEST_MODULE CppNotes test
#include <boost/test/unit_test.hpp>

#include <algorithm>

#include "types/singly_linked_list_nodes.hpp"
#include "algorithms/data_structures/partition_linked_list.hpp"

BOOST_AUTO_TEST_CASE(test_partll_1p_invalid_list)
{
    NodeSLL<int>* sll = nullptr;

    PartitionSLLOnePass(&sll, 10);
    BOOST_CHECK(nullptr == sll);
    DeleteSLL(&sll);
}

BOOST_AUTO_TEST_CASE(test_partll_2p_invalid_list)
{
    NodeSLL<int>* sll = nullptr;

    PartitionSLLTwoPass(sll, 10);
    BOOST_CHECK(nullptr == sll);
    DeleteSLL(&sll);
}

BOOST_AUTO_TEST_CASE(test_partll_1p_one_elem)
{
    NodeSLL<int>* sll = new NodeSLL<int>(10);
    PartitionSLLOnePass(&sll, 20);

    std::vector<int> expectedValues = {10};
    BOOST_CHECK(expectedValues == ValuesInSLL(&sll));
    DeleteSLL(&sll);
}

BOOST_AUTO_TEST_CASE(test_partll_2p_one_elem)
{
    NodeSLL<int>* sll = new NodeSLL<int>(10);
    PartitionSLLTwoPass(sll, 20);

    std::vector<int> expectedValues = {10};
    BOOST_CHECK(expectedValues == ValuesInSLL(&sll));
    DeleteSLL(&sll);
}

BOOST_AUTO_TEST_CASE(test_partll_1p_all_less)
{
    NodeSLL<int>* sll = CreateSLL<int>({10, 9, 8, 7});

    PartitionSLLOnePass(&sll, 20);

    std::vector<int> expectedValues = {10, 9, 8, 7};
    std::vector<int> result = ValuesInSLL(&sll);
    BOOST_CHECK(expectedValues == result);
    DeleteSLL(&sll);
}

BOOST_AUTO_TEST_CASE(test_partll_2p_all_less)
{
    NodeSLL<int>* sll = CreateSLL<int>({10, 9, 8, 7});

    PartitionSLLTwoPass(sll, 20);

    std::vector<int> expectedValues = {7, 8, 9, 10};
    std::vector<int> result = ValuesInSLL(&sll);
    BOOST_CHECK(expectedValues == result);
    DeleteSLL(&sll);
}

BOOST_AUTO_TEST_CASE(test_partll_1p_all_bigger)
{
    NodeSLL<int>* sll = CreateSLL<int>({10, 9, 8, 7});

    PartitionSLLOnePass(&sll, 2);

    std::vector<int> expectedValues = {10, 9, 8, 7};
    std::vector<int> result = ValuesInSLL(&sll);
    BOOST_CHECK(expectedValues == result);
    DeleteSLL(&sll);
}

BOOST_AUTO_TEST_CASE(test_partll_2p_all_bigger)
{
    NodeSLL<int>* sll = CreateSLL<int>({10, 9, 8, 7});

    PartitionSLLTwoPass(sll, 2);

    std::vector<int> expectedValues = {7, 8, 9, 10};
    std::vector<int> result = ValuesInSLL(&sll);
    BOOST_CHECK(expectedValues == result);
    DeleteSLL(&sll);
}

BOOST_AUTO_TEST_CASE(test_partll_1p_middle)
{
    NodeSLL<int>* sll = CreateSLL<int>({10, 9, 8, 7});

    PartitionSLLOnePass(&sll, 9);

    std::vector<int> expected = {8, 7, 10, 9};
    std::vector<int> result = ValuesInSLL(&sll);
    BOOST_CHECK(expected == result);
    DeleteSLL(&sll);
}

BOOST_AUTO_TEST_CASE(test_partll_2p_middle)
{
    NodeSLL<int>* sll = CreateSLL<int>({10, 9, 8, 7});

    PartitionSLLTwoPass(sll, 9);

    std::vector<int> expected = {7, 8, 9, 10};
    std::vector<int> result = ValuesInSLL(&sll);
    BOOST_CHECK(expected == result);
    DeleteSLL(&sll);
}

#endif /* TEST_PARTITION_LINKED_LIST_HPP_ */
