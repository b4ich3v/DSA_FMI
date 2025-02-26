#include <vector>
#include <algorithm> 

class Solution
{
public:

    int maxPathSum(std::vector<std::vector<int>>& grid) 
    {

        int rows = grid.size();
        int cols = grid[0].size();

        std::vector<std::vector<int>> dp(rows, std::vector<int> (cols, 0));
        dp[0][0] = grid[0][0];

        for (int i = 1; i < cols; i++) dp[0][i] = grid[0][i] + dp[0][i - 1];
        for (int i = 1; i < rows; i++) dp[i][0] = grid[i][0] + dp[i - 1][0];

        for (int i = 1; i < rows; i++)
        {

            for (int j = 1; j < cols; j++)
            {

                dp[i][j] = grid[i][j] + std::max(dp[i - 1][j], dp[i][j - 1]);

            }

        }

        return dp[rows - 1][cols - 1];

    }

};
