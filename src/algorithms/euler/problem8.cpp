#include "problem8.hpp"

#include <iostream>

void Problem8::DoSolve()
{
    std::cout << "Problem 8" << std::endl;

    std::string numbersStr;
    numbersStr.append("73167176531330624919225119674426574742355349194934");
    numbersStr.append("96983520312774506326239578318016984801869478851843");
    numbersStr.append("85861560789112949495459501737958331952853208805511");
    numbersStr.append("12540698747158523863050715693290963295227443043557");
    numbersStr.append("66896648950445244523161731856403098711121722383113");
    numbersStr.append("62229893423380308135336276614282806444486645238749");
    numbersStr.append("30358907296290491560440772390713810515859307960866");
    numbersStr.append("70172427121883998797908792274921901699720888093776");
    numbersStr.append("65727333001053367881220235421809751254540594752243");
    numbersStr.append("52584907711670556013604839586446706324415722155397");
    numbersStr.append("53697817977846174064955149290862569321978468622482");
    numbersStr.append("83972241375657056057490261407972968652414535100474");
    numbersStr.append("82166370484403199890008895243450658541227588666881");
    numbersStr.append("16427171479924442928230863465674813919123162824586");
    numbersStr.append("17866458359124566529476545682848912883142607690042");
    numbersStr.append("24219022671055626321111109370544217506941658960408");
    numbersStr.append("07198403850962455444362981230987879927244284909188");
    numbersStr.append("84580156166097919133875499200524063689912560717606");
    numbersStr.append("05886116467109405077541002256983155200055935729725");
    numbersStr.append("71636269561882670428252483600823257530420752963450");


    std::vector<long long int> nums = ConvertToNumbers(numbersStr);
    if ( 0 == nums.size() )
    {
        std::cout << "Error - conversion to numbers failed" << std::endl;
        return;
    }

    long long int largestProduct = 0;
    for (size_t i = 0; i < nums.size() - 13; ++i)
    {
        long long int prod = 1;
        for(size_t j = i; j < i + 13; ++j)
        {
            prod *= nums[j];
        }

        if (largestProduct < prod)
        {
            largestProduct = prod;
        }
    }

    std::cout << "Answer = " << largestProduct << std::endl;
}

std::vector<long long int> Problem8::ConvertToNumbers(const std::string &t_str)
{
    if ( 0 == t_str.size() )
    {
        std::cout << "Error - string is empty" << std::endl;
        return (std::vector<long long int>());
    }

    std::vector<long long int> nums;
    for ( size_t i = 0; i < t_str.size(); ++i )
    {
        if ( (t_str[i] < '0') || ('9' < t_str[i]) )
        {
            continue;
        }

        nums.push_back(t_str[i] - '0');
    }

    return (nums);
}
