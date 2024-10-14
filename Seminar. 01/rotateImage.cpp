#include <iostream>
#include <vector>
#include <algorithm>

class Solution 
{
public:

    void rotate(std::vector<std::vector<int>>& matrix)
    {

        int size = matrix.size();

        for (int i = 0; i < size; i++)
        {

            for (int j = i + 1; j < size; j++)
            {

                std::swap(matrix[i][j], matrix[j][i]);

            }

        }

        for (int i = 0; i < size; i++)
        {

            std::reverse(matrix[i].begin(), matrix[i].end());

        }

    }

};
