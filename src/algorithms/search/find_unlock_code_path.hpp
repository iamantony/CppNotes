#ifndef FIND_UNLOCK_CODE_PATH_HPP
#define FIND_UNLOCK_CODE_PATH_HPP

/*
https://leetcode.com/problems/open-the-lock/
You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots:
'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can rotate freely and wrap around:
for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of turning one
wheel one slot.

The lock initially starts at '0000', a string representing the state of the 4 wheels.

You are given a list of deadends dead ends, meaning if the lock displays any of these codes,
the wheels of the lock will stop turning and you will be unable to open it.

Given a target representing the value of the wheels that will unlock the lock,
return the minimum total number of turns required to open the lock, or -1 if it is impossible.

Example 1:
Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
Output: 6
Explanation:
A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
because the wheels of the lock become stuck after the display becomes the dead end "0102".

Example 2:
Input: deadends = ["8888"], target = "0009"
Output: 1
Explanation:
We can turn the last wheel in reverse to move from "0000" -> "0009".

Example 3:
Input: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
Output: -1
Explanation:
We can't reach the target without getting stuck.

Example 4:
Input: deadends = ["0000"], target = "8888"
Output: -1

Note:
The length of deadends will be in the range [1, 500].
target will not be in the list deadends.
Every string in deadends and the string target will be a string of 4 digits from the 10,000
possibilities '0000' to '9999'.
*/

#include <vector>
#include <unordered_set>
#include <string>

namespace Algo::Search {
    class UnlockCodePath {
        static std::vector<std::string> neighborCodes(const std::string& code) {
            const std::vector<char> nextNum = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
            const std::vector<char> prevNum = {'9', '0', '1', '2', '3', '4', '5', '6', '7', '8'};

            std::vector<std::string> neighbors;
            for (size_t i = 0; i < code.size(); ++i) {
                {
                    auto nextCode = code;
                    nextCode[i] = nextNum[static_cast<size_t>(nextCode[i] - '0')];
                    neighbors.push_back(nextCode);
                }

                {
                    auto prevCode = code;
                    prevCode[i] = prevNum[static_cast<size_t>(prevCode[i] - '0')];
                    neighbors.push_back(prevCode);
                }
            }

            return neighbors;
        }

    public:
        // TC: O(10^4) because code is a string of 4 digits with values in [0, 9]
        // SC: O(4 * 10^4)
        static int find_dfs(const std::vector<std::string>& deadends, const std::string& target) {
            if (target.empty()) { return -1; }

            std::unordered_set<std::string> forbiddenCodes(deadends.begin(), deadends.end());
            std::string startCode = "0000";
            if (forbiddenCodes.count(target) > 0 || forbiddenCodes.count(startCode) > 0) {
                return -1;
            }

            if (startCode == target) { return 0; }

            std::unordered_set<std::string> visitedCodes, codesToProcess;
            visitedCodes.insert(startCode);
            codesToProcess.insert(startCode);

            int depth = 0;
            while (!codesToProcess.empty()) {
                const auto codes = codesToProcess;
                codesToProcess.clear();
                for (const auto& code : codes) {
                    const auto neighbors = neighborCodes(code);
                    for (const auto nCode : neighbors) {
                        if (nCode == target) { return depth + 1; }
                        if (forbiddenCodes.count(nCode) > 0 || visitedCodes.count(nCode) > 0) {
                            continue;
                        }

                        visitedCodes.insert(nCode);
                        codesToProcess.insert(nCode);
                    }
                }

                ++depth;
            }

            return -1;
        }
    };
}

#endif //FIND_UNLOCK_CODE_PATH_HPP
