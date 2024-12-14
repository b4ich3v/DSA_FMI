#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

int dfs(int current, int& result, std::unordered_map<int, std::unordered_set<int>>& graph, std::unordered_set<int>& visited)
{

    if (graph[current].size() == 0) return 1;

    visited.insert(current);
    int children = 1;

    for (const auto& child : graph[current])
    {

        if (!visited.count(child)) 
        {

            children += dfs(child, result, graph, visited);

        }

    }

    if (children % 2 == 0) 
    {

        result++;
        return 0;

    }

    return children;

}

int main() 
{

    int V, E = 0;
    std::cin >> V >> E;

    std::unordered_map<int, std::unordered_set<int>> graph;

    for (int i = 0; i < V; i++) graph[i];

    for (int i = 0; i < E; i++)
    {

        int node1, node2 = 0;
        std::cin >> node1 >> node2;

        graph[node1].insert(node2);
        graph[node2].insert(node1);

    }

    int result = 0;
    std::unordered_set<int> visited;
    dfs(1, result, graph, visited);

    std::cout << result - 1;
    return 0;

}
