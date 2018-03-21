#ifndef GREATEST_COMMON_DIVISOR_HPP
#define GREATEST_COMMON_DIVISOR_HPP

// Calculate Greatest Common Divisor (GCD) for two numbers a and b.
// GCD is a number that could divide both a and b.
// Example:
// a = 15, b = 9 -> d = 3

// Lemma:
// a' = a / b
// gcd(a, b) == gcd(a', b) == gcd(b, a')

// a = a' + b*q, where q is some number
// d is a GCD if and only if it divides a' and b

namespace GCD {

class Solution {
public:
    int calcGCD(const int& a, const int& b) {
        if (b == 0) {
            return a;
        }

        int reminder = a % b;
        return calcGCD(b, reminder);
    }
};

}

#endif // GREATEST_COMMON_DIVISOR_HPP

