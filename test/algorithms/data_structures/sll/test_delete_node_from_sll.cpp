#include <boost/test/unit_test.hpp>
#include "algorithms/data_structures/sll/delete_node_from_sll.hpp"

BOOST_AUTO_TEST_SUITE(DeleteNodeFromSLL)

BOOST_AUTO_TEST_CASE(delete_head_one_elem)
{
    NodeSLL<int>* sll = new NodeSLL<int>(10);
    Algo::DS::SLL::DeleteNode::Delete(sll);

    std::vector<int> expectedValues = {0};
    BOOST_CHECK(expectedValues == ValuesInSLL(&sll));
    DeleteSLL(&sll);
}

BOOST_AUTO_TEST_CASE(delete_head)
{
    NodeSLL<int>* sll = CreateSLL<int>({10, 9, 8, 7});
    Algo::DS::SLL::DeleteNode::Delete(sll);

    std::vector<int> expectedValues = {9, 8, 7};
    BOOST_CHECK(expectedValues == ValuesInSLL(&sll));
    DeleteSLL(&sll);
}

BOOST_AUTO_TEST_CASE(delete_middle)
{
    NodeSLL<int>* sll = CreateSLL<int>({10, 9, 8, 7});

    NodeSLL<int>* toDelete = sll;
    while(toDelete != nullptr && toDelete->value != 9)
    {
        toDelete = toDelete->next;
    }

    Algo::DS::SLL::DeleteNode::Delete(toDelete);

    std::vector<int> expectedValues = {10, 8, 7};
    BOOST_CHECK(expectedValues == ValuesInSLL(&sll));
    DeleteSLL(&sll);
}

BOOST_AUTO_TEST_CASE(delete_last)
{
    NodeSLL<int>* sll = CreateSLL<int>({10, 9, 8, 7});

    NodeSLL<int>* toDelete = sll;
    while(toDelete != nullptr && toDelete->value != 7)
    {
        toDelete = toDelete->next;
    }

    Algo::DS::SLL::DeleteNode::Delete(toDelete);

    std::vector<int> expectedValues = {10, 9, 8, 0};
    BOOST_CHECK(expectedValues == ValuesInSLL(&sll));
    DeleteSLL(&sll);
}

BOOST_AUTO_TEST_SUITE_END()
