#ifndef ARGUMENTSDEDUCTION_H_
#define ARGUMENTSDEDUCTION_H_

#include <iostream>
#include <typeinfo>

template <typename T1, typename T2>
void meow(T1 t1, T2 t2)
{
    std::cout << "First type: " << typeid(T1).name() << ", value: " << t1 <<
            std::endl;

    std::cout << "Second type: " << typeid(T2).name() << ", value: " << t2 <<
            std::endl;
}

void StartAD()
{
    meow(1, 2L);
}

#endif /* ARGUMENTSDEDUCTION_H_ */
