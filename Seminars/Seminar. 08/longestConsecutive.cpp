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

    int longestConsecutive(std::vector<int>& nums) 
    {

        if (nums.size() == 0) return 0;

        std::unordered_set<int> s;

        for (int i = 0; i < nums.size(); i++) s.insert(nums[i]);

        int result = 1;
        int counter = 1;

        for (int current : s) 
        {

            if (s.find(current - 1) == s.end()) 
            {

                int newCurrent = current + 1;
                counter = 1;

                while (s.find(newCurrent) != s.end()) 
                {

                    newCurrent = newCurrent + 1;
                    counter++;

                }


                result = std::max(result, counter);

            }

        }

        return result;

    }

};
