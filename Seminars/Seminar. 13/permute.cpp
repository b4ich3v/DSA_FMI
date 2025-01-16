#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

class Solution 
{
public:

    void actualPermutation(std::vector<int>& nums, std::vector<std::vector<int>>& result, int start)
    {

        if (start == nums.size()) 
        {

            result.push_back(nums);
            return;

        }
        for (size_t i = start; i < nums.size(); i++) 
        {

            std::swap(nums[i], nums[start]);
            actualPermutation(nums, result, start + 1);
            std::swap(nums[i], nums[start]);

        }

    }

    std::vector<std::vector<int>> permute(std::vector<int>& nums)
    {

        std::vector<std::vector<int>> result;
        actualPermutation(nums, result, 0);

        return result;

    }

};

