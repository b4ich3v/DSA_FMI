#include <iostream>
#include <string>
#include <vector>

class Solution 
{
public:

    int getMoneyAmount(int n) 
    {

        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));

        for (int i = 2; i <= n; i++)
        {

            for (int j = 0; j <= n - i; j++) 
            {

                int end = i + j;

                for (int k = j; k < end; k++)
                {

                    int numPicked = k + 1;

                    if (k == j) 
                    {

                        dp[j][end] = numPicked + dp[j + 1][end];

                    }
                    else
                    {

                        dp[j][end] = std::min(dp[j][end], std::max(dp[j][k], dp[k + 1][end]) + numPicked);

                    }

                }

            }

        }

        return dp[0][n];

    }

};
