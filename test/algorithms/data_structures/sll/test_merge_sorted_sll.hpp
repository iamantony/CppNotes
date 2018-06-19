#ifndef TEST_MERGE_SORTED_SLL_HPP
#define TEST_MERGE_SORTED_SLL_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/data_structures/sll/merge_sorted_sll.hpp"

BOOST_AUTO_TEST_CASE(test_mssll_empty_lists)
{
    NodeSLL<int>* left = nullptr;
    NodeSLL<int>* right = nullptr;
    BOOST_CHECK(nullptr ==
                Algo::DS::SLL::MergeSortedLists::Merge(left, right));
}

BOOST_AUTO_TEST_CASE(test_mssll_one_empty_list)
{
    {
        NodeSLL<int>* left = CreateSLL<int>({1, 9});
        NodeSLL<int>* right = nullptr;

        std::vector<int> expectedValues = {1, 9};
        NodeSLL<int>* result =
                Algo::DS::SLL::MergeSortedLists::Merge(left, right);
        BOOST_CHECK(expectedValues == ValuesInSLL(&result));
        DeleteSLL(&result);
    }

    {
        NodeSLL<int>* left = nullptr;
        NodeSLL<int>* right = CreateSLL<int>({1, 2, 3});

        std::vector<int> expectedValues = {1, 2, 3};
        NodeSLL<int>* result =
                Algo::DS::SLL::MergeSortedLists::Merge(left, right);
        BOOST_CHECK(expectedValues == ValuesInSLL(&result));
        DeleteSLL(&result);
    }
}

BOOST_AUTO_TEST_CASE(test_mssll_non_empty_lists)
{
    NodeSLL<int>* left = CreateSLL<int>({1, 9, 20, 24, 55});
    NodeSLL<int>* right = CreateSLL<int>({1, 8, 11, 12, 55});

    std::vector<int> expectedValues = {1, 1, 8, 9, 11, 12, 20, 24, 55, 55};
    NodeSLL<int>* result =
            Algo::DS::SLL::MergeSortedLists::Merge(left, right);
    BOOST_CHECK(expectedValues == ValuesInSLL(&result));
    DeleteSLL(&result);
}

#endif // TEST_MERGE_SORTED_SLL_HPP
