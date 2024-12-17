#include <cmath>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

class Solution
{

    bool dfs(int current, std::unordered_map<int, std::unordered_set<int>>& graph, std::unordered_map<int, bool>& colors, bool currentColor = true) 
    {

        auto iter = colors.find(current);

        if (iter != colors.end()) return iter->second == currentColor;

        colors[current] = currentColor;

        for (auto& child : graph[current])
        {

            if (!dfs(child, graph, colors, !currentColor)) return false;

        }

        return true;

    }

public:

    bool possibleBipartition(int n, std::vector<std::vector<int>>& dislikes)
    {
     
        std::unordered_map<int, std::unordered_set<int>> graph;

        for (auto& edge : dislikes)
        {

            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);

        }

        std::unordered_map<int, bool> colors;

        for (auto& current : graph)
        {

            auto iter = colors.find(current.first);

            if (iter == colors.end())
            {

                if (!dfs(current.first, graph, colors)) return false;

            }

        }

        return true;

    }

};
