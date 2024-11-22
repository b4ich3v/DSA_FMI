#include <vector>

class Solution
{
public:

    bool canJump(std::vector<int>& nums)
    {

        int n = nums.size();
        std::vector<bool> dp(n, false); 
        dp[0] = true; 

        for (int i = 0; i < n; i++)
        {

            if (dp[i]) 
            {
                int maxJump = std::min(n - 1, i + nums[i]); 
                for (int j = i + 1; j <= maxJump; j++) dp[j] = true;
            }

        }

        return dp[n - 1]; 

    }

};
