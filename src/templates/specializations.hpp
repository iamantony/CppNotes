#ifndef SPECIALIZATIONS_H_
#define SPECIALIZATIONS_H_

#include <iostream>

using namespace std;

template <typename T>
struct Kitty
{
    static void Meow ( )
    {
        cout << "Kitty::Meow()" << endl;
    }
};

// Specialization
template<>
struct Kitty<char>
{
    static void Meow ( )
    {
        cout << "Kitty<char>::Meow()" << endl;
    }
};

// Partial Specialization
template <typename X>
struct Kitty<X*>
{
    static void Meow ( )
    {
        cout << "Kitty<X*>::Meow()" << endl;
    }
};

template <typename T, typename U>
struct Foo
{
    void operator() ()
    {
        cout << "Foo<T, U>" << endl;
    }
};

template <typename X, typename Y>
struct Foo<X*, Y>
{
    void operator() ()
    {
        cout << "Foo<X*, Y>" << endl;
    }
};

template <typename A, typename B>
struct Foo<A, B*>
{
    void operator() ()
    {
        cout << "Foo<A, B*>" << endl;
    }
};

void StartSpecializations()
{
    Kitty<int>::Meow();
    Kitty<char>::Meow();
    Kitty<double*>::Meow();

    Foo<int, int> fooNormal;
    fooNormal();

    Foo<int*, int> fooFirstPointer;
    fooFirstPointer();

    Foo<int, int*> fooSecondPointer;
    fooSecondPointer();

//    Error - ambigious
//    Foo<int*, int*> fooBothPointer;
}

#endif /* SPECIALIZATIONS_H_ */
