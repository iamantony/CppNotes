#ifndef MULTY_INHERITANCE_H_
#define MULTY_INHERITANCE_H_

#include <iostream>

class First
{
public:
    First()
    {
        std::cout << "In First constructor" <<  std::endl;
    };

    ~First()
    {
        std::cout << "In First destructor" << std::endl;
    };
};

class Second
{
public:
    Second()
    {
        std::cout << "In Second constructor" <<  std::endl;
    };

    ~Second()
    {
        std::cout << "In Second destructor" << std::endl;
    };
};

class Derived : public First, public Second
{
public:
    Derived()
    {
        std::cout << "In Derived constructor" <<  std::endl;
    };

    ~Derived()
    {
        std::cout << "In Derived destructor" << std::endl;
    };
};

void StartMI();

#endif /* MULTY_INHERITANCE_H_ */
