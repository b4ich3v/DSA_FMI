#include <iostream>
#include <vector>
#include <algorithm>

class Solution 
{
public:

    void crawling(std::vector<std::vector<char>>& grid, int i, int j)
    {

        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size()) return;
        if (grid[i][j] != '1') return;

        grid[i][j] = '0';

        crawling(grid, i + 1, j);
        crawling(grid, i , j + 1);
        crawling(grid, i - 1, j);
        crawling(grid, i , j - 1);

    }

    int numIslands(std::vector<std::vector<char>>& grid) 
    {

        int result = 0;

        for (int i = 0; i < grid.size(); i++)
        {

            for (int j = 0; j < grid[i].size(); j++)
            {

                if (grid[i][j] == '1') 
                {

                    crawling(grid, i, j);
                    result++;

                }

            }

        }
        
        return result;

    }

};
