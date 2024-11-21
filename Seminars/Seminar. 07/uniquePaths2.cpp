#include <vector>
#include <algorithm>
#include <string>

class Solution 
{
public:

    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) 
    {

        if (obstacleGrid[0][0] == 1) return 0;

        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();

        std::vector<std::vector<int>> dp(rows, std::vector<int>(cols, 0));
        dp[0][0] = 1;

        for (int i = 1; i < rows; i++)
        {

            if (obstacleGrid[i][0] == 0 && dp[i - 1][0] == 1) dp[i][0] = 1;
            else dp[i][0] = 0;

        }

        for (int i = 1; i < cols; i++)
        {

            if (obstacleGrid[0][i] == 0 && dp[0][i - 1] == 1) dp[0][i] = 1;
            else dp[0][i] = 0;

        }

        for (int i = 1; i < rows; i++)
        {

            for (int j = 1; j < cols; j++)
            {

                if (obstacleGrid[i][j] == 0) dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                else dp[i][j] = 0;

            }

        }

        return dp[rows - 1][cols - 1];

    }

};
