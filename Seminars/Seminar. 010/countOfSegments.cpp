#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_set>

std::unordered_map<int, std::unordered_set<int>> graph;

void dfs(int current, std::unordered_map<int, std::unordered_set<int>>& graph, std::unordered_set<int>& visited) 
{

	visited.insert(current);

	for (const auto& child : graph[current])
	{

		if (visited.find(child) == visited.end()) 
		{

			dfs(child, graph, visited);

		}

	}

}

int solve() 
{

	int X = 0;
	int Y = 0;

	std::cin >> X >> Y;

	for (int i = 0; i < X; i++) graph[i];

	for (int i = 0; i < Y; i++)
	{

		int node1, node2 = 0;
		std::cin >> node1 >> node2;

		graph[node1].insert(node2);
		graph[node2].insert(node1);

	}

	int result = 0;
	std::unordered_set<int> visited;

	for (const auto& current : graph)
	{

		if (visited.find(current.first) != visited.end()) continue;
		result += 1;
		dfs(current.first, graph, visited);

	}

	graph.clear();
	return result;

}

int main() 
{

	int T = 0;
	std::cin >> T;

	for (int i = 0; i < T; i++)
	{

		int result = solve();
		std::cout << result << " ";

	}

	return 0;

}
