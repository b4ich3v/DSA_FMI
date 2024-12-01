#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

class Solution 
{
public:

    std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
    {
        
        if (nums.size() < 3) return {};

        std::sort(nums.begin(), nums.end());
        std::unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) mp[nums[i]] = i;

        std::vector<std::vector<int>> triplets;

        for (int i = 0; i < nums.size(); i++) 
        {

            int target = -nums[i];

            for (int j = i + 1; j < nums.size(); j++) 
            {

                if (mp.count(target - nums[j]) && mp[target - nums[j]] > j)
                {

                    triplets.push_back({ nums[i], nums[j], target - nums[j] });

                }

                j = mp[nums[j]];

            }

            i = mp[nums[i]];

        }

        return triplets;

    }

};
