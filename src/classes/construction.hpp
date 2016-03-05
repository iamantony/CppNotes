#ifndef CONSTRUCTION_HPP_
#define CONSTRUCTION_HPP_

#include <iostream>
#include <string>

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


// Copy constructor and copy assignment operator
// From "Effective C++" by Scott Meyers:
// The copy constructor is used to initialize an object with a different
// object of the same type, and the copy assignment operator is used
// to copy the value from one object to another of the same type.

// Fortunately, copy construction is easy to distinguish from copy assignment.
// If a new object is being defined, a constructor has to be called; it can’t
// be an assignment. If no new object is being defined, no constructor can be
// involved, so it’s an assignment.
class Copyable
{
public:
    Copyable() : m_value(0) {}
    Copyable(const int& value) : m_value(value) {}

    // Copy constructor
    Copyable(const Copyable& other)
    {
        std::cout << "In copy constructor" << std::endl;
        this->m_value = other.m_value;
    }

    // Copy assignment operator. Don't forget to return reference to "this"
    // object
    Copyable& operator=(const Copyable& other)
    {
        std::cout << "In copy assignment operator" << std::endl;
        this->m_value = other.m_value;
        return (*this);
    }

    int m_value;
};

void CopyableClassExamples()
{
    Copyable c1;
    std::cout << "Value of c1: " << c1.m_value << std::endl;

    Copyable c2(5);
    std::cout << "Value of c2: " << c2.m_value << std::endl;

    // will call copy constructor
    Copyable c3(c1);
    std::cout << "Value of c3: " << c3.m_value << std::endl;

    // will call copy assignment operator
    c3 = c2;
    std::cout << "Updated value of c3: " << c3.m_value << std::endl;

    // will call copy constructor
    Copyable c4 = c1;
    std::cout << "Value of c4: " << c4.m_value << std::endl;
}

class NestedCtors
{
private:
    int one;
    double two;
    std::string three;

public:
    NestedCtors() : NestedCtors (12, 3.14, "meow")
    {
        std::cout << "NestedCtors()" << std::endl;
    }

    explicit NestedCtors(int o) : NestedCtors(o, 3.14, "meow")
    {
        std::cout << "NestedCtors(int o)" << std::endl;
    }

    NestedCtors (int o, double t, const std::string& str) :
        one ( o ), two ( t ), three ( str )
    {
        std::cout << "NestedCtors(int o, double t, const string& str)" <<
                std::endl;
    }
};

void NestedCtorsExamples()
{
    NestedCtors nc1;
    NestedCtors nc2(4);
    NestedCtors nc3(5, 4.3, "rrr");
}

#endif /* CONSTRUCTION_HPP_ */
