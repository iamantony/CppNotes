#ifndef CONSTRUCTION_HPP_
#define CONSTRUCTION_HPP_

#include <iostream>

// Explicit constructor
// If you declare constructor of the class as "explicit", you will not be
// able to implicitly create object of this class
class NoExplicitCtor
{
public:
    NoExplicitCtor(int value) : m_value(value) {}
    int m_value;
};

class WithExplicitCtor
{
public:
    explicit WithExplicitCtor(int value) : m_value(value) {}
    int m_value;
};

void WorkWithNEC(NoExplicitCtor obj)
{
    std::cout << "Object of class NoExplicitCtor has value " << obj.m_value <<
                    std::endl;
}

void WorkWithWEC(WithExplicitCtor obj)
{
    std::cout << "Object of class WithExplicitCtor has value " <<
                    obj.m_value << std::endl;
}

void ExplicitCtorExamples()
{
    // We can call function WorkWithNEC() this ways:
    WorkWithNEC(NoExplicitCtor(1));
    // Here object of class NoExplicitCtor will be constructed automatically
    // with value 2. Thanks to implicit type conversion: int -> NoExplicitCtor.
    WorkWithNEC(2);

    // Function WorkWithWEC we can call only this way:
    WorkWithWEC(WithExplicitCtor(3));
    // This will not work because of explicit constructor:
    // WorkWithWEC(4);
}

#endif /* CONSTRUCTION_HPP_ */
