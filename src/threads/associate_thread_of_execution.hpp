#ifndef ASSOCIATE_THREAD_OF_EXECUTION_HPP
#define ASSOCIATE_THREAD_OF_EXECUTION_HPP

#include <iostream>
#include <thread>

namespace Threads {

void func() {
    std::cout << std::this_thread::get_id() << " In func()" << std::endl;
}

void funcWithArgs(int x, int& y) {
    std::cout << std::this_thread::get_id() << " In funcWithArgs(): " <<
              x << " , " << y << std::endl;

    ++y;
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

class Worker {
public:
    void DoWork(int no, int yes) {
        if (no < yes) {
            std::cout << std::this_thread::get_id() <<
                         " In DoWork(): I'm gonna show you my precious: " <<
                         m_precious << std::endl;
        }
        else {
            std::cout << std::this_thread::get_id() <<
                         " In Example(): sorry, I'm poor" << std::endl;
        }
    }

private:
    int m_precious = 2^10;
};

void StartExamplesOfHowToAssociateThreadOfExecution() {
    std::thread t1(func);

    int mainY = 11;
    std::thread t2(funcWithArgs, 10, std::ref(mainY));
    std::thread t3(Example(42), -5);

    Worker workerObject;
    std::thread t4(&Worker::DoWork, &workerObject, 0, 1);
    std::thread t5([]() {
        std::cout << std::this_thread::get_id() << " In lambda" << std::endl;
    });

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    std::cout << "In main thread mainY = " << mainY << std::endl;
}

}

#endif // ASSOCIATE_THREAD_OF_EXECUTION_HPP
