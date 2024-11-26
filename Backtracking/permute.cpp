#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:


    void generateAllPerms(std::vector<int>& arr, std::vector<std::vector<int>>& result, int start, int end)
    {

        if (start == end) result.push_back(arr);
        else
        {

            for (int i = start; i < end; i++)
            {

                std::swap(arr[start], arr[i]);
                generateAllPerms(arr, result, start + 1, end);
                std::swap(arr[start], arr[i]);

            }

        }

    }

    std::vector<std::vector<int>> permute(std::vector<int>& nums) 
    {

        std::vector< std::vector<int>> result;
        generateAllPerms(nums, result, 0, nums.size());

        return result;

    }

};
