#include <vector>
#include <algorithm> 

class Solution 
{
public:

    int coinChange(std::vector<int>& coins, int amount)
    {
     
        std::vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int coin : coins) 
        {
            
            for (int i = coin; i <= amount; i++) 
            {
               
                dp[i] = std::min(dp[i], dp[i - coin] + 1);

            }

        }

        return dp[amount] <= amount ? dp[amount] : -1;

    }

};
