#ifndef CONST_HPP_
#define CONST_HPP_

#include <iostream>
#include <string>

// All about "const" key word

// From Item 2 of book "Effective C++" by Scott Meyers:
// Prefer const values to #defines

// Global const value
const int RATE = 110;
const char* const AUTHOR_NAME = "Antony Cherepanov";
// it is better to use std::string instead of char*
const std::string ONE("one");

// How to make class-specific const value
class Container
{
public:
    // Member "value" will be created in each object of the Container class
    const int value = 1;
    // Member "rate" will be created only once and will be used by all objects
    // of the Container class
    static const int rate = 100;
};

// The enum hack
// "The enum hack is worth knowing about for several reasons. First, the
// enum hack behaves in some ways more like a #define than a const
// does, and sometimes that’s what you want. For example, it’s legal to
// take the address of a const, but it’s not legal to take the address of an
// enum, and it’s typically not legal to take the address of a #define,
// either.
//
// A second reason to know about the enum hack is purely pragmatic.
// Lots of code employs it, so you need to recognize it when you see it. In
// fact, the enum hack is a fundamental technique of template metaprogramming."
class Hacked
{
public:
    enum {SIZE = 16};
    int array[SIZE];
};

void ConstExamples()
{
    std::cout << "Value of constant RATE: " << RATE << std::endl;
    std::cout << "Value of constant AUTHOR_NAME: " << AUTHOR_NAME << std::endl;
    std::cout << "Value of constant ONE: " << ONE << std::endl;

    Container c1, c2;
    const int* pvalue1 = &c1.value;
    const int* pvalue2 = &c2.value;
    if (pvalue1 == pvalue2)
    {
        std::cout << "Will not be printed" << std::endl;
    }
    else
    {
        std::cout << "Each object c1 and c2 of class Container have its own "
                        "member 'value'" << std::endl;
    }

    const int* prate1 = &c1.rate;
    const int* prate2 = &c2.rate;
    if (prate1 == prate2)
    {
        std::cout << "Each object c1 and c2 of class Container use same "
                        "member 'rate'" << std::endl;
    }
    else
    {
        std::cout << "Will not be printed" << std::endl;
    }
}

#endif /* CONST_HPP_ */
