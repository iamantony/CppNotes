#ifndef STL_ANY_HPP
#define STL_ANY_HPP

// http://en.cppreference.com/w/cpp/utility/any
// https://www.bfilipek.com/2018/06/any.html

#include <any>
#include <vector>
#include <string>
#include <iostream>
#include <exception>
#include <cassert>

namespace Types::Any {

class MyType {
public:
    MyType() : MyType(0, 0) {}
    MyType(const int& valA, const int& valB) : a(valA), b(valB) {
        std::cout << "MyType construction: " << a << " , " << b << std::endl;
    }

    ~MyType() {
        std::cout << "MyType destruction: " << a << " , " << b << std::endl;
    }

    void Print() {
        std::cout << a << " , " << b << std::endl;
    }

    int a, b;
};

void Creation() {
    // default initialization:
    std::any a;
    assert(!a.has_value());

    // initialization with an object:
    std::any a2(10); // int
    std::any a3(MyType(10, 11));

    // in_place:
    std::any a4(std::in_place_type<MyType>, 10, 11);
    std::any a5{std::in_place_type<std::string>, "Hello World"};

    // make_any
    std::any a6 = std::make_any<std::string>("Hello World");
}

void ChangeValue() {
    std::any a;

    // The crucial part of being safe for std::any is not to leak any resources.
    // To achieve this behaviour std::any will destroy any active object before
    // assigning a new value.

    // Here we will create object MyType
    a = MyType(10, 11);
    // And here (after assignment) it will be destructed
    a = std::string("Hello");

    a.emplace<float>(100.5f);
    a.emplace<std::vector<int>>({10, 11, 12, 13});
    a.emplace<MyType>(10, 11);
}

void EditValue() {
    std::any var = std::make_any<MyType>(10, 10);
    try {
        std::any_cast<MyType&>(var).Print();
        std::any_cast<MyType&>(var).a = 11; // read/write
        std::any_cast<MyType&>(var).Print();
        std::any_cast<int>(var); // throw!
    }
    catch(const std::bad_any_cast& e) {
        std::cout << e.what() << '\n';
    }

    int* p = std::any_cast<int>(&var);
    std::cout << (p ? "contains int... \n" : "doesn't contain an int...\n");

    MyType* pt = std::any_cast<MyType>(&var);
    if (pt) {
        pt->a = 12;
        std::any_cast<MyType&>(var).Print();
    }
}

// What are cons of using std::any? std::any don't know anything about the type
// of the value. That is why it will use heap memory to store value.

void StartAny() {
    Creation();
    ChangeValue();
    EditValue();
}

}

#endif // STL_ANY_HPP
