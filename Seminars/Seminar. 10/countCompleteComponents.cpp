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

    void dfs(int current, std::unordered_set<int>& visited, std::unordered_map<int, std::unordered_set<int>>& graph,
            int& countOfNodes, int& countOfEdges)
    {

        visited.insert(current);
        countOfNodes += 1;

        for (const auto& child : graph[current]) 
        {

            countOfEdges += 1;

            if (visited.find(child) == visited.end()) 
            {

                dfs(child, visited, graph, countOfNodes, countOfEdges);

            }

        }

    }

    int countCompleteComponents(int n, std::vector<std::vector<int>>& edges) 
    {

        std::unordered_map<int, std::unordered_set<int>> graph;

        for (int i = 0; i < n; i++) graph[i];

        for (int i = 0; i < edges.size(); i++)
        {

            graph[edges[i][0]].insert(edges[i][1]);
            graph[edges[i][1]].insert(edges[i][0]);

        }


        int result = 0;
        std::unordered_set<int> visited;

        int countOfNodes = 0;
        int countOfEdges = 0;

        for (const auto& current : graph)
        {

            if (visited.find(current.first) != visited.end()) continue;
            dfs(current.first, visited, graph, countOfNodes, countOfEdges);

            countOfEdges /= 2;
            if (countOfEdges == (countOfNodes * (countOfNodes - 1)) / 2) result += 1;

            countOfNodes = 0;
            countOfEdges = 0;

        }

        return result;

    }

};
