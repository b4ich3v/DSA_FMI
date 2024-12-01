#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <algorithm>

class Solution 
{
public:

    int maximumUniqueSubarray(std::vector<int>& nums) 
    {

        std::unordered_set<int> mp;
        int startIndex = 0;
        int currentSum = 0;
        int result = 0;

        for (int i = 0; i < nums.size(); i++)
        {

            while (mp.count(nums[i])) 
            {

                mp.erase(nums[startIndex]);
                currentSum -= nums[startIndex];
                startIndex++;

            }

            mp.insert(nums[i]);
            currentSum += nums[i];
            result = std::max(result, currentSum);

        }

        return result;

    }

};
