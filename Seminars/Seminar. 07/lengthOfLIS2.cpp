#include <iostream>
#include <string>
#include <vector>

class Solution 
{
public:

    int longestCommonSubstringInOrder(std::string text1, std::string text2)
    {

        int rows = text1.size();
        int cols = text2.size();
        int result = 0;  
        std::vector<std::vector<int>> dp(rows + 1, std::vector<int>(cols + 1, 0));

        for (int i = 1; i <= rows; i++)
        {

            for (int j = 1; j <= cols; j++)
            {

                if (text1[i - 1] == text2[j - 1]) 
                {

                    dp[i][j] = dp[i - 1][j - 1] + 1;  
                    result = std::max(result, dp[i][j]);  

                }
                else dp[i][j] = 0;

            }

        }

        return result;

    }

};


