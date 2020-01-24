#ifndef STR_DECODING_HPP
#define STR_DECODING_HPP

/*
https://leetcode.com/problems/decode-string/
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is
being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets
are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits
are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:
s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
*/

#include <string>
#include <stack>
#include <exception>

namespace Algo::String {
    class StrDecoding {
        static bool isNumber(const std::string& s, const size_t& pos) {
            return pos < s.size() && s[pos] >= '0' && s[pos] <= '9';
        }

        static bool isOpenBracket(const std::string& s, const size_t& pos) {
            return pos < s.size() && s[pos] == '[';
        }

        static bool isCloseBracket(const std::string& s, const size_t& pos) {
            return pos < s.size() && s[pos] == ']';
        }

        static std::string getNumber(const std::string& s, size_t& pos) {
            std::string number;
            while (pos < s.size() && isNumber(s, pos)) {
                number.push_back(s[pos]);
                ++pos;
            }

            return number;
        }

        static std::string getString(const std::string& s, size_t& pos) {
            std::string str;
            while (pos < s.size() &&
                   !isNumber(s, pos) &&
                   !isOpenBracket(s, pos) &&
                   !isCloseBracket(s, pos))
            {
                str.push_back(s[pos]);
                ++pos;
            }

            return str;
        }

        static void decoding(std::stack<std::string>& parts) {
            if (parts.size() < 2) {
                throw std::logic_error("Can't decode parts - too few");
            }

            auto strPart = parts.top();
            parts.pop();
            if (isNumber(strPart, 0)) {
                throw std::logic_error("Unexpected number part");
            }

            const auto numPart = parts.top();
            parts.pop();
            if (!isNumber(numPart, 0)) {
                throw std::logic_error("Unexpected non-number part");
            }

            std::string result;
            const auto num = std::stoi(numPart);
            if (num < 0) {
                throw std::logic_error("Number part transformed to negative number");
            }

            for (int i = 0; i < num; ++i) {
                result.append(strPart);
            }

            if (parts.empty()) {
                parts.push(result);
            }
            else {
                if (isNumber(parts.top(), 0)) {
                    parts.push(result);
                }
                else {
                    parts.top().append(result);
                }
            }
        }

    public:
        static std::string decode(const std::string& s) {
            std::stack<std::string> codeParts;
            size_t pos = 0;
            auto prevIsNum = false;
            while (pos < s.size()) {
                if (isNumber(s, pos)) {
                    const auto number = getNumber(s, pos);
                    if (!isOpenBracket(s, pos)) {
                        throw std::logic_error("No open bracket after number");
                    }

                    ++pos;
                    prevIsNum = true;
                    codeParts.push(number);
                }
                else if (isCloseBracket(s, pos)) {
                    ++pos;
                    decoding(codeParts);
                }
                else {
                    const auto str = getString(s, pos);
                    if (codeParts.empty() || prevIsNum) {
                        codeParts.push(str);
                    }
                    else {
                        codeParts.top().append(str);
                    }

                    prevIsNum = false;
                }
            }

            return codeParts.empty() ? std::string() : codeParts.top();
        }
    };
}

#endif //STR_DECODING_HPP
