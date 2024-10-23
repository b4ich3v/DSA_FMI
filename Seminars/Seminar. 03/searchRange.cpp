#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:

	int search(std::vector<int>& nums, int target)
	{

		int left = 0;
		int right = nums.size() - 1;

		while (left <= right)
		{

			int middle = left + (right - left) / 2;

			if (nums[middle] > target) right = middle - 1;
			else if (nums[middle] < target) left = middle + 1;
			else return middle;

		}

		return -1;

	}

    std::vector<int> searchRange(std::vector<int>& nums, int target)
    {

		std::vector<int> result(2, -1);

		auto lower = std::lower_bound(nums.begin(), nums.end(), target);
		auto upper = std::upper_bound(nums.begin(), nums.end(), target);

		if (lower != nums.end() && *lower == target)
		{

			result[0] = lower - nums.begin(); 
			result[1] = upper - nums.begin() - 1; 

		}

		return result;

    }

};

