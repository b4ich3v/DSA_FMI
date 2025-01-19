#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

void dfs(int current, std::unordered_set<int>& visited, std::unordered_map<int, std::unordered_set<int>>& graph, int& countOfNodes) 
{

    visited.insert(current);
    countOfNodes += 1;

    for (const auto& child : graph[current])
    {

        if (visited.find(child) == visited.end()) 
        {

            dfs(child, visited, graph, countOfNodes);

        }

    }

}

int main() 
{
   
    int N = 0;
    int E = 0;
    int K = 0;
    std::cin >> N >> E >> K;

    std::unordered_map<int, std::unordered_set<int>> graph;

    for (int i = 0; i < N; i++) graph[i];

    for (int i = 0; i < E; i++)
    {

        int node1 = 0;
        int node2 = 0;
        std::cin >> node1 >> node2;

        graph[node1].insert(node2);
        graph[node2].insert(node1);

    }

    int result = 0;
    std::unordered_set<int> visited;

    for (int i = 0; i < N; i++)
    {

        if (visited.find(i) != visited.end()) continue;
        int countOfNodes = 0;
        dfs(i, visited, graph, countOfNodes);

        if (countOfNodes % K == 0) result += 1;

    }

    std::cout << result;

    return 0;
}
