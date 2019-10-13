#ifndef MAX_QUEUE_HPP
#define MAX_QUEUE_HPP

#include <deque>
#include <limits>
#include <algorithm>

namespace Types::DS::Queue {

template<typename T>
class MaxQueue {
    std::deque<T> m_data;
    T m_max = std::numeric_limits<T>::min();

public:
    void push(const T& value) {
        m_data.push_back(value);
        m_max = std::max(value, m_max);
    }

    T max() const { return m_max; }
    size_t size() const { return m_data.size(); }
    bool empty() const { return size() == 0; }

    void pop() {
        if (empty()) { return; }

        const auto old_value = m_data.front();
        m_data.pop_front();
        if (empty()) {
            m_max = std::numeric_limits<T>::min();
            return;
        }

        if (old_value != max()) { return; }

        auto max_value = *(std::max_element(m_data.begin(), m_data.end()));
        m_max = max_value;
    }
};
}

#endif // MAX_QUEUE_HPP
