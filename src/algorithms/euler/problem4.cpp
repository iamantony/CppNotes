#include "problem4.hpp"

#include <iostream>

// Source: http://leetcode.com/2012/01/palindrome-number.html

void Problem4::DoSolve()
{
    std::cout << "Problem 4" << std::endl;

    int biggestPalindrom = 0;
    int countDepth = 0;
    for ( int i = 999; i > countDepth; --i )
    {
        for ( int j = i; j > 0; --j )
        {
            int product = i * j;
            if ( product < biggestPalindrom )
            {
                break;
            }

            if ( true == IsPalindrom(product) )
            {
                biggestPalindrom = product;
                if ( countDepth < j )
                {
                    countDepth = j;
                }

                break;
            }
        }
    }

    std::cout << "Answer = " << biggestPalindrom << std::endl;
}

bool Problem4::IsPalindrom(const int &t_number)
{
    if ( t_number < 0 )
    {
        return (false);
    }

    // Lets find divider, that will leave from input number only the first
    // (from the left) digit. Ex: t_number = 12345, so divider = 10000
    int divider = 1;
    while ( 10 <= t_number / divider )
    {
        divider *= 10;
    }

    int number = t_number;
    while ( number != 0 )
    {
        // Compare left and right digits of the number
        int leftDigit = number / divider;
        int rightDigit = number % 10;
        if ( leftDigit != rightDigit )
        {
            return (false);
        }

        // Lets short our number: get rid of left and right digits
        number = (number % divider) / 10;

        // After that our number lost two orders, so we need to
        // do the same with the divider
        divider /= 100;
    }

    return (true);
}
