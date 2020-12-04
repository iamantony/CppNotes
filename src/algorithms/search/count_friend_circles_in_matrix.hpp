#ifndef CPPNOTESMAIN_COUNT_FRIEND_CIRCLES_IN_MATRIX_HPP
#define CPPNOTESMAIN_COUNT_FRIEND_CIRCLES_IN_MATRIX_HPP

/*
https://leetcode.com/problems/friend-circles/
There are N students in a class. Some of them are friends, while some are not. Their friendship is
transitive in nature. For example, if A is a direct friend of B, and B is a direct friend of C,
then A is an indirect friend of C. And we defined a friend circle is a group of students who are
direct or indirect friends.

Given a N*N matrix M representing the friend relationship between students in the class.
If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not.
And you have to output the total number of friend circles among all the students.

Example 1:
Input:
[[1,1,0],
 [1,1,0],
 [0,0,1]]
Output: 2
Explanation:The 0th and 1st students are direct friends, so they are in a friend circle.
The 2nd student himself is in a friend circle. So return 2.

Example 2:
Input:
[[1,1,0],
 [1,1,1],
 [0,1,1]]
Output: 1
Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends,
so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.

Constraints:
- 1 <= N <= 200
- M[i][i] == 1
- M[i][j] == M[j][i]
*/

#include <vector>
#include <queue>

namespace Algo::Search {
    class FriendCircles {
    public:
        static size_t count(std::vector<std::vector<int>> m) {
            if (m.empty() || m.front().empty()) { return 0; }

            const auto maxR = m.size();
            const auto maxC = m.front().size();

            size_t result = 0;
            for (size_t r = 0; r < maxR; ++r) {
                if (m[r][r] == 0) { continue; }

                ++result;
                m[r][r] = 0;
                std::queue<size_t> friends;
                for (size_t c = 0; c < maxC; ++c) {
                    if (m[r][c] == 1) { friends.push(c); }
                }

                while (!friends.empty()) {
                    const auto fr = friends.front();
                    friends.pop();

                    if (m[fr][fr] == 0) { continue; }

                    m[fr][fr] = 0;
                    for (size_t fc = 0; fc < maxC; ++fc) {
                        if (m[fr][fc] == 1) { friends.push(fc); }
                    }
                }
            }

            return result;
        }
    };
}

#endif //CPPNOTESMAIN_COUNT_FRIEND_CIRCLES_IN_MATRIX_HPP
