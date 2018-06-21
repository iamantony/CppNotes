#ifndef TEST_PARTITION_LINKED_LIST_HPP_
#define TEST_PARTITION_LINKED_LIST_HPP_

#include <boost/test/unit_test.hpp>

#include "algorithms/data_structures/sll/partition_linked_list.hpp"

BOOST_AUTO_TEST_CASE(test_partsll_invalid_list)
{
    {
        NodeSLL<int>* sll = nullptr;
        Algo::DS::SLL::PartitionAroundValue::PartitionOnePass(&sll, 10);
        BOOST_CHECK(nullptr == sll);
        DeleteSLL(&sll);
    }

    {
        NodeSLL<int>* sll = nullptr;
        Algo::DS::SLL::PartitionAroundValue::PartitionTwoPass(sll, 10);
        BOOST_CHECK(nullptr == sll);
        DeleteSLL(&sll);
    }
}

BOOST_AUTO_TEST_CASE(test_partsll_one_elem)
{
    {
        NodeSLL<int>* sll = new NodeSLL<int>(10);
        Algo::DS::SLL::PartitionAroundValue::PartitionOnePass(&sll, 20);

        std::vector<int> expectedValues = {10};
        BOOST_CHECK(expectedValues == ValuesInSLL(&sll));
        DeleteSLL(&sll);
    }

    {
        NodeSLL<int>* sll = new NodeSLL<int>(10);
        Algo::DS::SLL::PartitionAroundValue::PartitionTwoPass(sll, 20);

        std::vector<int> expectedValues = {10};
        BOOST_CHECK(expectedValues == ValuesInSLL(&sll));
        DeleteSLL(&sll);
    }
}

BOOST_AUTO_TEST_CASE(test_partsll_all_less)
{
    {
        NodeSLL<int>* sll = CreateSLL<int>({10, 9, 8, 7});
        Algo::DS::SLL::PartitionAroundValue::PartitionOnePass(&sll, 20);

        std::vector<int> expectedValues = {10, 9, 8, 7};
        std::vector<int> result = ValuesInSLL(&sll);
        BOOST_CHECK(expectedValues == result);
        DeleteSLL(&sll);
    }

    {
        NodeSLL<int>* sll = CreateSLL<int>({10, 9, 8, 7});
        Algo::DS::SLL::PartitionAroundValue::PartitionTwoPass(sll, 20);

        std::vector<int> expectedValues = {7, 8, 9, 10};
        std::vector<int> result = ValuesInSLL(&sll);
        BOOST_CHECK(expectedValues == result);
        DeleteSLL(&sll);
    }
}

BOOST_AUTO_TEST_CASE(test_partsll_all_bigger)
{
    {
        NodeSLL<int>* sll = CreateSLL<int>({10, 9, 8, 7});
        Algo::DS::SLL::PartitionAroundValue::PartitionOnePass(&sll, 2);

        std::vector<int> expectedValues = {10, 9, 8, 7};
        std::vector<int> result = ValuesInSLL(&sll);
        BOOST_CHECK(expectedValues == result);
        DeleteSLL(&sll);
    }

    {
        NodeSLL<int>* sll = CreateSLL<int>({10, 9, 8, 7});
        Algo::DS::SLL::PartitionAroundValue::PartitionTwoPass(sll, 2);

        std::vector<int> expectedValues = {7, 8, 9, 10};
        std::vector<int> result = ValuesInSLL(&sll);
        BOOST_CHECK(expectedValues == result);
        DeleteSLL(&sll);
    }
}

BOOST_AUTO_TEST_CASE(test_partsll_middle)
{
    {
        NodeSLL<int>* sll = CreateSLL<int>({10, 9, 8, 7});
        Algo::DS::SLL::PartitionAroundValue::PartitionOnePass(&sll, 9);

        std::vector<int> expected = {8, 7, 10, 9};
        std::vector<int> result = ValuesInSLL(&sll);
        BOOST_CHECK(expected == result);
        DeleteSLL(&sll);
    }

    {
        NodeSLL<int>* sll = CreateSLL<int>({10, 9, 8, 7});
        Algo::DS::SLL::PartitionAroundValue::PartitionTwoPass(sll, 9);

        std::vector<int> expected = {7, 8, 9, 10};
        std::vector<int> result = ValuesInSLL(&sll);
        BOOST_CHECK(expected == result);
        DeleteSLL(&sll);
    }
}

#endif /* TEST_PARTITION_LINKED_LIST_HPP_ */
