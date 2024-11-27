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

        std::vector<std::vector<std::string>> result;
        std::unordered_map<std::string, std::vector<std::string>> mp;

        for (std::string current : strs) 
        {

            std::string copy = current;
            std::sort(copy.begin(), copy.end());

            mp[copy].push_back(current);

        }

        for (const auto& current : mp) 
        {

            result.push_back(current.second);
        }

        return result;

    }

};
