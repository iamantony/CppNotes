#ifndef ASSOCIATE_THREAD_OF_EXECUTION_HPP
#define ASSOCIATE_THREAD_OF_EXECUTION_HPP

#include <iostream>
#include <thread>

namespace Threads {

void func() {
    std::cout << std::this_thread::get_id() << " In func()" << std::endl;
}

void funcWithArgs(int x, int y) {
    std::cout << std::this_thread::get_id() << " In funcWithArgs(): " <<
              x << " , " << y << std::endl;
}

class Example {
public:
    explicit Example(int value) : m_value(value) {}

    void operator() (int x) {
        std::cout << std::this_thread::get_id() << " In Example: " <<
                     m_value + x << std::endl;
    }

private:
    int m_value = 0;
};


void StartExamplesOfHowToAssociateThreadOfExecution() {
    std::thread t1(func);
    std::thread t2(funcWithArgs, 10, 11);
    std::thread t3(Example(42), -5);
    std::thread t4([]() {
        std::cout << std::this_thread::get_id() << " In lambda" << std::endl;
    });

    t1.join();
    t2.join();
    t3.join();
    t4.join();
}

}

#endif // ASSOCIATE_THREAD_OF_EXECUTION_HPP
