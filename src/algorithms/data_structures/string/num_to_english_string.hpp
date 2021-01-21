#ifndef CPPNOTESMAIN_NUM_TO_ENGLISH_STRING_HPP
#define CPPNOTESMAIN_NUM_TO_ENGLISH_STRING_HPP

/*

*/

#include <string>
#include <vector>
#include <algorithm>

namespace Algo::DS::String {
    class ConvertNumToEnglishStr {
        enum Section {
            first = 0,
            thousand,
            million,
            billion
        };

        const std::vector<std::string> first_ten =
            {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

        const std::vector<std::string> teens =
            {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
             "Seventeen", "Eighteen", "Nineteen"};

        const std::vector<std::string> second_ten = {"", "", "Twenty", "Thirty", "Forty", "Fifty",
                                                     "Sixty", "Seventy", "Eighty", "Ninety"};

        const std::vector<std::string> section_names = {"", "Thousand", "Million", "Billion"};

        std::string thousand_to_string(int num, const Section section) {
            if (num == 0) { return {}; }

            std::vector<std::string> parts;
            if (num >= 100) {
                parts.push_back(first_ten[static_cast<size_t>(num / 100)]);
                parts.push_back("Hundred");
                num %= 100;
            }

            if (num >= 20) {
                parts.push_back(second_ten[static_cast<size_t>(num / 10)]);
                num %= 10;
            }

            if (num >= 10 && num <= 19) {
                parts.push_back(teens[static_cast<size_t>(num - 10)]);
                num = 0;
            }

            if (num > 0 && num <= 9) {
                parts.push_back(first_ten[static_cast<size_t>(num)]);
                num = 0;
            }

            if (section > first) {
                parts.push_back(section_names[static_cast<size_t>(section)]);
            }

            auto result =  std::accumulate(
                std::next(parts.begin()),
                parts.end(),
                parts.front(),
                [](const auto& left, const auto& right) { return left + " " + right; });


            return result;
        }

    public:
        std::string convert(int num) {
            if (num == 0) { return "Zero"; }

            std::string result;
            Section section = Section::first;
            while (num > 0) {
                auto thousand = num % 1000;
                auto thousand_str = thousand_to_string(thousand, section);
                if (!thousand_str.empty()) {
                    result = thousand_str + (result.empty() ? "" : " " + result);
                }

                num /= 1000;
                section = static_cast<Section>(static_cast<int>(section) + 1);
            }

            return result;
        }
    };
}

#endif //CPPNOTESMAIN_NUM_TO_ENGLISH_STRING_HPP
