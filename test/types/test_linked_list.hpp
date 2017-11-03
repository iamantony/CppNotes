#ifndef TEST_LINKED_LIST_H_
#define TEST_LINKED_LIST_H_

#define BOOST_TEST_MODULE CppNotes test
#include <boost/test/unit_test.hpp>

#include "types/linked_list.hpp"

BOOST_AUTO_TEST_CASE(test_create_linkedlist)
{
    LinkedList<int> list;
    BOOST_CHECK(true);
}

BOOST_AUTO_TEST_CASE(test_create_with_size)
{
    LinkedList<int> list(5, 42);
    BOOST_CHECK(false == list.isEmpty());
    BOOST_CHECK(5 == list.size());
    BOOST_CHECK(42 == list.at(0));
    BOOST_CHECK(42 == list.at(1));
    BOOST_CHECK(42 == list.at(2));
    BOOST_CHECK(42 == list.at(3));
    BOOST_CHECK(42 == list.at(4));
}

BOOST_AUTO_TEST_CASE(test_add_elements)
{
    LinkedList<int> list;
    BOOST_CHECK(list.isEmpty());

    list.addLast(1);
    list.addLast(2);
    list.addLast(3);
    list.addLast(4);

    BOOST_CHECK(false == list.isEmpty());
    BOOST_CHECK(4 == list.size());
    BOOST_CHECK(1 == list.first());
    BOOST_CHECK(4 == list.last());
}

BOOST_AUTO_TEST_CASE(test_clear)
{
    LinkedList<int> list;
    list.clear();
    BOOST_CHECK(true == list.isEmpty());
    BOOST_CHECK(0 == list.size());

    list.addLast(1);
    list.addLast(2);
    list.clear();

    BOOST_CHECK(true == list.isEmpty());
    BOOST_CHECK(0 == list.size());
}

BOOST_AUTO_TEST_CASE(test_first_last)
{
    LinkedList<unsigned int> list;

    BOOST_CHECK_THROW(list.first(), std::length_error);
    BOOST_CHECK_THROW(list.last(), std::length_error);

    list.addLast(186);
    list.addLast(187);
    list.addLast(28786);

    BOOST_CHECK(186 == list.first());
    BOOST_CHECK(28786 == list.last());
}

BOOST_AUTO_TEST_CASE(test_at)
{
    LinkedList<unsigned int> list;

    BOOST_CHECK_THROW(list.at(0), std::length_error);

    list.addLast(186);
    list.addLast(187);
    list.addLast(28786);

    BOOST_CHECK_THROW(list.at(-156), std::runtime_error);
    BOOST_CHECK_THROW(list.at(10), std::runtime_error);

    BOOST_CHECK(186 == list.at(0));
    BOOST_CHECK(187 == list.at(1));
    BOOST_CHECK(28786 == list.at(2));
}

BOOST_AUTO_TEST_CASE(test_add_first)
{
    LinkedList<unsigned int> list;
    list.addFirst(186);
    list.addLast(187);
    list.addFirst(28786);

    BOOST_CHECK(3 == list.size());
    BOOST_CHECK(28786 == list.first());
    BOOST_CHECK(186 == list.at(1));
    BOOST_CHECK(187 == list.last());
}

BOOST_AUTO_TEST_CASE(test_add_last)
{
    LinkedList<unsigned int> list;
    list.addLast(186);
    list.addLast(187);

    BOOST_CHECK(186 == list.first());
    BOOST_CHECK(187 == list.last());
}

BOOST_AUTO_TEST_CASE(test_insert)
{
    LinkedList<unsigned int> list;
    list.insert(-100, 1);
    list.insert(1500, 2);
    list.insert(0, 3);
    list.insert(1, 4);

    BOOST_CHECK(3 == list.at(0));
    BOOST_CHECK(4 == list.at(1));
    BOOST_CHECK(1 == list.at(2));
    BOOST_CHECK(2 == list.at(3));
}

BOOST_AUTO_TEST_CASE(test_remove)
{
    LinkedList<int> list;
    list.remove(0);
    list.addLast(-100);
    list.addLast(1500);
    list.addLast(0);
    list.addLast(1);

    list.remove(-100);
    list.remove(1501);

    list.remove(1);
    BOOST_CHECK(3 == list.size());
    BOOST_CHECK(-100 == list.at(0));
    BOOST_CHECK(0 == list.at(1));
    BOOST_CHECK(1 == list.at(2));

    list.remove(2);
    BOOST_CHECK(2 == list.size());
    BOOST_CHECK(-100 == list.at(0));
    BOOST_CHECK(0 == list.at(1));

    list.remove(0);
    BOOST_CHECK(1 == list.size());
    BOOST_CHECK(0 == list.at(0));

    list.remove(0);
    BOOST_CHECK(0 == list.size());
    BOOST_CHECK(true == list.isEmpty());
}

BOOST_AUTO_TEST_CASE(test_remove_first)
{
    LinkedList<unsigned int> list;
    list.addLast(1);
    list.addLast(2);
    list.addLast(3);
    list.addLast(4);

    list.removeFirst();
    BOOST_CHECK(3 == list.size());
    BOOST_CHECK(2 == list.at(0));
    BOOST_CHECK(3 == list.at(1));
    BOOST_CHECK(4 == list.at(2));

    list.removeFirst();
    BOOST_CHECK(2 == list.size());
    BOOST_CHECK(3 == list.at(0));
    BOOST_CHECK(4 == list.at(1));

    list.removeFirst();
    BOOST_CHECK(1 == list.size());
    BOOST_CHECK(4 == list.at(0));

    list.removeFirst();
    BOOST_CHECK(0 == list.size());
}

BOOST_AUTO_TEST_CASE(test_remove_last)
{
    LinkedList<unsigned int> list;
    list.addLast(1);
    list.addLast(2);
    list.addLast(3);
    list.addLast(4);

    list.removeLast();
    BOOST_CHECK(3 == list.size());
    BOOST_CHECK(1 == list.at(0));
    BOOST_CHECK(2 == list.at(1));
    BOOST_CHECK(3 == list.at(2));

    list.removeLast();
    BOOST_CHECK(2 == list.size());
    BOOST_CHECK(1 == list.at(0));
    BOOST_CHECK(2 == list.at(1));

    list.removeLast();
    BOOST_CHECK(1 == list.size());
    BOOST_CHECK(1 == list.at(0));

    list.removeLast();
    BOOST_CHECK(0 == list.size());
}

#endif /* TEST_LINKED_LIST_H_ */
