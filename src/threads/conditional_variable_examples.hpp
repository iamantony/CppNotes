#ifndef CONDITIONAL_VARIABLE_EXAMPLES_HPP
#define CONDITIONAL_VARIABLE_EXAMPLES_HPP

#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <random>
#include <iostream>

using namespace std::chrono_literals;

namespace Threads {

std::mutex dataMutex, counterMutex;
std::queue<int> data;
size_t counter = 10;
std::condition_variable condition;

void DataGenerator() {
    std::random_device randDev;
    std::mt19937 mt(randDev());
    std::uniform_int_distribution<int> dist(0, 99);
    while(counter > 0) {
        {
            std::lock_guard<std::mutex> lk(counterMutex);
            --counter;
        }

        const int value = dist(mt);
        std::cout << std::this_thread::get_id() << " Generated value: " <<
                     value << std::endl;

        {
            std::lock_guard<std::mutex> lk(dataMutex);
            data.push(value);
            condition.notify_one();
        }

        std::this_thread::sleep_for(0.5s);
    }
}

void DataConsumer() {
    while (true) {
        std::unique_lock<std::mutex> lk(dataMutex);
        condition.wait(lk, []{ return !data.empty(); });

        // here dataMutex will be locked, so it is safe to get value from queue
        const int value = data.front();
        data.pop();
        // we should not block generator of values, so unlock dataMutex. That
        // is why we use unique_lock instead of lock_guard
        dataMutex.unlock();

        // do some stuff with consumed value
        std::cout << std::this_thread::get_id() << " Consumed value: " <<
                     value << std::endl;

        {
            std::lock_guard<std::mutex> counterLock(counterMutex);
            if (counter == 0) {
                break;
            }
        }
    }
}

void Start() {
    std::thread t1(DataGenerator);
    std::thread t2(DataConsumer);

    t1.join();
    t2.join();
}

}

#endif // CONDITIONAL_VARIABLE_EXAMPLES_HPP
