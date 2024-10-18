#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution 
{
public:

    std::vector<std::vector<int>> groupThePeople(std::vector<int>& groupSizes)
    {
        
        std::vector<std::vector<int>> result;
        std::vector<std::vector<int>> groups(500);  

        for (int i = 0; i < groupSizes.size(); i++)
        {

            int groupSize = groupSizes[i]; 
            groups[groupSize].push_back(i);

            if (groups[groupSize].size() == groupSize)
            {

                result.push_back(groups[groupSize]);  
                groups[groupSize].clear();  

            }

        }

        return result;

    }

};
