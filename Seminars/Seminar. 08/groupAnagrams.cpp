#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

class Solution 
{
public:

    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs)
    {

        std::unordered_set<std::string> wordCounter;
        std::unordered_map<std::string, int> hashed;
        int index = 0;

        for (const auto& current : strs) 
        {

            std::string copy = current;
            std::sort(copy.begin(), copy.end());

            wordCounter.insert(copy);

        }

        for (const auto& current : wordCounter) 
        {

            hashed[current] = index;
            index += 1;

        }

        std::vector<std::vector<std::string>> result(wordCounter.size());

        for (const auto& current : strs) 
        {

            std::string copy = current;
            std::sort(copy.begin(), copy.end());

            result[hashed[copy]].push_back(current);

        }

        return result;

    }

};
