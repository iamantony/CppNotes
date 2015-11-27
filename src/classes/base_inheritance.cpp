#include "base_inheritance.hpp"

void StartBI()
{
    std::cout << "base_inheritance" << std::endl << std::endl;

    std::cout << "Create Base class object:" << std::endl;
    Base *baseObject = new Base();

    std::cout << "Create Derived class object:" << std::endl;
    // First of all will be created constructor of parent class and then
    // constructor of Derived class will be called.
    Derived *derivedObject = new Derived();

    std::cout << "Delete Base class object:" << std::endl;
    delete baseObject;

    std::cout << "Delete Derived class object:" << std::endl;
    // Call child (Derived destructor), in the end call parent class
    // destructor (Base destructor)
    delete derivedObject;
}
