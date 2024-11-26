#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:

    int countVowelStrings(int n)
    {

        std::vector<int> dp(5, 1); 

        for (int i = 2; i <= n; i++)
        {

            for (int j = 1; j <= 4; j++) 
            {

                dp[j] += dp[j - 1];

            }

        }

        int total = 0;
        for (int count : dp) total += count;

        return total;

    }

};



