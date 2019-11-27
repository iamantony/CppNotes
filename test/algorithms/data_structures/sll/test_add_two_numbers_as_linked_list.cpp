#include <boost/test/unit_test.hpp>
#include <memory>
#include "algorithms/data_structures/sll/add_two_numbers_as_linked_lists.hpp"

BOOST_AUTO_TEST_SUITE(AddTwoNumbersAsLinkedList)

BOOST_AUTO_TEST_CASE(empty_lists)
{
    NodeSLL<int> *left = nullptr, *right = nullptr;
    BOOST_CHECK(Algo::DS::SLL::AddNumbersSLL<int>::Add(left, right) == nullptr);

    NodeSLL<int> shortList(0);
    {
        NodeSLL<int>* result =
                Algo::DS::SLL::AddNumbersSLL<int>::Add(left, &shortList);
        BOOST_CHECK(result->value == 0);
        DeleteSLL(&result);
    }

    {
        shortList.value = 5;
        NodeSLL<int>* result =
                Algo::DS::SLL::AddNumbersSLL<int>::Add(&shortList, right);
        BOOST_CHECK(result->value == 5);
        DeleteSLL(&result);
    }
}

BOOST_AUTO_TEST_CASE(equal_size_lists)
{
    NodeSLL<int>* first = CreateSLL<int>({0, 1, 2, 3, 4});
    NodeSLL<int>* second = CreateSLL<int>({8, 7, 9, 9, 4});
    std::vector<int> expected({8, 8, 1, 3, 9});

    NodeSLL<int>* result = Algo::DS::SLL::AddNumbersSLL<int>::Add(first, second);
    BOOST_CHECK(expected == ValuesInSLL(&result));

    DeleteSLL(&first);
    DeleteSLL(&second);
    DeleteSLL(&result);
}

BOOST_AUTO_TEST_CASE(equal_size_lists_with_carry)
{
    NodeSLL<int>* first = CreateSLL<int>({0, 1, 2, 3, 4});
    NodeSLL<int>* second = CreateSLL<int>({8, 7, 9, 9, 9});
    std::vector<int> expected({8, 8, 1, 3, 4, 1});

    NodeSLL<int>* result = Algo::DS::SLL::AddNumbersSLL<int>::Add(first, second);
    BOOST_CHECK(expected == ValuesInSLL(&result));

    DeleteSLL(&first);
    DeleteSLL(&second);
    DeleteSLL(&result);
}

BOOST_AUTO_TEST_CASE(diff_size_lists)
{
    NodeSLL<int>* first = CreateSLL<int>({0, 1, 2});
    NodeSLL<int>* second = CreateSLL<int>({8, 7, 9, 9, 4});
    std::vector<int> expected({8, 8, 1, 0, 5});

    NodeSLL<int>* result = Algo::DS::SLL::AddNumbersSLL<int>::Add(first, second);
    BOOST_CHECK(expected == ValuesInSLL(&result));

    DeleteSLL(&first);
    DeleteSLL(&second);
    DeleteSLL(&result);
}

BOOST_AUTO_TEST_SUITE_END()
