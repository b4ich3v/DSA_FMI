#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:

	int singleNonDuplicate(const std::vector<int>& nums)
	{

		int left = 0;
		int right = nums.size() - 1;

		while (left < right)
		{

			int middle = left + (right - left) / 2;

			if (middle % 2 == 1) middle--;

			if (nums[middle] == nums[middle + 1]) left = middle + 2;
			else right = middle;


		}

		return nums[left];

	}

};
