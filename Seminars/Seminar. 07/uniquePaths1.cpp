#include <vector>
#include <algorithm>
#include <string>

class Solution
{
public:

    int uniquePaths(int rows, int cols)
    {

        std::vector<std::vector<int>> dp(rows, std::vector<int>(cols, 0));

        for (int i = 0; i < rows; i++) dp[i][0] = 1;
        for (int i = 0; i < cols; i++) dp[0][i] = 1;

        for (int i = 1; i < rows; i++)
        {

            for (int j = 1; j < cols; j++)
            {

                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

            }

        }

        return dp[rows - 1][cols - 1];

    }

};
