#include <iostream>
#include <string>
#include <vector>

class Solution 
{
public:

    bool dfs(std::vector<std::vector<char>>& matrix, int x, int y, int i, std::string word)
    {

        if (i == word.size()) return true;

        if (x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size() || matrix[x][y] == -1 || matrix[x][y] != word[i]) return false;

        int temp = matrix[x][y];
        matrix[x][y] = -1;

        bool result = dfs(matrix, x + 1, y, i + 1, word) ||
            dfs(matrix, x, y + 1, i + 1, word) ||
            dfs(matrix, x - 1, y, i + 1, word) ||
            dfs(matrix, x, y - 1, i + 1, word);

        matrix[x][y] = temp;
        return result;

    }

    bool exist(std::vector<std::vector<char>>&board, std::string word) 
    {

        int rows = board.size();
        int cols = board[0].size();


        for (int i = 0; i < rows; i++)
        {

            for (int j = 0; j < cols; j++)
            {

                if (dfs(board, i, j, 0, word)) return true;

            }

        }

        return false;

    }

};






