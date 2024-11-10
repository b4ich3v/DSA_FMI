#include <vector>
#include <deque>
#include <iostream>

class Solution
{
public:

    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k)
    {

        std::deque<int> d;
        std::vector<int> result;

        for (int i = 0; i < nums.size(); ++i)
        {

            if (!d.empty() && d.front() == i - k)  d.pop_front();

            while (!d.empty() && nums[d.back()] < nums[i])  d.pop_back();

            d.push_back(i);

            if (i >= k - 1) result.push_back(nums[d.front()]);

        }

        return result;

    }

};
