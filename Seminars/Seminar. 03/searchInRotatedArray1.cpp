#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <stack>
#include <string>

class Solution
{
public:

    int search(std::vector<int>& nums, int target) 
    {

        int index = 0;
        int nextIndex = 1;
        int pivotIndex = 0;

        while (nextIndex < nums.size())
        {

            if (nums[index] > nums[nextIndex]) 
            {

                pivotIndex = nextIndex;
                break;

            }

            index++;
            nextIndex++; 

        }

        auto left1 = std::lower_bound(nums.begin() + pivotIndex, nums.end(), target);
        auto left2 = std::lower_bound(nums.begin(), nums.begin() + pivotIndex, target);

        if (left1 != nums.end() && *left1 == target) 
        {

            return (int)(left1 - nums.begin());

        }

        if (left2 != nums.begin() + pivotIndex && *left2 == target) 
        {

            return (int)(left2 - nums.begin());

        }

        return -1;

    }

};








