#ifndef BASIC_NUMBERS_MULTIPLICATION_HPP_
#define BASIC_NUMBERS_MULTIPLICATION_HPP_

#include <string>

// Standard algorithm of multiplication of two numbers.
// @input: two numbers, represented as strings
// @output: multiplication result
long long int BasicNumbersMultiplication(const std::string& firstNum,
        const std::string& secondNum)
{
    if (firstNum.empty() || secondNum.empty())
    {
        return 0;
    }

    long long int result = 0;
    int i = static_cast<int>(secondNum.size() - 1);
    long long int positionFactorSecond = 1;
    for (; i >= 0; --i, positionFactorSecond *= 10)
    {
        std::string factorStr(1, secondNum.at(static_cast<size_t>(i)));
        int factor = std::stoi(factorStr);
        if (0 == factor)
        {
            continue;
        }

        long long int intermediate_result = 0;
        int j = static_cast<int>(firstNum.size() - 1);
        long long int positionFactorFirst = 1;
        for (; j >= 0; --j, positionFactorFirst *= 10)
        {
            std::string multiplicantStr(1, firstNum.at(static_cast<size_t>(j)));
            int multiplicant = std::stoi(multiplicantStr);
            if (0 == multiplicant)
            {
                continue;
            }

            intermediate_result += (multiplicant * factor) *
                    positionFactorFirst * positionFactorSecond;
        }

        result += intermediate_result;
    }

    return result;
}

#endif /* BASIC_NUMBERS_MULTIPLICATION_HPP_ */
