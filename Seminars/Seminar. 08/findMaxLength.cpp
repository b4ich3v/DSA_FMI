#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

class Solution
{
public:

    int findMaxLength(std::vector<int>& nums)
    {

        for (int i = 0; i < nums.size(); i++) if (!nums[i]) nums[i] = -1;

        std::unordered_map<int, int> mp;
        mp[0] = -1;
        int prefSum = 0;
        int result = 0;

        for (int i = 0; i < nums.size(); i++)
        {

            prefSum += nums[i];

            if (mp.find(prefSum) != mp.end()) result = std::max(result, i - mp[prefSum]);
            else mp[prefSum] = i;

        }

        return result;

    }

};
