#ifndef TEST_SHARED_POINTER_HPP
#define TEST_SHARED_POINTER_HPP

#include <iostream>

#include <boost/test/unit_test.hpp>

#include "pointers/shared_pointer.hpp"

class MyInt {
public:
    int value;

    MyInt() : value(0) {
        std::cout << "In MyInt(): " << value << std::endl;
    }

    explicit MyInt(const int& other) : value(other) {
        std::cout << "In MyInt(const int&): " << value << std::endl;
    }

    MyInt(const MyInt&) = delete;
    MyInt& operator=(const MyInt&) = delete;
    MyInt(const MyInt&&) = delete;
    MyInt& operator=(const MyInt&&) = delete;

    ~MyInt() {
        std::cout << "In ~MyInt(): " << value << std::endl;
    }
};

BOOST_AUTO_TEST_CASE(test_shrdptr_nullptr)
{
    Pointers::SharedPointer<MyInt> ptr1;
    Pointers::SharedPointer<MyInt> ptr2(nullptr);
    Pointers::SharedPointer<MyInt> ptr3(ptr1);
}

BOOST_AUTO_TEST_CASE(test_shrdptr_create_one_sp)
{
    Pointers::SharedPointer<MyInt> ptr1(new MyInt(42));
}

BOOST_AUTO_TEST_CASE(test_shrdptr_sp_copy_constr)
{
    Pointers::SharedPointer<MyInt> ptr1(new MyInt(43));
    Pointers::SharedPointer<MyInt> ptr2(ptr1);
}

BOOST_AUTO_TEST_CASE(test_shrdptr_sp_copy_assign)
{
    Pointers::SharedPointer<MyInt> ptr1(new MyInt(44));
    Pointers::SharedPointer<MyInt> ptr2 = ptr1;
}

BOOST_AUTO_TEST_CASE(test_shrdptr_sp_move_constr)
{
    Pointers::SharedPointer<MyInt> ptr1(
                Pointers::SharedPointer<MyInt>(new MyInt(45)));
}

#endif // TEST_SHARED_POINTER_HPP
