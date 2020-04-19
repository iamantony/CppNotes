#ifndef HAPPY_NUMBER_HPP
#define HAPPY_NUMBER_HPP

/*

*/

#include <unordered_set>

namespace Algo::HashMap {
    class HappyNumber {
    public:
        static bool check(int n) {
            if (n < 1) { return false; }
            if (n == 1) { return true; }

            uint64_t number = static_cast<uint64_t>(n);
            std::unordered_set<uint64_t> known_values;
            while (true) {
                uint64_t sum = 0;
                while (number > 0) {
                    const auto modulo = number % 10;
                    sum += modulo * modulo;
                    number /= 10;
                }

                if (sum == 1) { return true; }
                if (known_values.count(sum) > 0) { return false; }

                known_values.insert(sum);
                number = sum;
            }
        }
    };
}

#endif //HAPPY_NUMBER_HPP
