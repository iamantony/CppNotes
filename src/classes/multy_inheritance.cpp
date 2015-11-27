#include "multy_inheritance.hpp"

void StartMI()
{
    std::cout << "multi_inheritance" << std::endl << std::endl;

    std::cout << "Create Derived class object:" << std::endl;
    Derived *derivedObject = new Derived();

    std::cout << "Delete Derived class object:" << std::endl;
    delete derivedObject;
}
