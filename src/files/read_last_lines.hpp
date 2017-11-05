#ifndef READ_LAST_LINES_HPP_
#define READ_LAST_LINES_HPP_

// Write a method to print the last K lines of an input file using C++.

#include <iostream>
#include <fstream>
#include <string>
#include <queue>

std::queue<std::string> ReadLastLines(const std::string& file_name,
        const size_t& num_of_lines)
{
    if (file_name.empty() || num_of_lines == 0)
    {
        std::cout << "Invalid arguments" << std::endl;
        return std::queue<std::string>();
    }

    std::ifstream fileStream(file_name, std::ifstream::in);
    if (false == fileStream.is_open())
    {
        std::cout << "Failed to open file" << std::endl;
        return std::queue<std::string>();
    }

    std::queue<std::string> lines;
    std::string line;
    while(std::getline(fileStream, line))
    {
        if (num_of_lines <= lines.size())
        {
            lines.pop();
        }

        lines.push(line);
    }

    if (fileStream.bad())
    {
        std::cout << "Something went wrong" << std::endl;
        return std::queue<std::string>();
    }

    return lines;
}

#endif /* READ_LAST_LINES_HPP_ */
