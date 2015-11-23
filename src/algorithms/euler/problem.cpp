#include "problem.hpp"

#include <iostream>
#include <chrono>

void Problem::Solve()
{
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    DoSolve();

    end = std::chrono::system_clock::now();
    std::chrono::duration<double> secElapsed = end - start;
    std::cout << "Elapsed time: " << secElapsed.count() << " s" << std::endl;
}
