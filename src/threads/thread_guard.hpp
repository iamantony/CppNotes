#ifndef THREAD_GUARD_HPP
#define THREAD_GUARD_HPP

#include <thread>

namespace Threads {

// ThreadGuard will automatically join() referenced thread when it will be
// deleted.
class ThreadGuard {
public:
    explicit ThreadGuard(std::thread& t) : m_thread(t) {}
    ~ThreadGuard() {
        if (m_thread.joinable()) {
            m_thread.join();
        }
    }

    ThreadGuard(const ThreadGuard& other) = delete;
    ThreadGuard& operator=(const ThreadGuard& other) = delete;

private:
    std::thread& m_thread;
};

}

#endif // THREAD_GUARD_HPP
