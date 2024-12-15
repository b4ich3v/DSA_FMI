#include <cmath>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

class Solution 
{
public:

    void dfs(int current, std::vector<bool>& visited, std::unordered_map<int, std::unordered_set<int>>& graph)
    {

        visited[current] = true;

        for (const auto& child : graph[current])
        {

            if (visited[child] == false)
            {

                dfs(child, visited, graph);

            }

        }

    }

    bool canVisitAllRooms(std::vector<std::vector<int>>& rooms)
    {

        std::unordered_map<int, std::unordered_set<int>> graph;

        for (int i = 0; i < rooms.size(); i++) graph[i];

        for (int i = 0; i < rooms.size(); i++)
        {

            for (int j = 0; j < rooms[i].size(); j++)
            {

                graph[i].insert(rooms[i][j]);

            }

        }

        std::vector<bool> visited(rooms.size(), false);
        dfs(0, visited, graph);

        for (int i = 0; i < rooms.size(); i++)
        {

            if (!visited[i]) return false;
                
        }

        return true;

    }

};
