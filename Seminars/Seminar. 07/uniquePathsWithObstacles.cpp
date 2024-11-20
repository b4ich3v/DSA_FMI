#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
#include <queue>

class Solution 
{
public:

    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) 
    {

        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1 || obstacleGrid[rows - 1][cols - 1] == 1)  return 0;

        std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols, 0));
        matrix[0][0] = 1;

        for (int j = 1; j < cols; j++) 
        {

            matrix[0][j] = (obstacleGrid[0][j] == 0 && matrix[0][j - 1] == 1) ? 1 : 0;

        }

        for (int i = 1; i < rows; i++) 
        {

            matrix[i][0] = (obstacleGrid[i][0] == 0 && matrix[i - 1][0] == 1) ? 1 : 0;

        }

        for (int i = 1; i < rows; ++i)
        {

            for (int j = 1; j < cols; ++j) 
            {

                if (obstacleGrid[i][j] == 0) 
                {

                    matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];

                }

            }

        }

        return matrix[rows - 1][cols - 1];

    }

};



