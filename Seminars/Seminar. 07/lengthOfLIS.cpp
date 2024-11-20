#include <vector>
#include <algorithm> 

class Solution 
{
public:

    int lengthOfLIS(std::vector<int>& nums)
    {

        std::vector<int> dp(nums.size(), 1);
        int result = 1;

        for (int i = 1; i < nums.size(); i++)
        {

            for (int j = 0; j < i; j++)
            {

                if (nums[i] > nums[j]) dp[i] = std::max(dp[i], dp[j] + 1);

            }

            result = std::max(result, dp[i]);

        }

        return result;

    }

};
