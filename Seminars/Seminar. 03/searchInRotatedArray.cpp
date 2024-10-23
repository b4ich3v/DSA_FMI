#include <iostream>
#include <vector>

class Solution
{
public:
    
    int findPivot(std::vector<int>& nums) 
    {

        int left = 0;
        int right = nums.size() - 1;

        while (left < right) 
        {

            int middle = left + (right - left) / 2;

            if (middle < right && nums[middle] > nums[middle + 1])  return middle;
            if (middle > left && nums[middle] < nums[middle - 1])  return middle - 1;
            if (nums[left] >= nums[middle])  right = middle - 1;
            else  left = middle + 1;
        }

        return -1; 

    }

    int binarySearch(std::vector<int>& nums, int left, int right, int target) 
    {

        while (left <= right) 
        {

            int mid = left + (right - left) / 2;

            if (nums[mid] == target) return mid;
            if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }

        return -1; 

    }

    int search(std::vector<int>& nums, int target) 
    {

        int n = nums.size();
        int pivot = findPivot(nums);

        if (pivot == -1) return binarySearch(nums, 0, n - 1, target);

        if (nums[pivot] == target) return pivot;

        if (nums[0] <= target) return binarySearch(nums, 0, pivot - 1, target);

        return binarySearch(nums, pivot + 1, n - 1, target);

    }

};


