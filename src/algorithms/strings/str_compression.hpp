#ifndef STR_COMPRESSION_HPP_
#define STR_COMPRESSION_HPP_

// Implement a method to perform basic string compression using the counts of
// repeated characters. For example, the string aabcccccaaa would become
// a2blc5a3. If the "compressed" string would not become smaller than the
// original string, your method should return the original string.

#include <string>

size_t CalcCompressedStrSize(const std::string& str);

std::string CompressString(const std::string& str)
{
    size_t compStrSize = CalcCompressedStrSize(str);
    if (str.size() <= compStrSize)
    {
        return str;
    }

    std::string compressedStr(compStrSize, ' ');
    size_t position = 0, counter = 1;
    for (size_t i = 1; i < str.size(); ++i)
    {
        if (str[i] == str[i - 1])
        {
            ++counter;
        }
        else
        {
            compressedStr[position++] = str[i - 1];
            std::string number = std::to_string(counter);
            compressedStr.replace(position, number.size(), number);
            position += number.size();
            counter = 1;
        }
    }

    compressedStr[position++] = str[str.size() - 1];
    std::string number = std::to_string(counter);
    compressedStr.replace(position, number.size(), number);

    return compressedStr;
}

size_t CalcCompressedStrSize(const std::string& str)
{
    if (str.empty())
    {
        return 0;
    }

    size_t compStrSize = 0;
    size_t counter = 1;
    for (size_t i = 1; i < str.size(); ++i)
    {
        if (str[i] == str[i - 1])
        {
            ++counter;
        }
        else
        {
            compStrSize += 1 + std::to_string(counter).size();
            counter = 1;
        }
    }

    compStrSize += 1 + std::to_string(counter).size();
    return compStrSize;
}

#endif /* STR_COMPRESSION_HPP_ */
