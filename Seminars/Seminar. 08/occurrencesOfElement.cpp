#include <vector>
#include <unordered_map>

class Solution
{
public:

    std::vector<int> occurrencesOfElement(std::vector<int>& nums, std::vector<int>& queries, int x)
    {
        
        std::unordered_map<int, std::vector<int>> mp;
        std::vector<int> result(queries.size(), -1); 

        for (int i = 0; i < nums.size(); i++) 
        {

            mp[nums[i]].push_back(i);

        }

        for (int i = 0; i < queries.size(); i++) 
        {

            int occurrence = queries[i]; 

            if (occurrence <= mp[x].size())
            { 

                result[i] = mp[x][occurrence - 1]; 

            }

        }

        return result;

    }

};
