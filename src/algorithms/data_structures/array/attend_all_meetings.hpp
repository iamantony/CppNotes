#ifndef CPPNOTESMAIN_ATTEND_ALL_MEETINGS_HPP
#define CPPNOTESMAIN_ATTEND_ALL_MEETINGS_HPP

/*
https://leetcode.com/problems/meeting-rooms/
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...]
(si < ei), determine if a person could attend all meetings.

Example 1:
Input: [[0,30],[5,10],[15,20]]
Output: false

Example 2:
Input: [[7,10],[2,4]]
Output: true
*/

#include <vector>
#include <algorithm>

namespace Algo::DS::Array {
    class AttendAllMeetings {
    public:
        static bool can_attend(std::vector<std::vector<int>>& intervals) {
            std::sort(
                intervals.begin(),
                intervals.end(),
                [](const auto& left, const auto& right){ return left.front() < right.front(); });

            for (size_t i = 1; i < intervals.size(); ++i) {
                if (intervals[i - 1].back() > intervals[i].front()) {
                    return false;
                }
            }

            return true;
        }
    };
}

#endif //CPPNOTESMAIN_ATTEND_ALL_MEETINGS_HPP
