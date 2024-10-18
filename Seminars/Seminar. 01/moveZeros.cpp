#include <iostream>
#include <vector>

class Solution 
{
public:

    void moveZeroes(std::vector<int>& nums) 
    {

        for (int iter = 0, nextNumberIndex = 0; iter < nums.size(); iter++) 
        {

            if (nums[iter] != 0) 
            {
                std::swap(nums[nextNumberIndex], nums[iter]);
                nextNumberIndex++;

            }

        }

    }

};
