#include "const.hpp"

const int Container::rate;

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

void ConstReferences()
{
    int a1 = 10;
    std::cout << "Initial value of a1: " << a1 << std::endl;

    // A reference is an entity that is an alias for another object.
    // We can work with refA the same way as with value a1.
    int& refA = a1;
    std::cout << "Increment value of a1 through refA: " << ++refA << std::endl;

    // We can create const T&. In this case we will not be able to change
    // value of the a1 through constRefA.
    const int& constRefA = a1;
    std::cout << "We can only access the value of the object through "
            "const T&: " << constRefA << std::endl;

    // We can not reset a reference to make it refer to a different object.
    // That is mean that T& is the same as T& const.
}

void ConstPointers()
{
    int b1 = 10;
    std::cout << "Initial value of b1: " << b1 << std::endl;

    // Pointer is an object that can hold address of another object
    int* pB = &b1;
    std::cout << "Address of the b1: " << pB << std::endl;
    std::cout << "Increment value of b1 through pB: " << ++(*pB) << std::endl;

    // const T* - we can not change the value of the object that pointer points
    // to, but we can make pointer to point to other object
    const int* constPB = &b1;
    std::cout << "const T* points to b1: " << *constPB << std::endl;
    std::cout << "const T* points to address: " << constPB << std::endl;
    // ++(*constPB); - this will not work

    int b2 = 20;
    constPB = &b2;
    std::cout << "Now const T* points to other object: " << constPB <<
            ". It has value: " << *constPB << std::endl;

    // const T* const - constant pointer to constant value of type T. We can
    // not change value of the object and can not change object that pointer
    // points to
    const int* const constPconstB = &b1;
    std::cout << "We can only access the value of the object through "
                "const T* const: " << *constPconstB << std::endl;
}
