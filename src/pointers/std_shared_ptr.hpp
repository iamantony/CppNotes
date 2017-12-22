#ifndef STD_SHARED_PTR_HPP
#define STD_SHARED_PTR_HPP

#include <memory>
#include <vector>
#include <iostream>

// Usage of aliasing constructor of shared_ptr
// https://www.justsoftwaresolutions.co.uk/cplusplus/shared-ptr-secret-constructor.html
namespace {

std::vector<std::shared_ptr<int>> someIntsToStore;

struct Example {
    int value = 42;

    Example() {
        std::cout << "Construction of Example" << std::endl;
    }

    ~Example() {
        std::cout << "Deconstruction of Example" << std::endl;
    }
};

void SomeStoreFunction(std::shared_ptr<int> ptr) {
    someIntsToStore.push_back(ptr);
}

void CreateSPAndStoreInt() {
    std::cout << "Let's create some Example structs with ints and store them "
                 "in special vector for good times" << std::endl;
    std::shared_ptr<Example> pExample(std::make_shared<Example>());

    // We going to store in pInt value from pExample, making dependecy to
    // pExample. pExample will live till end of life of pInt;
    std::shared_ptr<int> pInt(pExample, &pExample->value);
    SomeStoreFunction(pInt);
    std::cout << "Doing some stuff here and exit" << std::endl;
}

}

void UsageOfAliasingConstructor() {
    CreateSPAndStoreInt();
    std::cout << "We exit CreateSPAndStoreInt() func and all objects, that were"
                 " created inside it, should be removed. But not this time!" <<
                 std::endl;
    std::cout << "Size of vector with ints: " << someIntsToStore.size() <<
                 "; value = " << *(someIntsToStore.front()) << std::endl;
    std::cout << "Let's clear vector" << std::endl;
    someIntsToStore.clear();
    std::cout << "Now all objects being destroyed!" << std::endl;
}

#endif // STD_SHARED_PTR_HPP
