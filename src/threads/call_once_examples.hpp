#ifndef CALL_ONCE_EXAMPLES_HPP
#define CALL_ONCE_EXAMPLES_HPP

#include <thread>
#include <mutex>
#include <memory>
#include <iostream>

using namespace std::chrono_literals;

namespace Threads {

std::once_flag flag;
std::shared_ptr<int> ptr;

void InitPtr() {
    std::cout << std::this_thread::get_id() << " InitPtr()" << std::endl;
    std::this_thread::sleep_for(1s);
    ptr.reset(new int(15));
}

void AccessPtr() {
    std::call_once(flag, InitPtr);
    std::cout << std::this_thread::get_id() << " AccessPtr(): " << *ptr <<
                 std::endl;
}

void Start() {
    std::thread st1(AccessPtr);
    std::thread st2(AccessPtr);
    std::thread st3(AccessPtr);
    std::thread st4(AccessPtr);
    st1.join();
    st2.join();
    st3.join();
    st4.join();
}

}

#endif // CALL_ONCE_EXAMPLES_HPP
