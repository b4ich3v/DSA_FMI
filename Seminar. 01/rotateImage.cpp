#include <iostream>
#include <vector>

class Solution 
{
public:

    void rotate(std::vector<std::vector<int>>& matrix)
    {

        int size = matrix.size();

        for (int i = 0; i < size; i++)
        {

            for (int j = 0; j < size; j++)
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
