#include <cmath>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <climits>

struct Node 
{

    int x;
    int y;
    int removedObstacles;

    bool operator<(const Node& other) const 
    {

        return removedObstacles > other.removedObstacles;

    }

};

std::vector<std::vector<int>> directions = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

class Solution 
{

    bool isValid(int x, int y, int rows, int cols) 
    {

        return 0 <= x && x < rows && 0 <= y && y < cols;

    }

public:

    int minimumObstacles(std::vector<std::vector<int>>& grid) 
    {

        int rows = grid.size();
        int cols = grid[0].size();

        std::vector<std::vector<int>> minObstacles(rows, std::vector<int>(cols, INT_MAX));
        std::priority_queue<Node> q;
        q.push({ 0, 0, 0 });
        minObstacles[0][0] = 0;

        while (!q.empty()) 
        {

            const auto current = q.top();
            q.pop();

            if (minObstacles[current.x][current.y] < current.removedObstacles) continue;
            if (current.x == rows - 1 && current.y == cols - 1) return current.removedObstacles;

            for (int i = 0; i < 4; i++) 
            {

                int newX = current.x + directions[i][0];
                int newY = current.y + directions[i][1];

                if (isValid(newX, newY, rows, cols)) 
                {

                    int newPositionRemovedObstacles = current.removedObstacles + grid[newX][newY];

                    if (newPositionRemovedObstacles < minObstacles[newX][newY])
                    {

                        minObstacles[newX][newY] = newPositionRemovedObstacles;
                        q.push({ newX, newY, newPositionRemovedObstacles });

                    }

                }

            }

        }

        return 0;

    }

};
