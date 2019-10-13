#ifndef SLIDING_WINDOW_MAX_HPP
#define SLIDING_WINDOW_MAX_HPP

/*
https://leetcode.com/problems/sliding-window-maximum/
Given an array nums, there is a sliding window of size k which is moving
from the very left of the array to the very right. You can only see the k
numbers in the window. Each time the sliding window moves right by one
position. Return the max sliding window.

Example:
Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7]
*/

#include <vector>
#include <deque>

namespace Algo::DS::Queue {

template<typename T>
class SlidingWindow {
public:
    static std::vector<T> Max(
            const std::vector<T>& data, const size_t window_size) {
        if (data.empty() || window_size == 0) { return {}; }

        std::deque<size_t> dq;
        std::vector<T> result;
        for (size_t i = 0; i < data.size(); ++i) {
            if (!dq.empty() &&
                    i >= window_size &&
                    dq.front() == i - window_size) {
                dq.pop_front();
            }

            while(!dq.empty() && data[dq.back()] < data[i]) {
                dq.pop_back();
            }

            dq.push_back(i);
            if (i >= window_size - 1) {
                result.push_back(data[dq.front()]);
            }
        }

        return result;
    }
};
}

#endif // SLIDING_WINDOW_MAX_HPP
