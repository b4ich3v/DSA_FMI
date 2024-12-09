#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

class Solution
{
public:

    int findKthLargest(std::vector<int>& nums, int k)
    {

        std::make_heap(nums.begin(), nums.end());

        for (int i = 1; i < k; i++)
        {

            std::pop_heap(nums.begin(), nums.end());
            nums.pop_back();

        }

        return nums.front();

    }

};
