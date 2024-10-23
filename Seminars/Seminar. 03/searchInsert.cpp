#include <iostream>
#include <vector>
#include <algorithm>

class Solution 
{
public:

    int searchInsert(std::vector<int>& nums, int target) 
    {

        int left = 0;
        int right = nums.size() - 1;
        int result = -1;

        while (left <= right)
        {

            int middle = left + (right - left) / 2;

            if (nums[middle] > target) right = middle - 1;
            else if (nums[middle] < target) left = middle + 1;
            else return middle;

        }

        return left;

    }

};


