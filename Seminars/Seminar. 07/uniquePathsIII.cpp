#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
#include <queue>

class Solution 
{
public:

    int uniquePathsIII(std::vector<std::vector<int>>& grid)
    {

        int rows = grid.size(), cols = grid[0].size();
        int startX = 0, startY = 0, emptySquares = 0;

        for (int i = 0; i < rows; i++)
        {

            for (int j = 0; j < cols; j++) 
            {

                if (grid[i][j] == 1) { startX = i;  startY = j;}
                else if (grid[i][j] == 0) emptySquares++;
 
            }

        }

        emptySquares++;
        return allPaths(grid, startX, startY, emptySquares);

    }

    int allPaths(std::vector<std::vector<int>>& grid, int x, int y, int remaining) 
    {

        int rows = grid.size(), cols = grid[0].size();

        if (x < 0 || x >= rows || y < 0 || y >= cols || grid[x][y] == -1) return 0;

        if (grid[x][y] == 2) return (remaining == 0) ? 1 : 0;

        int temp = grid[x][y];
        grid[x][y] = -1;

        int paths = allPaths(grid, x + 1, y, remaining - 1) +
                    allPaths(grid, x - 1, y, remaining - 1) +
                    allPaths(grid, x, y + 1, remaining - 1) +
                    allPaths(grid, x, y - 1, remaining - 1);

        grid[x][y] = temp;
        return paths;

    }
    
};




