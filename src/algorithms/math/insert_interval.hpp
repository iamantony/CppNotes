#ifndef INSERT_INTERVAL_HPP
#define INSERT_INTERVAL_HPP

/*
https://leetcode.com/problems/insert-interval/
Given a set of non-overlapping intervals, insert a new interval into
the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their
start times.

Example 1:
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Example 2:
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
*/

#include <vector>

namespace Algo::Math {
class InsertInverval {
    static int& Start(std::vector<int>& interval) {
        return interval[0];
    }

    static int& End(std::vector<int>& interval) {
        return interval[1];
    }

    static void Check(std::vector<int>& interval) {
         if (interval.size() == 2 && Start(interval) > End(interval)) {
             std::swap(Start(interval), End(interval));
         }
    }

public:
    // TS: O(n)
    // SC: O(n)
    static std::vector<std::vector<int>> Insert(
            std::vector<std::vector<int>>& intervals,
            std::vector<int>& newInterval) {
        Check(newInterval);

        std::vector<std::vector<int>> result;
        bool inserted = false;
        for (size_t i = 0; i < intervals.size(); ++i) {
            Check(intervals[i]);

            if (inserted) {
                result.push_back(intervals[i]);
                continue;
            }

            // case: [3, 5] and [1, 2] ----> [1, 2], [3, 5]
            if (Start(intervals[i]) > End(newInterval)) {
                result.push_back(newInterval);
                inserted = true;

                result.push_back(intervals[i]);
            }
            // case: [3, 5] and [1, 3] ---> [1, 5]
            else if (End(intervals[i]) >= Start(newInterval)) {
                auto min_val = std::min(Start(intervals[i]), Start(newInterval));
                auto max_val = std::max(End(intervals[i]), End(newInterval));

                newInterval = {min_val, max_val};
            }
            else if (End(intervals[i]) < End(newInterval)) {
                // case: [3, 5] and [2, 6] ---> skip
                if (Start(intervals[i]) > Start(newInterval)) {
                    continue;
                }
                //case: [1, 2] and [5, 6] ---> [1, 2]
                else if (Start(intervals[i]) < Start(newInterval) &&
                         End(intervals[i]) < Start(newInterval)) {
                    result.push_back(intervals[i]);
                }
                //case: [1, 4] and [3, 6] ---> [1, 6]
                else if (Start(intervals[i]) < Start(newInterval) &&
                         End(intervals[i]) >= Start(newInterval)) {
                    Start(newInterval) = Start(intervals[i]);
                }
            }
        }

        // case: newInterval is the last one
        if (!inserted && newInterval.size() == 2) {
            result.push_back(newInterval);
        }

        return result;
    }
};
}

#endif // INSERT_INTERVAL_HPP
