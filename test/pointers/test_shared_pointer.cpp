#include <boost/test/unit_test.hpp>
#include <iostream>
#include "pointers/shared_pointer.hpp"

class MyInt {
public:
    int value;

    MyInt() : value(0) {
    }

    explicit MyInt(const int& other) : value(other) {
    }

    MyInt(const MyInt&) = delete;
    MyInt& operator=(const MyInt&) = delete;
    MyInt(const MyInt&&) = delete;
    MyInt& operator=(const MyInt&&) = delete;

    ~MyInt() {
    }
};

BOOST_AUTO_TEST_SUITE(SharedPtr)

BOOST_AUTO_TEST_CASE(test_nullptr)
{
    Pointers::SharedPointer2<MyInt> ptr1;
    Pointers::SharedPointer2<MyInt> ptr2(nullptr);
    Pointers::SharedPointer2<MyInt> ptr3(ptr1);
}

BOOST_AUTO_TEST_CASE(create_one_sp)
{
    Pointers::SharedPointer2<MyInt> ptr1(new MyInt(42));
}

BOOST_AUTO_TEST_CASE(sp_copy_constr)
{
    Pointers::SharedPointer2<MyInt> ptr1(new MyInt(43));
    {
        Pointers::SharedPointer2<MyInt> ptr2(ptr1);
    }
}

BOOST_AUTO_TEST_CASE(sp_copy_assign)
{
    Pointers::SharedPointer2<MyInt> ptr1(new MyInt(44));
    Pointers::SharedPointer2<MyInt> ptr2 = ptr1;
}

BOOST_AUTO_TEST_CASE(sp_move_constr)
{
    Pointers::SharedPointer2<MyInt> ptr1(
                Pointers::SharedPointer2<MyInt>(new MyInt(45)));
    ptr1.Get()->value = 46;
}

BOOST_AUTO_TEST_SUITE_END()
