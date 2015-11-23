#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "algorithms/euler/problem12.hpp"

int main()
{
    std::cout << "CppNotes" << std::endl << std::endl;

    Problem *problem = new Problem12();
    problem->Solve();
    delete problem;

    return (0);
}
