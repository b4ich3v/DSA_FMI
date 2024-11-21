#include <vector>
#include <algorithm>
#include <string>

class Solution
{
public:

    int uniquePathsIII(std::vector<std::vector<int>>& grid)
    {

        int rows = grid.size();
        int cols = grid[0].size();

        int startX = 0;
        int startY = 0;
        int emptySquares = 0;

        for (int i = 0; i < rows; i++)
        {

            for (int j = 0; j < cols; j++)
            {

                if (grid[i][j] == 1) { startX = i;  startY = j; }
                else if (grid[i][j] == 0) emptySquares++;

            }

        }

        emptySquares++;
        return allPaths(grid, startX, startY, emptySquares);

    }

    int allPaths(std::vector<std::vector<int>>& grid, int x, int y, int remaining)
    {

        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == -1) return 0;

        if (grid[x][y] == 2)
        {

            if (remaining == 0) return 1;
            else return 0;

        }

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
