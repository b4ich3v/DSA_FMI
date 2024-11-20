#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
#include <queue>

class Solution 
{
public:

    int uniquePaths(int m, int n)
    {

        std::vector<std::vector<int>> matrix(m, std::vector<int>(n, 1));

        for (int i = 1; i < m; i++)
        {

            for (int j = 1; j < n; j++)
            {

                matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];

            }

        }

        return matrix[m - 1][n - 1];

    }

};


