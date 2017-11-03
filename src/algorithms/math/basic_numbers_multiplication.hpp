#ifndef BASIC_NUMBERS_MULTIPLICATION_HPP_
#define BASIC_NUMBERS_MULTIPLICATION_HPP_

long long int GetNumOfDigits(const long long int& number);
long long int GetDigitAtPosition(const long long int& number,
        const long long int& position);

// Standard algorithm of multiplication of two numbers.
// @input: two numbers
// @output: multiplication result
long long int BasicNumbersMultiplication(const long long int& firstNum,
        const long long int& secondNum)
{
    if (0 == firstNum || 0 == secondNum)
    {
        return 0;
    }

    // Result will be negative number
    long long int sign = -1;
    if ( (firstNum > 0 && secondNum > 0) || (firstNum < 0 && secondNum < 0) )
    {
        // Result will be positive number
        sign = 1;
    }

    // Get positive values of our numbers. We will use them in further
    // computations
    const long long int first = std::abs(firstNum);
    const long long int second = std::abs(secondNum);

    long long int result = 0;

    // Multiply each digit of second number with each digit of the first number
    const long long int secondNumDigits = GetNumOfDigits(second);
    for (long long int i = 1, positionFactorSecond = 1; i <= secondNumDigits;
            ++i, positionFactorSecond *= 10)
    {
        long long int factor = GetDigitAtPosition(second, i);
        if (0 == factor)
        {
            continue;
        }

        long long int intermediate_result = 0;
        const long long int firstNumDigits = GetNumOfDigits(first);
        for (long long int j = 1, positionFactorFirst = 1; j <= firstNumDigits;
                ++j, positionFactorFirst *= 10)
        {
            long long int multiplicant = GetDigitAtPosition(first, j);
            if (0 == multiplicant)
            {
                continue;
            }

            intermediate_result += (multiplicant * factor) *
                    positionFactorFirst * positionFactorSecond;
        }

        result += intermediate_result;
    }

    return result * sign;
}

// Get number of digits in number
// @input: number
// @output: number of digits
long long int GetNumOfDigits(const long long int& number)
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

// Get digit of the number at specified position
// Number:           8 6 3 7
// Digits positions: 4 3 2 1
long long int GetDigitAtPosition(const long long int& number,
        const long long int& position)
{
    if (position <= 0)
    {
        return 0;
    }

    long long int value = number;
    for (long long int i = 1; i < position; ++i)
    {
        value /= 10;
    }

    return value % 10;
}

#endif /* BASIC_NUMBERS_MULTIPLICATION_HPP_ */
