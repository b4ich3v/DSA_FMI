#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iostream>
#include <climits>
#include <algorithm>

std::unordered_map<int, std::unordered_set<int>> graph;

bool dfs(int current, std::unordered_map<int, int>& colours, std::unordered_map<int, std::unordered_set<int>>& graph) 
{

    colours[current] = 1;

    for (const auto& child : graph[current])
    {

        if (colours[child] == 1) return true;
        if (colours[child] == 2) continue;
        if (dfs(child, colours, graph)) return true;

    }

    colours[current] = 2;
    return false;

}

bool hasCycle(std::unordered_map<int, std::unordered_set<int>>& graph) 
{

    std::unordered_map<int, int> colours;

    for (const auto& current : graph)
    {
        
        if (colours[current.first] == 2) continue;
        if (dfs(current.first, colours, graph)) return true;

    }

    return false;

}

bool solve() 
{

    int V = 0;
    int E = 0;
    std::cin >> V >> E;

    for (int i = 0; i < V; i++) graph[i];

    for (int i = 0; i < E; i++)
    {

        int xi = 0;
        int yi = 0;
        int wi = 0;

        std::cin >> xi >> yi >> wi;

        graph[xi].insert(yi);

    }

    bool result = hasCycle(graph);
    graph.clear();

    return result;

}

int main()
{

    int N = 0;
    std::cin >> N;

    for (int i = 0; i < N; i++)
    {

        if (solve()) std::cout << "true" << " ";
        else std::cout << "false" << " ";

    }

    return 0;

}


