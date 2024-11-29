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

    int findPairs(std::vector<int>& nums, int k) 
    {

        std::unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) mp[nums[i]]++;

        int result = 0;

        for (const auto& current : mp)
        {

            int number = current.first;
            int count = current.second;

            if (k == 0) 
            {

                if (count > 1) result++;

            }
            else
            {

                if (mp.find(number + k) != mp.end()) result++;

            }

        }

        return result;

    }

};
