#ifndef BASE_H_
#define BASE_H_

#include <iostream>

class Base
{
public:
    int public_data;

protected:
    int protected_data;

public:
    // Construct Base class object and initialize class members
    Base() : public_data(0), protected_data(1)
    {
        std::cout << "In Base constructor: public_data = " << public_data <<
                ", protected_data = " << protected_data << std::endl;
    };

    ~Base()
    {
        std::cout << "In Base destructor" << std::endl;
    };
};

class Derived : public Base
{
public:
    // We have access to public and protected members of Base class
    // and we can change them
    Derived()
    {
        public_data = 42;
        protected_data++;
        std::cout << "In Derived constructor: public_data = " << public_data <<
                ", protected_data = " << protected_data << std::endl;
    };

    ~Derived()
    {
        std::cout << "In Derived destructor" << std::endl;
    };
};

void StartBI();

#endif /* BASE_H_ */
