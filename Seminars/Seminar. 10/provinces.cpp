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

    void dfs(int current, std::unordered_set<int>& visited, std::unordered_map<int, std::unordered_set<int>>& graph) 
    {

        visited.insert(current);

        for (const auto& child : graph[current]) 
        {

            if (visited.find(child) == visited.end())
            {

                dfs(child, visited, graph);

            }

        }

    }

    int findCircleNum(std::vector<std::vector<int>>& isConnected) 
    {

        std::unordered_map<int, std::unordered_set<int>> graph;

        for (int i = 0; i < isConnected.size(); i++)
        {

            for (int j = 0; j < isConnected.size(); j++)
            {

                if (isConnected[i][j] == 1)
                {

                    graph[i].insert(j);
                    graph[j].insert(i);

                }

            }

        }

        std::unordered_set<int> visited;
        int result = 0;

        for (const auto& current : graph)
        {

            if (visited.find(current.first) != visited.end()) continue;
            result += 1;
            dfs(current.first, visited, graph);

        }

        return result;

    }

};
