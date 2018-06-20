#ifndef DETACHED_THREAD_HPP
#define DETACHED_THREAD_HPP

#include <iostream>
#include <thread>

using namespace std::chrono_literals;

namespace Threads {

// Detached threads are often called daemon threads after the UNIX concept of a
// daemon process that runs in the background without any explicit user
// interface. Such threads are typically long-running: they may well run for
// almost the entire lifetime of the application, performing a background task.

void func() {
    for (int i = 0; i < 5; ++i) {
        std::cout << std::this_thread::get_id() << " In detached thread: " <<
                     i << std::endl;

        std::this_thread::sleep_for(1s);
    }
}

void StartExampleOfDetachedThread() {
    std::thread detachedThread(func);
    detachedThread.detach();

//    The thread of execution no longer has an associated management object,
//    just as if the std::thread object had been destroyed. The C++ runtime
//    library is therefore responsible for cleaning up the resources associated
//    with running the thread when it completes.

//    If right here we will finish execution of our program, detached thread
//    will automatically terminated by C++ runtime library. And we don't know
//    on which step it will be sopped. It may even do not execute any
//    line of code yet!
//    return 0;

    std::this_thread::sleep_for(5s);
}

}

#endif // DETACHED_THREAD_HPP
