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

    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {

        std::unordered_map<int, int> mp;
        std::vector<int> result(2, -1);

        for (int i = 0; i < nums.size(); i++)
        {

            if (mp.find(target - nums[i]) != mp.end())
            {

                result[0] = mp[target - nums[i]];
                result[1] = i;
                return result;

            }

            mp[nums[i]] = i;

        }

        return result;

    }

};
