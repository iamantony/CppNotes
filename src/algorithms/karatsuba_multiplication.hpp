#ifndef KARATSUBA_MULTIPLICATION_HPP_
#define KARATSUBA_MULTIPLICATION_HPP_

// Karatsuba algorithm of multiplication of two numbers.
// @input: two numbers
// @output: multiplication result

// X - is the first number
// Y - is the second number
// Represent the numbers as:
// X = 10^(n/2) * a + b
// Y = 10^(n/2) * c + d
// where n - is the length of the numbers (number of digits)
// and a, b, c, d are the half of the numbers
// Example: X = 1234 and Y = 5678
// n = 4
// X = 10^(4/2) * 12 + 34
// Y = 10^(4/2) * 56 + 78

// Then: x * y = (10^(n/2) * a + b) * (10^(n/2) * c + d) =
// 10^n * a * c + 10^(n/2) * (a * b + b * c) + b * d  (1)

// Idea: recursively compute ac, ad, bc, db, then compute (1) in the
// straightforward way.

long long int KaratsubaMultiplication(const long long int& firstNum,
        const long long int& secondNum)
{
    return 0;
}



#endif /* KARATSUBA_MULTIPLICATION_HPP_ */
