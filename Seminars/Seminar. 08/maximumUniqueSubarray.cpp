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

    int maximumUniqueSubarray(std::vector<int>& nums) 
    {

        std::unordered_set<int> s;
        int startIndex = 0;
        int currentSum = 0;
        int result = 0;

        for (int i = 0; i < nums.size(); i++)
        {

            while (s.find(nums[i]) != s.end()) 
            {

                s.erase(nums[startIndex]);
                currentSum -= nums[startIndex];
                startIndex += 1;

            }


            currentSum += nums[i];
            s.insert(nums[i]);
            result = std::max(result, currentSum);

        }

        return result;

    }

};
