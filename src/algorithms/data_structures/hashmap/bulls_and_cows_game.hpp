#ifndef BULLS_AND_COWS_GAME_HPP
#define BULLS_AND_COWS_GAME_HPP

/*
https://leetcode.com/problems/bulls-and-cows/
You are playing the following Bulls and Cows game with your friend: You write down a number and
ask your friend to guess what the number is. Each time your friend makes a guess, you provide a
hint that indicates how many digits in said guess match your secret number exactly in both digit
and position (called "bulls") and how many digits match the secret number but locate in the wrong
position (called "cows"). Your friend will use successive guesses and hints to eventually derive
the secret number.

Write a function to return a hint according to the secret number and friend's guess, use A to
indicate the bulls and B to indicate the cows.

Please note that both secret number and friend's guess may contain duplicate digits.

Example 1:
Input: secret = "1807", guess = "7810"
Output: "1A3B"
Explanation: 1 bull and 3 cows. The bull is 8, the cows are 0, 1 and 7.

Example 2:
Input: secret = "1123", guess = "0111"
Output: "1A1B"
Explanation: The 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow.

Note: You may assume that the secret number and your friend's guess only contain digits, and their
lengths are always equal.
*/

#include <string>
#include <unordered_map>
#include <algorithm>

namespace Algo::DS::HashMap {
    class BullsAndCows {
    public:
        static std::string play(const std::string& secret, const std::string& guess) {
            std::unordered_map<char, size_t> chars_map;
            std::for_each(
                secret.begin(), secret.end(), [&chars_map](const auto& c){ ++chars_map[c]; });

            size_t bulls_num = 0;
            for (size_t i = 0; i < guess.size() && i < secret.size(); ++i) {
                if (guess[i] != secret[i]) { continue; }

                ++bulls_num;

                auto iter = chars_map.find(guess[i]);
                --iter->second;
                if (iter->second == 0) { chars_map.erase(iter); }
            }

            size_t cows_num = 0;
            for (size_t i = 0; i < guess.size(); ++i) {
                auto iter = chars_map.find(guess[i]);
                if (iter == chars_map.end()) { continue; }
                if (i < secret.size() && guess[i] == secret[i]) { continue; }

                ++cows_num;

                --iter->second;
                if (iter->second == 0) { chars_map.erase(iter); }
            }

            return std::to_string(bulls_num) + 'A' + std::to_string(cows_num) + 'B';
        }
    };
}

#endif //BULLS_AND_COWS_GAME_HPP
