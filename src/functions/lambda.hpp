#ifndef FUNCTIONS_LAMBDA_H_
#define FUNCTIONS_LAMBDA_H_

#include <functional>
#include <iostream>

void BasicLambda()
{
    auto add5 = [](int value) {
        return value + 5;
    };

    std::cout << "add5(10): " << add5(10) << std::endl;
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

    constexpr auto fib = [](auto fib_func, int value) {
        if (value < 2) {
            return 1;
        }

        return fib_func(fib_func, value - 1) +
                fib_func(fib_func, value - 2);
    };

    std::cout << "Calc Fibonacci number of 5 using 2nd version "
                 "of recursive lambda: " << fib(fib, 5) << std::endl;

    auto fib2 = [](int value) {
        auto fib_impl = [](auto fib_func, int val) {
            if (val < 2) {
                return 1;
            }

            return fib_func(fib_func, val - 1) +
                    fib_func(fib_func, val - 2);
        };

        return fib_impl(fib_impl, value);
    };

    std::cout << "Calc Fibonacci number of 6 using 3rd version "
                 "of recursive lambda: " << fib2(6) << std::endl;
}

#endif // FUNCTIONS_LAMBDA_H_
