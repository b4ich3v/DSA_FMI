#include <cmath>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

class Solution
{

    std::vector<std::vector<int>> result;

public:

    void dfs(int current, std::vector<int>& currentPath, std::vector<std::vector<int>>& graph) 
    {

        currentPath.push_back(current);

        if (current == graph.size() - 1)
        {

            result.push_back(currentPath);
            currentPath.pop_back();
            return;

        }

        for (const auto& child : graph[current]) 
        {

            dfs(child, currentPath, graph);

        }

        currentPath.pop_back();

    }

    std::vector<std::vector<int>> allPathsSourceTarget(std::vector<std::vector<int>>& graph)
    {

        std::vector<int> currentPath;
        dfs(0, currentPath, graph);

        return result;

    }

};
