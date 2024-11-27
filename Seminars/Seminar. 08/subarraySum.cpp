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

    int subarraySum(std::vector<int>& nums, int k) 
    {

        std::unordered_map<int, int> mp;
        int prefSum = 0;
        int result = 0;
        mp[0] = 1;

        for (int i = 0; i < nums.size(); i++)
        {

            prefSum += nums[i];

            if (mp.find(prefSum - k) != mp.end()) result += mp[prefSum - k];

            mp[prefSum]++;

        }

        return result;

    }

};
