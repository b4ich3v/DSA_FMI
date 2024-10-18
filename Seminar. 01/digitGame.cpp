#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution 
{
public:

    bool canAliceWin(std::vector<int>& nums) 
    {

        int sumOfTwoDigits = 0;
        int sumOfOneDigit = 0;

        for (int i = 0; i < nums.size(); i++)
        {

            if (nums[i] < 10) sumOfOneDigit += nums[i];
            else sumOfTwoDigits += nums[i];

        }

        return sumOfOneDigit != sumOfTwoDigits;

    }

};


