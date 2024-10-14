#include <iostream>
#include <vector>
#include <algorithm>

class Solution 
{
public:

    void manipulateBits(std::vector<int>& special, int number) 
    {

        int index = 0;

        while (number) 
        {

            if (number & 1) special[index]++;
            number >>= 1;

        }

    }

    int singleNumber(std::vector<int>& nums) 
    {

        std::vector<int> special(32, 0);
        int size = nums.size();

        for (int i = 0; i < size; i++)
        {

            manipulateBits(special, nums[i]);

        }

        int result = 0;

        for (int i = 0, iter = 1; i < special.size(); i++, iter *= 2)
        {
            if (special[i] % 3 != 0) 
            {

                result += iter;

            }

        }

        return result;

    }

};
