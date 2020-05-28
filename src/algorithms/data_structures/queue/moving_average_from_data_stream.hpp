#ifndef CPPNOTESMAIN_MOVING_AVERAGE_FROM_DATA_STREAM_HPP
#define CPPNOTESMAIN_MOVING_AVERAGE_FROM_DATA_STREAM_HPP

/*
https://leetcode.com/problems/moving-average-from-data-stream/
Given a stream of integers and a window size, calculate the moving average of all integers in the
sliding window.

Example:
MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3
*/

#include <queue>

namespace Algo::DS::Queue {
    class MovingAverage {
        std::queue<int> m_nums;
        int m_sum = 0;
        size_t m_max_size;
    public:
        MovingAverage(int size) {
            m_max_size = static_cast<size_t>(size);
        }

        double next(int val) {
            m_nums.push(val);
            m_sum += val;
            if (m_nums.size() > m_max_size) {
                m_sum -= m_nums.front();
                m_nums.pop();
            }

            return static_cast<double>(m_sum) / static_cast<double>(m_nums.size());
        }
    };
}

#endif //CPPNOTESMAIN_MOVING_AVERAGE_FROM_DATA_STREAM_HPP
