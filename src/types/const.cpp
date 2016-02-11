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
