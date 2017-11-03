#ifndef NAMESPACELOOKUP_H_
#define NAMESPACELOOKUP_H_

#include <iostream>

struct c1
{
    template<typename T>
    void foo(T value)
    {
        std::cout << "In foo<T>(T): " << value << std::endl;
    }
};

struct c2 : c1
{
    using c1::foo;
    void foo(double value)
    {
        std::cout << "In foo(double): " << value << std::endl;
    }
};

void StartNL()
{
    c2 c;
    c.foo(11.2);
    c.foo(11);
}

#endif /* NAMESPACELOOKUP_H_ */
