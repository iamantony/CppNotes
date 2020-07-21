#ifndef CPPNOTESMAIN_TASK_SCHEDULER_HPP
#define CPPNOTESMAIN_TASK_SCHEDULER_HPP

/*
https://leetcode.com/problems/task-scheduler/
You are given a char array representing tasks CPU need to do. It contains capital letters A to Z
where each letter represents a different task. Tasks could be done without the original order of
the array. Each task is done in one unit of time. For each unit of time, the CPU could complete
either one task or just be idle.

However, there is a non-negative integer n that represents the cooldown period between two same
tasks (the same letter in the array), that is that there must be at least n units of time between
any two same tasks.

You need to return the least number of units of times that the CPU will take to finish all the
given tasks.

Example 1:
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation:
A -> B -> idle -> A -> B -> idle -> A -> B
There is at least 2 units of time between any two same tasks.

Example 2:
Input: tasks = ["A","A","A","B","B","B"], n = 0
Output: 6
Explanation: On this case any permutation of size 6 would work since n = 0.
["A","A","A","B","B","B"]
["A","B","A","B","A","B"]
["B","B","B","A","A","A"]
...
And so on.

Example 3:
Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
Output: 16
Explanation:
One possible solution is
A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle -> idle -> A

Constraints:
- The number of tasks is in the range [1, 10000].
- The integer n is in the range [0, 100].
*/

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <limits>

namespace Algo::Greedy {
    class TaskScheduler {
        static std::vector<std::pair<char, size_t>> count_tasks(const std::vector<char>& tasks) {
            std::unordered_map<char, size_t> count_map;
            for (const auto& t : tasks) {
                ++count_map[t];
            }

            std::vector<std::pair<char, size_t>> task_count;
            for (const auto& [t, c] : count_map) {
                task_count.push_back({t, c});
            }

            return task_count;
        }

        static void update_task_count(std::vector<std::pair<char, size_t>>& task_count) {
            std::sort(
                task_count.begin(),
                task_count.end(),
                [](const auto& left, const auto& right){ return left.second > right.second; });

            const auto zero_iter = std::find_if(
                task_count.begin(),
                task_count.end(),
                [](const auto& pair){ return pair.second == 0; });

            task_count.erase(zero_iter, task_count.end());
        }

    public:
        // https://leetcode.com/problems/task-scheduler/discuss/104504/C%2B%2B-8lines-O(n)
        static int schedule_quick(const std::vector<char>& tasks, const int n) {
            // First count the number of occurrences of each element.
            std::unordered_map<char, int> count_map;
            int count = 0;
            for(auto& task : tasks)
            {
                count_map[task]++;
                count = std::max(count, count_map[task]);
            }

            // Let the max frequency seen be M for element T
            // We can schedule the first M-1 occurrences of T, each T will be followed by at least
            // N CPU cycles in between successive schedules of T.
            // Total CPU cycles after scheduling M-1 occurrences of T = (M-1) * (N + 1). 1 comes
            // for the CPU cycle for E itself
            int ans = (count - 1) * (n + 1);

            // Now schedule the final round of tasks. We will need at least 1 CPU cycle of the last
            // occurrence of T. If there are multiple tasks with frequency M, they will all need 1
            // more cycle.
            // Run through the frequency dictionary and for every element which has frequency == M,
            // add 1 cycle to result.
            for(const auto& [task, freq] : count_map) {
                if(freq == count) { ++ans; }
            }

            // If we have more number of tasks than the max slots we need as computed above we will
            // return the length of the tasks array as we need at least those many CPU cycles.
            // To understand this line try to dry run the test case ['A','B','C'] with n=1
            return std::max(static_cast<int>(tasks.size()), ans);
        }

        static int schedule_full(const std::vector<char>& tasks, const int n) {
            std::vector<std::pair<char, size_t>> task_count = count_tasks(tasks);
            update_task_count(task_count);

            const char IDLE = '0';
            const size_t CP = static_cast<size_t>(n);
            std::unordered_map<char, size_t> pos_map;
            std::vector<char> queue;
            while (!task_count.empty()) {
                size_t distance = 0;
                size_t task_index = task_count.size();
                const size_t next_pos = queue.size();
                for (size_t i = 0; i < task_count.size(); ++i) {
                    auto& task_item = task_count[i];
                    if (pos_map.count(task_item.first) == 0) {
                        distance = CP;
                        task_index = i;
                        break;
                    }

                    const auto task_distance = next_pos - pos_map[task_item.first] - 1;
                    if (task_distance >= distance) {
                        distance = task_distance;
                        task_index = i;
                        if (distance >= CP) {
                            break;
                        }
                    }
                }

                while (distance < CP) {
                    queue.push_back(IDLE);
                    ++distance;
                }

                auto& task_item = task_count[task_index];
                queue.push_back(task_item.first);
                --task_item.second;
                pos_map[task_item.first] = queue.size() - 1;
                update_task_count(task_count);
            }

            return static_cast<int>(queue.size());
        }
    };
}

#endif //CPPNOTESMAIN_TASK_SCHEDULER_HPP
