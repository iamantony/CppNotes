#ifndef INT_OPERATORS_HPP_
#define INT_OPERATORS_HPP_

// Write methods to multiply, subtract, and divide operations for integers.
// Use only the add operator.

int Negate(const int& originalValue)
{
    int result = 0;
    int value = originalValue;
    int sign = originalValue < 0 ? 1 : -1;
    while(value != 0)
    {
        result += sign;
        value += sign;
    }

    return result;
}

int ABSInt(const int& value)
{
    if (0 <= value)
    {
        return value;
    }

    return Negate(value);
}

int Subtract(const int& value, const int& subtrahend)
{
    return value + Negate(subtrahend);
}

int Multiply(const int& value, const int& multiplier)
{
    int result = 0;
    for (int i = ABSInt(multiplier); i > 0; --i)
    {
        result += value;
    }

    if (multiplier < 0)
    {
        result = Negate(result);
    }

    return result;
}

int Divide(const int& value, const int& divisor)
{
    if (divisor == 0)
    {
        return 0;
    }

    int absValue = ABSInt(value);
    int absDivisor = ABSInt(divisor);

    int result = 0;
    int sum = 0;
    while(sum + absDivisor <= absValue)
    {
        sum += absDivisor;
        ++result;
    }

    if ((value < 0 && divisor < 0) || (0 < value && 0 < divisor))
    {
        return result;
    }

    return Negate(result);
}

#endif /* INT_OPERATORS_HPP_ */
