#ifndef TEST_VECTOR_DS_HPP
#define TEST_VECTOR_DS_HPP

#include <boost/test/unit_test.hpp>
#include <iostream>

#include "types/vector_ds.hpp"

int ITEM_COUNTER = 0;

class Item {
public:
    Item() : Item(-1) {}
    Item(const int& val) : value(val) {
        id = ITEM_COUNTER;
        ++ITEM_COUNTER;

        std::cout << "Item() #" << id << ": " << value << std::endl;
    }

    Item(const Item& other) : Item(other.value) {
//        std::cout << "In copy constructor" << std::endl;
    }

    ~Item() {
        std::cout << "Destruct Item #" << id << ", value = " << value <<
                     std::endl;
    }

    Item& operator=(const Item& other)
    {
        std::cout << "In copy assignment operator" << std::endl;
        this->value = other.value;
        return (*this);
    }

    friend bool operator==(const Item& left, const Item& right);

public:
    int value;

private:
    int id;
};

bool operator==(const Item& left, const Item& right)
{
    return left.value == right.value;
}

BOOST_AUTO_TEST_CASE(test_vds_create_vector)
{
    DS::Vector<int> vector;
    BOOST_CHECK(true == vector.isEmpty());
    BOOST_CHECK(0 == vector.size());
    BOOST_CHECK(16 == vector.capacity());
}

BOOST_AUTO_TEST_CASE(test_vds_create_with_size)
{
    DS::Vector<int> vector(3);
    BOOST_CHECK(false == vector.isEmpty());
    BOOST_CHECK(3 == vector.size());
    BOOST_CHECK(0 == vector.at(0));
    BOOST_CHECK(0 == vector.at(1));
    BOOST_CHECK(0 == vector.at(2));
}

BOOST_AUTO_TEST_CASE(test_vds_create_with_size_and_default_value)
{
    Item item(42);
    DS::Vector<Item> vector(5, item);
    BOOST_CHECK(false == vector.isEmpty());
    BOOST_CHECK(5 == vector.size());
    BOOST_CHECK(item == vector.at(0));
    BOOST_CHECK(item == vector.at(1));
    BOOST_CHECK(item == vector.at(2));
    BOOST_CHECK(item == vector.at(3));
    BOOST_CHECK(item == vector.at(4));
}

BOOST_AUTO_TEST_CASE(test_vds_add_elements)
{
    DS::Vector<Item> vector(0);
    BOOST_CHECK(vector.isEmpty());
    BOOST_CHECK(0 == vector.capacity());

    vector.pushBack(1);
    vector.pushBack(2);
    vector.pushBack(3);
    vector.pushBack(4);

    BOOST_CHECK(false == vector.isEmpty());
    BOOST_CHECK(4 == vector.size());
    BOOST_CHECK(Item(1) == vector.at(0));
    BOOST_CHECK(Item(2) == vector.at(1));
    BOOST_CHECK(Item(3) == vector.at(2));
    BOOST_CHECK(Item(4) == vector.at(3));
}

/*
BOOST_AUTO_TEST_CASE(test_vds_clear)
{
    DS::Vector<int> vector;
    list.clear();
    BOOST_CHECK(true == vector.isEmpty());
    BOOST_CHECK(0 == vector.size());

    list.addLast(1);
    list.addLast(2);
    list.clear();

    BOOST_CHECK(true == vector.isEmpty());
    BOOST_CHECK(0 == vector.size());
}

BOOST_AUTO_TEST_CASE(test_vds_first_last)
{
    DS::Vector<unsigned int> vector;

    BOOST_CHECK_THROW(vector.first(), std::length_error);
    BOOST_CHECK_THROW(vector.last(), std::length_error);

    list.addLast(186);
    list.addLast(187);
    list.addLast(28786);

    BOOST_CHECK(186 == vector.first());
    BOOST_CHECK(28786 == vector.last());
}

BOOST_AUTO_TEST_CASE(test_vds_at)
{
    DS::Vector<unsigned int> vector;

    BOOST_CHECK_THROW(vector.at(0), std::length_error);

    list.addLast(186);
    list.addLast(187);
    list.addLast(28786);

    BOOST_CHECK_THROW(vector.at(-156), std::runtime_error);
    BOOST_CHECK_THROW(vector.at(10), std::runtime_error);

    BOOST_CHECK(186 == vector.at(0));
    BOOST_CHECK(187 == vector.at(1));
    BOOST_CHECK(28786 == vector.at(2));
}

BOOST_AUTO_TEST_CASE(test_vds_add_first)
{
    DS::Vector<unsigned int> vector;
    list.addFirst(186);
    list.addLast(187);
    list.addFirst(28786);

    BOOST_CHECK(3 == vector.size());
    BOOST_CHECK(28786 == vector.first());
    BOOST_CHECK(186 == vector.at(1));
    BOOST_CHECK(187 == vector.last());
}

BOOST_AUTO_TEST_CASE(test_vds_add_last)
{
    DS::Vector<unsigned int> vector;
    list.addLast(186);
    list.addLast(187);

    BOOST_CHECK(186 == vector.first());
    BOOST_CHECK(187 == vector.last());
}

BOOST_AUTO_TEST_CASE(test_vds_insert)
{
    DS::Vector<unsigned int> vector;
    list.insert(-100, 1);
    list.insert(1500, 2);
    list.insert(0, 3);
    list.insert(1, 4);

    BOOST_CHECK(3 == vector.at(0));
    BOOST_CHECK(4 == vector.at(1));
    BOOST_CHECK(1 == vector.at(2));
    BOOST_CHECK(2 == vector.at(3));
}

BOOST_AUTO_TEST_CASE(test_vds_remove)
{
    DS::Vector<int> vector;
    list.remove(0);
    list.addLast(-100);
    list.addLast(1500);
    list.addLast(0);
    list.addLast(1);

    list.remove(-100);
    list.remove(1501);

    list.remove(1);
    BOOST_CHECK(3 == vector.size());
    BOOST_CHECK(-100 == vector.at(0));
    BOOST_CHECK(0 == vector.at(1));
    BOOST_CHECK(1 == vector.at(2));

    list.remove(2);
    BOOST_CHECK(2 == vector.size());
    BOOST_CHECK(-100 == vector.at(0));
    BOOST_CHECK(0 == vector.at(1));

    list.remove(0);
    BOOST_CHECK(1 == vector.size());
    BOOST_CHECK(0 == vector.at(0));

    list.remove(0);
    BOOST_CHECK(0 == vector.size());
    BOOST_CHECK(true == vector.isEmpty());
}

BOOST_AUTO_TEST_CASE(test_vds_remove_first)
{
    DS::Vector<unsigned int> vector;
    list.addLast(1);
    list.addLast(2);
    list.addLast(3);
    list.addLast(4);

    list.removeFirst();
    BOOST_CHECK(3 == vector.size());
    BOOST_CHECK(2 == vector.at(0));
    BOOST_CHECK(3 == vector.at(1));
    BOOST_CHECK(4 == vector.at(2));

    list.removeFirst();
    BOOST_CHECK(2 == vector.size());
    BOOST_CHECK(3 == vector.at(0));
    BOOST_CHECK(4 == vector.at(1));

    list.removeFirst();
    BOOST_CHECK(1 == vector.size());
    BOOST_CHECK(4 == vector.at(0));

    list.removeFirst();
    BOOST_CHECK(0 == vector.size());
}

BOOST_AUTO_TEST_CASE(test_vds_remove_last)
{
    DS::Vector<unsigned int> vector;
    list.addLast(1);
    list.addLast(2);
    list.addLast(3);
    list.addLast(4);

    list.removeLast();
    BOOST_CHECK(3 == vector.size());
    BOOST_CHECK(1 == vector.at(0));
    BOOST_CHECK(2 == vector.at(1));
    BOOST_CHECK(3 == vector.at(2));

    list.removeLast();
    BOOST_CHECK(2 == vector.size());
    BOOST_CHECK(1 == vector.at(0));
    BOOST_CHECK(2 == vector.at(1));

    list.removeLast();
    BOOST_CHECK(1 == vector.size());
    BOOST_CHECK(1 == vector.at(0));

    list.removeLast();
    BOOST_CHECK(0 == vector.size());
}
*/

#endif // TEST_VECTOR_DS_HPP
