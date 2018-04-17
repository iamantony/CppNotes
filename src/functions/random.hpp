#ifndef RANDOM_HPP
#define RANDOM_HPP

// How to generate random numbers?

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>

// Old C++03 way
// http://en.cppreference.com/w/cpp/numeric/random/rand

// Problem with rand:
// https://channel9.msdn.com/Events/GoingNative/2013/rand-Considered-Harmful
// - small distance between min and max
// - it is possbile to start two pragrams at nearly same time and get equal
// random numbers
// - short period until it will repeat itself
void RandomNumbersUsingRand() {
    // First of all you should seed the pseudo-random generator using seed()
    // function.

    // Generally speaking, the pseudo-random number generator should only be
    // seeded once, before any calls to rand(), at the start of the program.
    // It should not be repeatedly seeded, or reseeded every time you wish
    // to generate a new batch of pseudo-random numbers.

    // Standard practice is to use the result of a call to time(0) as the seed.

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // At next step we can call rand() that will provide pseudo-random value
    // from 0 to RAND_MAX (implementation defined)
    std::cout << "Pseudo random values from rand():" << std::endl;
    for (size_t i = 0; i < 10; ++i) {
        std::cout << std::rand() << ", ";
    }

    std::cout << std::endl;
}

void RandomNumbersUsingModernCpp() {
    // Choose random seed number
    int seed = 42;

    // Use it as a seed for mersenne-twister generator that will generate
    // numbers [0, 2^32). It is extremely fast, producing high quality
    // numbers, but reproducible. If you want to use non-reproducable
    // generator, use std::random_device.
    std::mt19937 mt(seed);

    // After that use one of the distributions. Here we will use uniform
    // distribution that will generate numbers [0, 99]
    std::uniform_int_distribution<int> dist(0, 99);
    std::cout << "Pseudo random values from modern generator:" << std::endl;
    for (size_t i = 0; i < 10; ++i) {
        std::cout << dist(mt) << ", ";
    }

    std::cout << std::endl;
}

void RandomNumbers() {
    RandomNumbersUsingRand();
    RandomNumbersUsingModernCpp();
}

#endif // RANDOM_HPP
