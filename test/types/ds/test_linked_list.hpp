#ifndef TEST_LINKED_LIST_H_
#define TEST_LINKED_LIST_H_

#include <boost/test/unit_test.hpp>

#include "types/ds/linked_list.hpp"

BOOST_AUTO_TEST_CASE(test_ll_create_empty_linkedlist)
{
    DS::LinkedList<int> list;
    BOOST_CHECK(list.isEmpty());
    BOOST_CHECK(0 == list.size());
}

BOOST_AUTO_TEST_CASE(test_ll_create_with_size)
{
    DS::LinkedList<int> list(5, 42);
    BOOST_CHECK(false == list.isEmpty());
    BOOST_CHECK(5 == list.size());
    BOOST_CHECK(42 == list.at(0));
    BOOST_CHECK(42 == list.at(1));
    BOOST_CHECK(42 == list.at(2));
    BOOST_CHECK(42 == list.at(3));
    BOOST_CHECK(42 == list.at(4));
}

BOOST_AUTO_TEST_CASE(test_ll_create_from_vector)
{
    std::vector<int> vector({1, 2, 3});
    DS::LinkedList<int> list(vector);
    BOOST_CHECK(false == list.isEmpty());
    BOOST_CHECK(3 == list.size());
    BOOST_CHECK(1 == list.at(0));
    BOOST_CHECK(2 == list.at(1));
    BOOST_CHECK(3 == list.at(2));
}

BOOST_AUTO_TEST_CASE(test_ll_add_elements)
{
    DS::LinkedList<int> list;
    BOOST_CHECK(list.isEmpty());

    list.pushFront(1);
    list.pushFront(2);
    list.pushBack(3);
    list.pushBack(4);
    list.insert(0, 10);
    list.insert(3, 11);
    list.insert(6, 12);
    list.insert(42, 13);

    BOOST_CHECK(false == list.isEmpty());
    BOOST_CHECK(8 == list.size());

    BOOST_CHECK(10 == list.at(0));
    BOOST_CHECK(2 == list.at(1));
    BOOST_CHECK(1 == list.at(2));
    BOOST_CHECK(11 == list.at(3));
    BOOST_CHECK(3 == list.at(4));
    BOOST_CHECK(4 == list.at(5));
    BOOST_CHECK(12 == list.at(6));
    BOOST_CHECK(13 == list.at(7));
}

BOOST_AUTO_TEST_CASE(test_ll_access_elements)
{
    {
        DS::LinkedList<int> list;

        BOOST_CHECK_THROW(list.front(), std::length_error);
        BOOST_CHECK_THROW(list.back(), std::length_error);
        BOOST_CHECK_THROW(list.at(3), std::length_error);
    }

    {
        std::vector<int> vector({1, 2, 3, 4, 5});
        DS::LinkedList<int> list(vector);

        BOOST_CHECK(1 == list.front());
        BOOST_CHECK(5 == list.back());
        BOOST_CHECK(1 == list.at(0));
        BOOST_CHECK(3 == list.at(2));
        BOOST_CHECK(5 == list.at(4));

        BOOST_CHECK_THROW(list.at(5), std::runtime_error);
    }
}

BOOST_AUTO_TEST_CASE(test_ll_access_n_from_end)
{
    std::vector<int> vector({1, 2, 3, 4, 5});
    DS::LinkedList<int> list(vector);

    BOOST_CHECK(5 == list.valueNFromEnd(0));
    BOOST_CHECK(4 == list.valueNFromEnd(1));
    BOOST_CHECK(1 == list.valueNFromEnd(4));

    BOOST_CHECK_THROW(list.valueNFromEnd(5), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(test_ll_clear)
{
    DS::LinkedList<int> list;
    list.clear();
    BOOST_CHECK(true == list.isEmpty());
    BOOST_CHECK(0 == list.size());

    list.pushBack(1);
    list.pushBack(2);
    BOOST_CHECK(false == list.isEmpty());
    BOOST_CHECK(2 == list.size());

    list.clear();

    BOOST_CHECK(true == list.isEmpty());
    BOOST_CHECK(0 == list.size());
}

BOOST_AUTO_TEST_CASE(test_ll_remove_elements)
{
    std::vector<int> vector({1, 2, 3, 4, 5});
    DS::LinkedList<int> list(vector);

    list.popFront();
    list.popBack();
    BOOST_CHECK(3 == list.size());
    BOOST_CHECK(2 == list.at(0));
    BOOST_CHECK(3 == list.at(1));
    BOOST_CHECK(4 == list.at(2));

    list.deleteItem(1);
    BOOST_CHECK(2 == list.size());
    BOOST_CHECK(2 == list.at(0));
    BOOST_CHECK(4 == list.at(1));

    list.deleteItem(0);
    list.deleteItem(10);
    BOOST_CHECK(1 == list.size());
    BOOST_CHECK(4 == list.at(0));

    list.deleteItem(0);
    BOOST_CHECK(0 == list.size());
    BOOST_CHECK(true == list.isEmpty());
}

BOOST_AUTO_TEST_CASE(test_ll_remove_values)
{
    std::vector<int> vector({1, 1, 3, 4, 3, 6, 3});
    DS::LinkedList<int> list(vector);

    list.remove(3);
    BOOST_CHECK(4 == list.size());
    BOOST_CHECK(1 == list.at(0));
    BOOST_CHECK(1 == list.at(1));
    BOOST_CHECK(4 == list.at(2));
    BOOST_CHECK(6 == list.at(3));

    list.remove(1);
    BOOST_CHECK(2 == list.size());
    BOOST_CHECK(4 == list.at(0));
    BOOST_CHECK(6 == list.at(1));

    list.remove(15);
    BOOST_CHECK(2 == list.size());
}

BOOST_AUTO_TEST_CASE(test_ll_reverse)
{
    std::vector<int> vector({1, 2, 3, 4, 3, 6, 3});
    DS::LinkedList<int> list(vector);

    list.reverse();
    BOOST_CHECK(7 == list.size());
    BOOST_CHECK(3 == list.at(0));
    BOOST_CHECK(6 == list.at(1));
    BOOST_CHECK(3 == list.at(2));
    BOOST_CHECK(4 == list.at(3));
    BOOST_CHECK(3 == list.at(4));
    BOOST_CHECK(2 == list.at(5));
    BOOST_CHECK(1 == list.at(6));
}

#endif /* TEST_LINKED_LIST_H_ */
