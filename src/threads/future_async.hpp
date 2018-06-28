#ifndef FUTURE_ASYNC_HPP
#define FUTURE_ASYNC_HPP

#include <future>
#include <iostream>

using namespace std::chrono_literals;

namespace Threads {

int SimpleFunction() {
    const int result = 10;
    std::cout << std::this_thread::get_id() << " In SimpleFunction(): " <<
                 result << std::endl;

    std::this_thread::sleep_for(1s);
    return result;
}

class Example {
public:
    std::string GenerateString(const int value, const std::string base) {
        const std::string result = base + std::to_string(value + (m_value++));
        std::cout << std::this_thread::get_id() << " In GenerateString(): " <<
                     result << std::endl;

        std::this_thread::sleep_for(1s);
        return result;
    }

private:
    int m_value = 0;
};

void Start() {
    std::cout << "Main thread ID: " <<  std::this_thread::get_id() << std::endl;

    std::future<int> f1 = std::async(SimpleFunction);
    std::cout << "Get value from SimpleFunction() asynchronously: " <<
                 f1.get() << std::endl;

    Example ex;

    // We will call GenerateString() asynchronously
    auto f2 = std::async(std::launch::async, &Example::GenerateString, &ex,
                         10, std::string("result_async = "));
    std::this_thread::sleep_for(0.5s);
    std::cout << "Going to get value of f2: ";
    std::cout << f2.get() << std::endl;

    // We will call GenerateString() only when we call get() on future variable
    auto f3 = std::async(std::launch::deferred, &Example::GenerateString, &ex,
                         15, std::string("result_deferred = "));
    std::this_thread::sleep_for(0.5s);
    std::cout << std::endl << "Going to get value of f3: " << std::endl;
    std::cout << f3.get() << std::endl;

    // duration-based wait
    std::cout << "Going to wait SimpleFunction() for 1ns" << std::endl;
    std::future<int> f4 = std::async(SimpleFunction);
    auto waitResult = f4.wait_for(std::chrono::nanoseconds(1));
    switch(waitResult) {
    case std::future_status::ready:
        std::cout << "Ready. Wow, too fast" << std::endl;
        break;

    case std::future_status::deferred:
        std::cout << "Deferred. Hah, you even did not start yet" << std::endl;
        break;

    case std::future_status::timeout:
        std::cout << "Timeout. Sorry, toooo long!" << std::endl;
        break;

    default:
        std::cout << "Unexpected default case" << std::endl;
    }
}

}

#endif // FUTURE_ASYNC_HPP
