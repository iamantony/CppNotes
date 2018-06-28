#ifndef CLOCKS_HPP
#define CLOCKS_HPP

#include <chrono>
#include <iomanip>
#include <ratio>
#include <thread>
#include <iostream>

// http://www.modernescpp.com/index.php/the-three-clocks

using namespace std::chrono_literals;

namespace Time {

void GetCurrentTime() {
    // Get time as time_point
    auto systemNow = std::chrono::system_clock::now();

    // Convert time_point into time_t
    auto systemNowTime = std::chrono::system_clock::to_time_t(systemNow);

    // Print current time using specified format
    const char* timeFormat = "%d.%m.%Y %H:%M:%S";
    std::cout << "Current time by system clock: " <<
                 std::put_time(std::localtime(&systemNowTime), timeFormat) <<
                 std::endl;
}

template <typename T>
void printRatio(){
    std::cout << "  precision: " << T::num << "/" << T::den << " second " <<
                 std::endl;

    typedef typename std::ratio_multiply<T,std::kilo>::type MillSec;
    typedef typename std::ratio_multiply<T,std::mega>::type MicroSec;
    std::cout << std::fixed;
    std::cout << "             " <<
                 static_cast<double>(MillSec::num)/MillSec::den <<
                 " milliseconds " << std::endl;

    std::cout << "             " <<
                 static_cast<double>(MicroSec::num)/MicroSec::den <<
                 " microseconds " << std::endl;
}

void ClocksPeriod() {
    std::cout << std::boolalpha << std::endl;

    std::cout << "std::chrono::system_clock: " << std::endl;
    std::cout << "  is steady: " << std::chrono::system_clock::is_steady <<
                 std::endl;

    printRatio<std::chrono::system_clock::period>();
    std::cout << std::endl;

    std::cout << "std::chrono::steady_clock: " << std::endl;
    std::cout << "  is steady: " << std::chrono::steady_clock::is_steady <<
                 std::endl;

    printRatio<std::chrono::steady_clock::period>();
    std::cout << std::endl;

    std::cout << "std::chrono::high_resolution_clock: " << std::endl;
    std::cout << "  is steady: " <<
                 std::chrono::high_resolution_clock::is_steady << std::endl;
    printRatio<std::chrono::high_resolution_clock::period>();
    std::cout << std::endl;
}

void BenchmarkSomeOperation() {
    auto someOperation = []() {
        std::this_thread::sleep_for(1s);
    };

    auto start = std::chrono::high_resolution_clock::now();
    someOperation();
    auto stop = std::chrono::high_resolution_clock::now();
    std::cout << "someOperation() took " <<
                 std::chrono::duration<double>(stop-start).count() <<
                 "ms" << std::endl;
}

void Start() {
    GetCurrentTime();
    ClocksPeriod();
    BenchmarkSomeOperation();
}

}

#endif // CLOCKS_HPP
