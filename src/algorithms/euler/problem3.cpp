#include "problem3.hpp"

#include <iostream>
#include <math.h>

#include "common/primenumbers.hpp"

void Problem3::DoSolve()
{
    std::cout << "Problem 3" << std::endl;

    long unsigned int number = 600851475143;
    double numberAsDouble = static_cast<double>(number);
    long unsigned int numSqrt = static_cast<long unsigned int>(
                    floor(sqrt(numberAsDouble) + 0.5));

    std::vector<long unsigned int> primalNumbers =
                    PrimeNumbers::GetPrimeNumbers(numSqrt);

    long unsigned int lastPrimal = 0;
    for ( long unsigned int i = primalNumbers.size() - 1; i > 0; --i )
    {
        if ( 0 == number % primalNumbers[i] )
        {
            lastPrimal = primalNumbers[i];
            break;
        }
    }

    std::cout << "Answer = " << lastPrimal << std::endl;
}
