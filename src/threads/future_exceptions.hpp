#ifndef FUTURE_EXCEPTIONS_HPP
#define FUTURE_EXCEPTIONS_HPP

#include <future>
#include <iostream>

namespace Threads {

double Divide(const int dividend, const int divisor) {
    if (divisor == 0) {
        throw std::invalid_argument("divisor == 0");
    }

    return dividend / divisor;
}

void Start() {
    std::future<double> f1 = std::async(Divide, 10, 2);
    std::cout << "Divide 10 by 2: " << f1.get() << std::endl;

    std::future<double> f2 = std::async(Divide, 2, 0);
    try {
        const double result = f2.get();
        std::cout << "This will not be printed: " << result << std::endl;
    }
    catch(std::exception& e) {
        std::cout << "Division error: " << e.what() << std::endl;
    }
}

}

#endif // FUTURE_EXCEPTIONS_HPP
