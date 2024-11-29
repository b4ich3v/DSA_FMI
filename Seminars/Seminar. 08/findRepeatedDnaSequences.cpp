#include <string>
#include <vector>
#include <unordered_map>

class Solution 
{
public:

    std::vector<std::string> findRepeatedDnaSequences(std::string str)
    {

        std::unordered_map<std::string, int> mp;
        std::vector<std::string> result;


        if (str.size() < 10) return result;

        for (int i = 0; i <= str.size() - 10; i++) 
        {

            std::string current = str.substr(i, 10);
            mp[current]++;

        }


        for (const auto& current : mp) 
        {

            if (current.second > 1) result.push_back(current.first);

        }

        return result;

    }

};
