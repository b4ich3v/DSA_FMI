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
    int effort;

    bool operator < (const Node& other) const 
    {

        return effort > other.effort;

    }

};

std::vector<std::vector<int>> directions = { {0, 1}, {0,-1}, {1,0}, {-1,0} };

class Solution 
{
private:

    bool isValid(int x, int y, int rows, int cols) 
    {

        return 0 <= x && x < rows && 0 <= y && y < cols;

    }

public:

    int minimumEffortPath(std::vector<std::vector<int>>& heights)
    {

        int rows = heights.size();
        int cols = heights[0].size();

        std::vector<std::vector<int>> efforts(rows, std::vector<int>(cols, INT_MAX));
        std::priority_queue<Node> q;

        q.push({ 0,0,0 });
        efforts[0][0] = 0;

        while (!q.empty())
        {

            const auto current = q.top();
            q.pop();

            if (current.effort > efforts[current.x][current.y]) continue;
            if (current.x == rows - 1 && current.y == cols - 1) return current.effort;

            for (int i = 0; i < 4; i++)
            {

                int newX = current.x + directions[i][0];
                int newY = current.y + directions[i][1];

                if (isValid(newX, newY, rows, cols)) 
                {

                    int newEffort = std::max(current.effort, std::abs(heights[current.x][current.y] - heights[newX][newY]));

                    if (newEffort < efforts[newX][newY]) 
                    {

                        efforts[newX][newY] = newEffort;
                        q.push({ newX, newY, newEffort });

                    }

                }

            }

        }

        return 0;

    }

};
