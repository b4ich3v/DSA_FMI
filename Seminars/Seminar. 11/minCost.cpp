#include <cmath>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <climits>

struct Node 
{
public:

    int x;
    int y;
    int price;

    bool operator < (const Node& other) const 
    {

        return price > other.price;

    }

};

std::vector<std::vector<int>> directions = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

class Solution 
{
private:

    bool isValid(int x, int y, int rows, int cols) 
    {

        return 0 <= x && x < rows && 0 <= y && y < cols;

    }

    bool newPrice(int index, int arrow) 
    {

        return index != arrow - 1;

    }

public:

    int minCost(std::vector<std::vector<int>>& grid)
    {

        int rows = grid.size();
        int cols = grid[0].size();

        std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols, INT_MAX));
        std::priority_queue<Node> q;

        q.push({ 0,0,0 });
        matrix[0][0] = 0;

        while (!q.empty())
        {

            const auto current = q.top();
            q.pop();

            if (current.price > matrix[current.x][current.y]) continue;
            if (current.x == rows - 1 && current.y == cols - 1) return current.price;

            for (int i = 0; i < 4; i++)
            {

                int newX = current.x + directions[i][0];
                int newY = current.y + directions[i][1];

                if (isValid(newX, newY, rows, cols)) 
                {

                    int newDistance = current.price + newPrice(i, grid[current.x][current.y]);

                    if (newDistance < matrix[newX][newY]) 
                    {

                        matrix[newX][newY] = newDistance;
                        q.push({ newX, newY, newDistance });

                    }

                }

            }

        }

        return 0;

    }

};
