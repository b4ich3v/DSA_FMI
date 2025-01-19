#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

std::unordered_map<int, std::unordered_set<int>> graph;
std::unordered_set<int> visited;
int counter = 0;

void dfs(int current, std::unordered_set<int>& visited, std::unordered_map<int, std::unordered_set<int>>& graph,
	int parent, bool& hasCycle)
{

	visited.insert(current);

	for (const auto& child : graph[current])
	{

		if (visited.find(child) == visited.end()) 
		{

			dfs(child, visited, graph, current, hasCycle);

		}
		else if (child != parent)
		{

			hasCycle = true;

		}

	}

}

int main() 
{

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T = 0;
	std::cin >> T;

	for (int i = 0; i < T; i++)
	{

		int V = 0;
		int E = 0;
		std::cin >> V >> E;

		for (int i = 0; i < V; i++) graph[i];

		for (int i = 0; i < E; i++)
		{

			int node1 = 0;
			int node2 = 0;
			std::cin >> node1 >> node2;

			graph[node1].insert(node2);
			graph[node2].insert(node1);

		}

		for (const auto& current : graph)
		{

			if (visited.find(current.first) != visited.end()) continue;

			bool hasCycle = false;
			dfs(current.first, visited, graph, -1, hasCycle);
			if (hasCycle) counter += 1;

		}

		graph.clear();
		visited.clear();
		std::cout << counter << std::endl;
		counter = 0;

	}

	return 0;

}
