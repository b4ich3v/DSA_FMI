#include <vector>
#include <algorithm>
#include <string>

class Solution 
{
public:

    int longestCommonSubsequence(std::string text1, std::string text2) 
    {

        int rows = text1.size();
        int cols = text2.size();

        std::vector<std::vector<int>> dp(rows + 1, std::vector<int>(cols + 1, 0));

        for (int i = 1; i <= rows; ++i) 
        {

            for (int j = 1; j <= cols; ++j) 
            {

                if (text1[i - 1] == text2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else  dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);

            }

        }

        return dp[rows][cols];

    }

};
