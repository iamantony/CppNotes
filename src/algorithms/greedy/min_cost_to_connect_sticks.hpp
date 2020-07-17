#ifndef CPPNOTESMAIN_MIN_COST_TO_CONNECT_STICKS_HPP
#define CPPNOTESMAIN_MIN_COST_TO_CONNECT_STICKS_HPP

/*
https://leetcode.com/problems/minimum-cost-to-connect-sticks/
You have some sticks with positive integer lengths.

You can connect any two sticks of lengths X and Y into one stick by paying a cost of X + Y.
You perform this action until there is one stick remaining.

Return the minimum cost of connecting all the given sticks into one stick in this way.

Example 1:
Input: sticks = [2,4,3]
Output: 14

Example 2:
Input: sticks = [1,8,3,5]
Output: 30

Constraints:
- 1 <= sticks.length <= 10^4
- 1 <= sticks[i] <= 10^4
*/

#include <vector>
#include <queue>

namespace Algo::Greedy {
    class MinCostToConnectSticks {
    public:
        static int calc(std::vector<int> sticks) {
            if (sticks.size() <= 1) { return 0; }

            int cost = 0;
            std::priority_queue<int, std::vector<int>, std::greater<int> > pq(
                sticks.begin(), sticks.end());

            while (pq.size() > 1) {
                int sum = pq.top();
                pq.pop();
                sum += pq.top();
                pq.pop();

                cost += sum;
                pq.push(sum);
            }

            return cost;
        }
    };
}

#endif //CPPNOTESMAIN_MIN_COST_TO_CONNECT_STICKS_HPP
