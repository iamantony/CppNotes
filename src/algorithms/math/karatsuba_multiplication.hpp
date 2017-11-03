#ifndef KARATSUBA_MULTIPLICATION_HPP_
#define KARATSUBA_MULTIPLICATION_HPP_

#include <utility>

namespace Karatsuba
{
    long long int GetNumOfDigits(const long long int& number);
    std::pair<long long int, long long int> SplitNumber(const long long int& number,
            const long long int& size);
}

// Karatsuba algorithm of multiplication of two numbers.
// https://en.wikipedia.org/wiki/Karatsuba_algorithm
// @input: two numbers
// @output: multiplication result
// https://en.wikipedia.org/wiki/Karatsuba_algorithm
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
    if (firstNum < 10 || secondNum < 10)
    {
        return firstNum * secondNum;
    }

    long long int firstDigitsNum = Karatsuba::GetNumOfDigits(firstNum);
    long long int secondDigitsNum = Karatsuba::GetNumOfDigits(secondNum);
    long long int digitsInSplitNums =
            std::max(firstDigitsNum, secondDigitsNum) / 2;

    std::pair<long long int, long long int> a_b =
            Karatsuba::SplitNumber(firstNum, digitsInSplitNums);

    std::pair<long long int, long long int> c_d =
            Karatsuba::SplitNumber(secondNum, digitsInSplitNums);

    long long int bd = KaratsubaMultiplication(a_b.second, c_d.second);
    long long int apbmcpd = KaratsubaMultiplication(
            (a_b.first + a_b.second), (c_d.first + c_d.second));

    long long int ac = KaratsubaMultiplication(a_b.first, c_d.first);

    long long int firstPart =
        ac * static_cast<long long int>(std::pow(10, 2 * digitsInSplitNums));

    long long int middlePart = (apbmcpd - ac - bd) *
            static_cast<long long int>(std::pow(10, digitsInSplitNums));

    long long int result = firstPart + middlePart + bd;

    return result;
}

// Get number of digits in number
// @input: number
// @output: number of digits
long long int Karatsuba::GetNumOfDigits(const long long int& number)
{
    long long int digitsNum = 0;
    long long int value = std::abs(number);
    while(0 < value)
    {
        ++digitsNum;
        value /= 10;
    }

    return digitsNum;
}

// Split number in two parts so at least one of the parts contains number of
// digits equal to size argument
// @input: number and number of digits in parts
// @output: two parts of the number
std::pair<long long int, long long int> Karatsuba::SplitNumber(const long long int& number,
        const long long int& size)
{
    if (size < 1)
    {
        return std::pair<long long int, long long int>(1, number);
    }

    long long int divider = static_cast<long long int>(std::pow(10, size));

    long long int leftPart = number / divider;
    long long int rightPart = number % divider;
    return std::pair<long long int, long long int>(leftPart, rightPart);
}

#endif /* KARATSUBA_MULTIPLICATION_HPP_ */
