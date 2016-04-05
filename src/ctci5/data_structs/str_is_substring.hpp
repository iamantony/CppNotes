#ifndef STR_IS_SUBSTRING_HPP_
#define STR_IS_SUBSTRING_HPP_

#include <string>

// Assume you have a method isSubstring which checks if one word is a
// substring of another. Given two strings, s1 and s2, write code to check
// if s2 is a rotation of s1 using only one call to isSubstring (e.g.,
// "waterbottLe" is a rotation of "erbottLewat").

bool isSubString(const std::string& source, const std::string& str)
{
    if (source.empty() || str.empty() || source.size() < str.size())
    {
        return false;
    }
    else if (source.size() == str.size())
    {
        return source == str;
    }

    size_t strPos = 0;
    for(size_t i = 0; i < source.size(); ++i)
    {
        if (source[i] == str[strPos])
        {
            ++strPos;
            if (strPos == str.size())
            {
                return true;
            }
        }
        else
        {
            strPos = 0;
        }
    }

    return false;
}

bool isStrRotationOfOtherStr(const std::string& original,
        const std::string& str)
{
    if (original.empty() || original.size() != str.size())
    {
        return false;
    }

    std::string sourceStr = original + original;
    return isSubString(sourceStr, str);
}

#endif /* STR_IS_SUBSTRING_HPP_ */
