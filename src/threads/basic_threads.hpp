#ifndef BASIC_THREADS_HPP
#define BASIC_THREADS_HPP

#include <thread>
#include <iostream>

using namespace std::chrono_literals;

namespace Threads {

void function() {
    for (int i = 0; i < 5; ++i) {
        std::cout << std::this_thread::get_id() << " In function(): " << i <<
                     std::endl;

        std::this_thread::sleep_for(1.5s);
    }
}

void iterate(const int i) {
    for (int j = 0; j < i; ++j) {
        std::cout << std::this_thread::get_id() << " In iterate(): " << j <<
                     std::endl;

        std::this_thread::sleep_for(1.2s);
    }
}

void StartSimpleThread() {
    // Start a thread that will call function()
    std::thread t1(function);

    // Start a thread that will call iterate() with specified parameter.
    // If we pass reference or a pointer to the new thread, we must be sure
    // that this variable will be not destroyed during work of the thread.
    // Here we copy paramter to the thread.
    int i = 10;
    std::thread t2(iterate, i);

    // Do some work in main thread
    for (int k = 0; k < 5; ++k) {
        std::cout << std::this_thread::get_id() << " In main thread: " << k <<
                     std::endl;

        std::this_thread::sleep_for(1s);
    }

    // Do not exit program till launched threads finish (joined)!
    // If we don't call join(), at the end of the function destructor of the
    // thread will be called. Destructor will check if thread is joinable.
    // And if it is, it will call std::terminate() that will call by default
    // std::abort.
    t1.join();
    t2.join();

    std::cout << "Done" << std::endl;
}

}

#endif // BASIC_THREADS_HPP
