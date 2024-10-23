#include <vector>
#include <algorithm>

class Solution 
{
public:

    int findMin(std::vector<int>& nums) 
    {

        int left = 0;
        int right = nums.size() - 1;

        while (left < right) 
        { 

            int middle = left + (right - left) / 2;

            
            if (nums[middle] > nums[right]) left = middle + 1;
            else if (nums[middle] < nums[right])  right = middle;
            else  right--;

        }

        return nums[left];

    }

};
