#ifndef THREADS_MUTEXES_HPP
#define THREADS_MUTEXES_HPP

#include <thread>
#include <mutex>
#include <iostream>
#include <vector>

using namespace std::chrono_literals;

namespace Threads {

void ProtectAccessToCommonDataUsingMutex() {
    std::vector<int> data;
    std::mutex mutex;

    std::thread t1([&]() {
        for (int i = 0; i < 5; ++i) {
            std::this_thread::sleep_for(0.5s);
            std::lock_guard<std::mutex> lock(mutex);
            data.push_back(i);
        }
    });

    std::thread t2([&]() {
        for (int i = 3; i < 6; ++i) {
            std::this_thread::sleep_for(0.7s);
            std::lock_guard<std::mutex> lock(mutex);
            data.push_back(i);
        }
    });

    t1.join();
    t2.join();

    std::cout << "Values in vector: ";
    for (const int& i : data) {
        std::cout << i << ", ";
    }

    std::cout << std::endl;
}

void StartMutexesExamples() {
    ProtectAccessToCommonDataUsingMutex();
}

}

#endif // THREADS_MUTEXES_HPP
