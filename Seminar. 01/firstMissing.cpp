#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:

    int firstMissingPositive(std::vector<int>& nums)
    {

        int size = nums.size();
        std::vector<bool> container(size + 1, false);

        for (int i = 0; i < size; i++)
        {

            if (nums[i] > 0 && nums[i] <= size) container[nums[i]] = true;

        }

        for (int i = 1; i <= size; i++)
        {

            if (!container[i])  return i;
         
        }

        return size + 1; 

    }

};
