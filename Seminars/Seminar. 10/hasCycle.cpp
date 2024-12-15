#include <iostream>
#include <unordered_set>
#include <unordered_map>

std::unordered_map<int, std::unordered_set<int>> graph;

bool dfs(int current, std::unordered_map<int, int>& colours, std::unordered_map<int, std::unordered_set<int>>& graph)
{

    colours[current] = 1;

    for (int neighbor : graph[current])
    {

        if (colours[neighbor] == 1) return true;
        if (colours[neighbor] == 2) continue;
        if (dfs(neighbor, colours, graph)) return true;

    }

    colours[current] = 2;
    return false;

}

bool hasCycle(std::unordered_map<int, std::unordered_set<int>>& graph)
{

    std::unordered_map<int, int> colours;

    for (const auto& current : graph)
    {

        if (colours[current.first] != 0) continue;
        if (dfs(current.first, colours, graph)) return true;

    }

    return false;

}

bool solve()
{

    int V, E = 0;
    std::cin >> V >> E;

    for (int i = 0; i < V; i++) graph[i];
    
    for (int e = 0; e < E; e++)
    {
        
        int node1, node2, kg = 0;
        std::cin >> node1 >> node2 >> kg;
        graph[node1].insert(node2);

    }

    bool result = hasCycle(graph);
    graph.clear();

    return result;

}

int main()
{

    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int Q;
    std::cin >> Q;

    for (int i = 0; i < Q; i++)
    {

        std::string result = solve() ? "true" : "false";
        std::cout << result << " ";

    }

    return 0;

}
