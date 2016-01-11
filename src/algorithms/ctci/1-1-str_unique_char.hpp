#ifndef STR_UNIQUE_CHAR_HPP_
#define STR_UNIQUE_CHAR_HPP_

#include <iostream>
#include <string>
#include <set>

// Implement an algorithm to determine if a string has all unique characters.
// What if you cannot use additional data structures?

bool IsStrHasAllUniqueChars(const std::string& inputStr)
{
    if (inputStr.empty())
    {
        return (false);
    }

    std::set<char> characters;
    for (int i = 0; i < inputStr.size(); ++i)
    {
        if (0 == characters.count(inputStr.at(i)))
        {
            characters.insert(inputStr.at(i));
        }
        else
        {
            return (false);
        }
    }

    return (true);
}

#endif /* STR_UNIQUE_CHAR_HPP_ */
