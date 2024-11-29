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

    long long countBadPairs(std::vector<int>& nums) 
    {

        std::unordered_map<long long, long long> mp;
        long long size = nums.size();
        long long result = size * (size - 1) / 2;

        for (long long i = 0; i < size; i++) mp[nums[i] - i]++;
        for (const auto& current : mp) result -= current.second * (current.second - 1) / 2;

        return result;

    }

};
