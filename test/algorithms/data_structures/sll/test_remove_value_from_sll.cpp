#include <boost/test/unit_test.hpp>
#include "algorithms/data_structures/sll/remove_value_from_sll.hpp"

BOOST_AUTO_TEST_SUITE(RemoveValueFromSLL)

BOOST_AUTO_TEST_CASE(null_sll)
{
    NodeSLL<int>* node = nullptr;
    BOOST_CHECK(nullptr == Algo::DS::SLL::RemoveValue::Remove(node, 42));
}

BOOST_AUTO_TEST_CASE(test_rvfsll_one_elem)
{
    {
        NodeSLL<int>* sll = new NodeSLL<int>(0);
        std::vector<int> expectedValues = {0};
        sll = Algo::DS::SLL::RemoveValue::Remove(sll, 1);

        BOOST_CHECK(expectedValues == ValuesInSLL(&sll));
        DeleteSLL(&sll);
    }

    {
        NodeSLL<int>* sll = new NodeSLL<int>(0);
        std::vector<int> expectedValues;
        sll = Algo::DS::SLL::RemoveValue::Remove(sll, 0);

        BOOST_CHECK(expectedValues == ValuesInSLL(&sll));
        DeleteSLL(&sll);
    }
}

BOOST_AUTO_TEST_CASE(test_rvfsll_remove_from_start)
{
    NodeSLL<int>* sll = CreateSLL<int>({0, 1, 2, 3, 4});
    std::vector<int> expectedValues = {1, 2, 3, 4};
    sll = Algo::DS::SLL::RemoveValue::Remove(sll, 0);

    BOOST_CHECK(expectedValues == ValuesInSLL(&sll));
    DeleteSLL(&sll);
}

BOOST_AUTO_TEST_CASE(test_rvfsll_remove_from_middle)
{
    NodeSLL<int>* sll = CreateSLL<int>({0, 1, 2, 3, 4});
    std::vector<int> expectedValues = {0, 1, 3, 4};
    sll = Algo::DS::SLL::RemoveValue::Remove(sll, 2);

    BOOST_CHECK(expectedValues == ValuesInSLL(&sll));
    DeleteSLL(&sll);
}

BOOST_AUTO_TEST_CASE(test_rvfsll_remove_from_end)
{
    NodeSLL<int>* sll = CreateSLL<int>({0, 1, 2, 3, 4});
    std::vector<int> expectedValues = {0, 1, 2, 3};
    sll = Algo::DS::SLL::RemoveValue::Remove(sll, 4);

    BOOST_CHECK(expectedValues == ValuesInSLL(&sll));
    DeleteSLL(&sll);
}

BOOST_AUTO_TEST_CASE(test_rvfsll_set_with_duplicates)
{
    NodeSLL<int>* sll = CreateSLL<int>({0, 1, 0, 3, 3});
    std::vector<int> expectedValues = {0, 1, 0};
    sll = Algo::DS::SLL::RemoveValue::Remove(sll, 3);

    BOOST_CHECK(expectedValues == ValuesInSLL(&sll));
    DeleteSLL(&sll);
}

BOOST_AUTO_TEST_SUITE_END()
