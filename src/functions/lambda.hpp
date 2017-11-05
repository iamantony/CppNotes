#ifndef FUNCTIONS_LAMBDA_H_
#define FUNCTIONS_LAMBDA_H_

#include <functional>
#include <iostream>

void BasicLambda()
{
    // TODO
}

void RecursiveLambda()
{
    // Let's calc factorial
    // If we want use recursive lambda, we should:
    // - do not use 'auto' in lambda declaration. Use std::function
    // - lambda should capture its name so it could call itself
    std::function<int (int)> factorial = [&factorial](int number)
    {
        if (number == 0)
        {
            return 1;
        }

        return number * factorial(number - 1);
    };

    std::cout << "Calc 5! using recursive lambda: " << factorial(5) <<
                 std::endl;
}

#endif // FUNCTIONS_LAMBDA_H_
