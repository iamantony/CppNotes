#ifndef CPPNOTESMAIN_REORDER_DATA_IN_LOG_FILES_HPP
#define CPPNOTESMAIN_REORDER_DATA_IN_LOG_FILES_HPP

/*
https://leetcode.com/problems/reorder-data-in-log-files/
You have an array of logs.  Each log is a space delimited string of words.

For each log, the first word in each log is an alphanumeric identifier.  Then, either:
- Each word after the identifier will consist only of lowercase letters, or;
- Each word after the identifier will consist only of digits.

We will call these two varieties of logs letter-logs and digit-logs.  It is guaranteed that each
log has at least one word after its identifier.

Reorder the logs so that all of the letter-logs come before any digit-log.  The letter-logs are
ordered lexicographically ignoring identifier, with the identifier used in case of ties.
The digit-logs should be put in their original order.

Return the final order of the logs.

Example 1:
Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]

Constraints:
- 0 <= logs.length <= 100
- 3 <= logs[i].length <= 100
- logs[i] is guaranteed to have an identifier, and a word after the identifier.
*/

#include <algorithm>
#include <string>
#include <vector>

namespace Algo::DS::String {
    class ReorderDataInLogFiles {
        struct Log {
            std::string id;
            std::string data;

            explicit Log(const std::string& log_str) {
                const auto space_pos = log_str.find(' ');
                if (space_pos == std::string::npos) {
                    throw std::runtime_error("Invalid log string");
                }

                id = log_str.substr(0, space_pos);
                data = log_str.substr(space_pos + 1);
            }

            std::string to_log_str() const {
                return id + ' ' + data;
            }
        };

        std::vector<Log> m_digit_logs;
        std::vector<Log> m_letter_logs;

        void clean() {
            m_digit_logs.clear();
            m_letter_logs.clear();
        }

        bool is_digit_log(const Log& log) const {
            for (const auto& ch : log.data) {
                if (!(ch == ' ' || (ch >= '0' && ch <= '9'))) {
                    return false;
                }
            }

            return true;
        }

        void process_log_string(const std::string& log_str) {
            Log log(log_str);
            is_digit_log(log) ? m_digit_logs.push_back(log) : m_letter_logs.push_back(log);
        }

        void sort_letter_logs() {
            std::sort(
                m_letter_logs.begin(),
                m_letter_logs.end(),
                [](const auto& left_log, const auto& right_log) {
                    if (left_log.data == right_log.data) {
                        return left_log.id < right_log.id;
                    }

                    return left_log.data < right_log.data;
                });
        }

        std::vector<std::string> prepare_result() {
            std::vector<std::string> result;
            result.reserve(m_letter_logs.size() + m_digit_logs.size());

            auto pusher = [&result](const auto& log){
                result.push_back(log.to_log_str());
            };

            std::for_each(m_letter_logs.begin(), m_letter_logs.end(), pusher);
            std::for_each(m_digit_logs.begin(), m_digit_logs.end(), pusher);
            return result;
        }

    public:
        std::vector<std::string> reorder(const std::vector<std::string>& logs) {
            clean();
            for (const auto& log_str : logs) {
                process_log_string(log_str);
            }

            sort_letter_logs();
            return prepare_result();
        }
    };
}

#endif //CPPNOTESMAIN_REORDER_DATA_IN_LOG_FILES_HPP
