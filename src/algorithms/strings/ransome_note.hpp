#ifndef RANSOME_NOTE_HPP_
#define RANSOME_NOTE_HPP_

// A ransom note can be formed by cutting words our of a magazine to form a
// new sentence. How would you figure out if a ransom note (represented as a
// string) can be formed from a given magazine (string).

#include <string>
#include <unordered_map>

bool isStrFormedFromStr(const std::string& str, const std::string& source)
{
    if (str.empty() || source.empty())
    {
        return false;
    }

    std::unordered_map<char, int> map;
    for (const char& ch : str)
    {
        if (map.end() == map.find(ch))
        {
            map[ch] = 0;
        }

        ++map[ch];
    }

    for (const char& ch : source)
    {
        std::unordered_map<char, int>::iterator it = map.find(ch);
        if (it == map.end())
        {
            continue;
        }

        --(it->second);
        if (it->second <= 0)
        {
            map.erase(it);
            if (map.empty())
            {
                return true;
            }
        }
    }

    return false;
}

#endif /* RANSOME_NOTE_HPP_ */
