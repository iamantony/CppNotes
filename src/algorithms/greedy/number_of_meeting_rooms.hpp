#ifndef CPPNOTESMAIN_NUMBER_OF_MEETING_ROOMS_HPP
#define CPPNOTESMAIN_NUMBER_OF_MEETING_ROOMS_HPP

/*
https://leetcode.com/problems/meeting-rooms-ii/
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...]
(si < ei), find the minimum number of conference rooms required.

Example 1:
Input: [[0, 30],[5, 10],[15, 20]]
Output: 2

Example 2:
Input: [[7,10],[2,4]]
Output: 1
*/

#include <vector>
#include <algorithm>
#include <queue>

namespace Algo::Greedy {
    class NumberOfMeetingRooms {
    public:
        static int calc(std::vector<std::vector<int>>& intervals) {
            if (intervals.empty()) { return 0; }

            std::sort(
                intervals.begin(),
                intervals.end(),
                [](const auto& left, const auto& right){ return left.front() < right.front(); });

            std::vector<size_t> rooms = {0};
            for (size_t i = 1; i < intervals.size(); ++i) {
                bool have_room = false;
                const auto& current_interval = intervals[i];
                for (size_t r = 0; r < rooms.size(); ++r) {
                    const auto& meeting_interval = intervals[rooms[r]];
                    if (meeting_interval.back() < current_interval.front()) {
                        have_room = true;
                        rooms[r] = i;
                        break;
                    }
                }

                if (!have_room) { rooms.push_back(i); }
            }

            return static_cast<int>(rooms.size());
        }

        static int calc_with_pq(std::vector<std::vector<int>>& intervals) {
            std::sort(
                intervals.begin(),
                intervals.end(),
                [](const auto& left, const auto& right){ return left.front() < right.front(); });

            std::priority_queue<int, vector<int>, greater<int>> pq;
            for (const auto& interval : intervals) {
                if (!pq.empty() && pq.top() <= interval.front()) { pq.pop(); }

                pq.push(interval.back());
            }
            return static_cast<int>(pq.size());
        }
    };
}

#endif //CPPNOTESMAIN_NUMBER_OF_MEETING_ROOMS_HPP
