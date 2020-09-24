#ifndef CPPNOTESMAIN_BINARY_WATCH_TIME_HPP
#define CPPNOTESMAIN_BINARY_WATCH_TIME_HPP

/*
https://leetcode.com/problems/binary-watch/
A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the
bottom represent the minutes (0-59). Each LED represents a zero or one, with the least significant
bit on the right.

Given a non-negative integer n which represents the number of LEDs that are currently on, return
all possible times the watch could represent.

Example:
Input: n = 1
Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]

Note:
- The order of output does not matter.
- The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
- The minute must be consist of two digits and may contain a leading zero, for example "10:2"
is not valid, it should be "10:02".
*/

#include <vector>
#include <string>
#include <algorithm>

namespace Algo::DP {
    class BinaryWatch {
        static const int max_h;
        static const int max_m;

        static std::string generate_impl(int n, int max_size) {
            std::string h(static_cast<size_t>(max_size), '0');
            std::fill_n(h.rbegin(), n, '1');
            return h;
        }

        static std::string generate_hours(int n) {
            return generate_impl(n, max_h);
        }

        static std::string generate_minutes(int n) {
            return generate_impl(n, max_m);
        }

        static int bin_str_to_int(std::string binary_str) {
            int res = 0;
            int counter = 0;
            for (auto iter = binary_str.rbegin(); iter != binary_str.rend(); ++iter, ++counter) {
                if (*iter != '1') { continue; }

                res += 1 << counter;
            }

            return res;
        }

        static std::vector<int> possible_nums(std::string binary_str) {
            std::vector<int> possible_nums;
            std::sort(binary_str.begin(), binary_str.end());
            do {
                possible_nums.push_back(bin_str_to_int(binary_str));
            }
            while(std::next_permutation(binary_str.begin(), binary_str.end()));

            return possible_nums;
        }

        static std::string to_time(int h, int m) {
            auto minutes = std::to_string(m);
            if (minutes.size() == 1) { minutes = "0" + minutes; }

            return std::to_string(h) + ":" + minutes;
        }

    public:
        static std::vector<std::string> get_time(int num_led_on) {
            if (num_led_on < 0 || num_led_on > max_h + max_m) { return {}; }

            std::vector<std::string> result;
            const auto max_minute_led_on = std::min(num_led_on, max_m);
            for (auto m = max_minute_led_on; m >= 0; --m) {
                if (num_led_on - m > max_h) { continue; }

                const auto initial_minutes = generate_minutes(m);
                const auto possible_minutes = possible_nums(initial_minutes);

                const auto initial_hours = generate_hours(num_led_on - m);
                const auto possible_hours = possible_nums(initial_hours);

                for (const auto& ph: possible_hours) {
                    for (const auto& pm : possible_minutes) {
                        if (ph < 0 || ph > 11 || pm < 0 || pm > 59) { continue; }

                        result.push_back(to_time(ph, pm));
                    }
                }
            }

            return result;
        }
    };

    const int BinaryWatch::max_h = 4;
    const int BinaryWatch::max_m = 6;
}

#endif //CPPNOTESMAIN_BINARY_WATCH_TIME_HPP
