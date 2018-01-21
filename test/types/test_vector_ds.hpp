#ifndef TEST_VECTOR_DS_HPP
#define TEST_VECTOR_DS_HPP

#include <boost/test/unit_test.hpp>
#include <iostream>

#include "types/vector_ds.hpp"

int VDS_ITEM_COUNTER = 0;

class Item {
public:
    Item() : Item(-1) {}
    Item(const int& val) : value(val) {
        id = VDS_ITEM_COUNTER;
        ++VDS_ITEM_COUNTER;

//        std::cout << "Item() #" << id << ": " << value << std::endl;
    }

    Item(const Item& other) : Item(other.value) {
//        std::cout << "In copy constructor" << std::endl;
    }

    ~Item() {
//        std::cout << "Destruct Item #" << id << ", value = " << value <<
//                     std::endl;
    }

    Item& operator=(const Item& other)
    {
//        std::cout << "In copy assignment operator" << std::endl;
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

    DS::Vector<int> vectorEmpty(0);
    BOOST_CHECK(true == vectorEmpty.isEmpty());
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

BOOST_AUTO_TEST_CASE(test_vds_clear)
{
    DS::Vector<Item> vector;
    vector.clear();
    BOOST_CHECK(true == vector.isEmpty());
    BOOST_CHECK(0 == vector.size());
    BOOST_CHECK(0 == vector.capacity());

    vector.pushBack(1);
    vector.pushBack(2);
    vector.clear();

    BOOST_CHECK(true == vector.isEmpty());
    BOOST_CHECK(0 == vector.size());
    BOOST_CHECK(0 == vector.capacity());
}

BOOST_AUTO_TEST_CASE(test_vds_at)
{
    DS::Vector<Item> vector;

    BOOST_CHECK_THROW(vector.at(0), std::out_of_range);

    vector.pushBack(186);
    vector.pushBack(187);
    vector.pushBack(28786);

    BOOST_CHECK_THROW(vector.at(156), std::out_of_range);
    BOOST_CHECK_THROW(vector.at(10), std::out_of_range);

    BOOST_CHECK(Item(186) == vector.at(0));
    BOOST_CHECK(Item(187) == vector.at(1));
    BOOST_CHECK(Item(28786) == vector.at(2));

    vector.clear();
    BOOST_CHECK_THROW(vector.at(0), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(test_vds_prepend)
{
    DS::Vector<unsigned int> vector;
    vector.prepend(186);
    vector.prepend(187);
    vector.prepend(28786);

    BOOST_CHECK(3 == vector.size());
    BOOST_CHECK(28786 == vector.at(0));
    BOOST_CHECK(187 == vector.at(1));
    BOOST_CHECK(186 == vector.at(2));
}

BOOST_AUTO_TEST_CASE(test_vds_insert)
{
    DS::Vector<unsigned int> vector;
    vector.insert(0, 0);
    vector.insert(1, 4);
    vector.insert(1, 3);
    vector.insert(10, 5);
    vector.insert(1, 2);
    vector.insert(1, 1);

    BOOST_CHECK(0 == vector[0]);
    BOOST_CHECK(1 == vector[1]);
    BOOST_CHECK(2 == vector[2]);
    BOOST_CHECK(3 == vector[3]);
    BOOST_CHECK(4 == vector[4]);
    BOOST_CHECK(5 == vector[5]);
}

BOOST_AUTO_TEST_CASE(test_vds_remove)
{
    DS::Vector<int> vector;
    vector.remove(0);

    vector.pushBack(-100);
    vector.pushBack(0);
    vector.pushBack(1500);
    vector.pushBack(0);
    vector.pushBack(0);
    vector.pushBack(1);

    vector.remove(123);

    vector.remove(1);
    BOOST_CHECK(5 == vector.size());
    BOOST_CHECK(-100 == vector.at(0));
    BOOST_CHECK(0 == vector.at(1));
    BOOST_CHECK(1500 == vector.at(2));
    BOOST_CHECK(0 == vector.at(3));
    BOOST_CHECK(0 == vector.at(4));

    vector.remove(0);
    BOOST_CHECK(2 == vector.size());
    BOOST_CHECK(-100 == vector.at(0));
    BOOST_CHECK(1500 == vector.at(1));

    vector.remove(-100);
    BOOST_CHECK(1 == vector.size());
    BOOST_CHECK(1500 == vector.at(0));

    vector.remove(1500);
    BOOST_CHECK(0 == vector.size());

    vector.pushBack(100);
    vector.pushBack(1010);
    BOOST_CHECK(2 == vector.size());
    BOOST_CHECK(100 == vector.at(0));
    BOOST_CHECK(1010 == vector.at(1));
}

BOOST_AUTO_TEST_CASE(test_vds_pop_elements)
{
    DS::Vector<Item> vector;

    BOOST_CHECK_THROW(vector.popBack(), std::out_of_range);

    vector.pushBack(1);
    vector.pushBack(2);
    vector.pushBack(3);
    vector.pushBack(4);

    BOOST_CHECK(4 == vector.size());

    vector.popBack();
    vector.popBack();

    BOOST_CHECK(2 == vector.size());
    BOOST_CHECK(1 == vector[0]);
    BOOST_CHECK(2 == vector[1]);

    vector.popBack();
    vector.popBack();
    BOOST_CHECK(0 == vector.size());

    BOOST_CHECK_THROW(vector.popBack(), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(test_vds_find_element)
{
    DS::Vector<Item> vector(3);

    size_t itemIndex = 0;
    BOOST_CHECK(false == vector.find(Item(0), itemIndex));
    BOOST_CHECK(0 == itemIndex);

    vector.pushBack(-100);
    vector.pushBack(0);
    vector.pushBack(1500);
    vector.pushBack(0);
    vector.pushBack(0);
    vector.pushBack(1);

    BOOST_CHECK(true == vector.find(Item(-100), itemIndex));
    BOOST_CHECK(3 == itemIndex);

    BOOST_CHECK(true == vector.find(Item(0), itemIndex));
    BOOST_CHECK(4 == itemIndex);

    BOOST_CHECK(true == vector.find(Item(1), itemIndex));
    BOOST_CHECK(8 == itemIndex);

    BOOST_CHECK(false == vector.find(Item(20), itemIndex));
}

BOOST_AUTO_TEST_CASE(test_vds_equality)
{
    DS::Vector<int> vector;
    vector.pushBack(-100);
    vector.pushBack(0);
    vector.pushBack(1500);

    DS::Vector<int> vectorEqual;
    vectorEqual.pushBack(-100);
    vectorEqual.pushBack(0);
    vectorEqual.pushBack(1500);

    BOOST_CHECK(vector == vectorEqual);

    DS::Vector<int> vectorNESameSize;
    vectorNESameSize.pushBack(-100);
    vectorNESameSize.pushBack(-100);
    vectorNESameSize.pushBack(-100);

    BOOST_CHECK(false == (vector == vectorNESameSize));

    DS::Vector<int> vectorNEDiffSize(0);
    BOOST_CHECK(false == (vector == vectorNEDiffSize));
}

BOOST_AUTO_TEST_CASE(test_vds_copy_constructor)
{
    DS::Vector<int> vector;
    vector.pushBack(-100);
    vector.pushBack(0);
    vector.pushBack(1500);

    {
        DS::Vector<int> vectorCopy(vector);
        BOOST_CHECK(vector == vectorCopy);
    }

    BOOST_CHECK(3 == vector.size());
    BOOST_CHECK(-100 == vector.at(0));
    BOOST_CHECK(0 == vector.at(1));
    BOOST_CHECK(1500 == vector.at(2));

    DS::Vector<int> vectorEmpty(0);
    DS::Vector<int> vectorEmptyCopy(vectorEmpty);
    BOOST_CHECK(vectorEmpty == vectorEmptyCopy);
}

BOOST_AUTO_TEST_CASE(test_vds_copy_assign_operator)
{
    DS::Vector<int> vector;
    vector.pushBack(-100);
    vector.pushBack(0);
    vector.pushBack(1500);

    // Try to assign to itself
    vector = vector;

    {
        DS::Vector<int> vectorCopy(5, 16);
        BOOST_CHECK(false == (vector == vectorCopy));

        vectorCopy = vector;
        BOOST_CHECK(vector == vectorCopy);
    }

    BOOST_CHECK(3 == vector.size());
    BOOST_CHECK(-100 == vector.at(0));
    BOOST_CHECK(0 == vector.at(1));
    BOOST_CHECK(1500 == vector.at(2));

    DS::Vector<int> vectorEmpty(0);
    vector = vectorEmpty;
    BOOST_CHECK(0 == vector.size());
    BOOST_CHECK(0 == vector.capacity());
}

#endif // TEST_VECTOR_DS_HPP
