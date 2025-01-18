#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <climits>

std::unordered_map<int, std::unordered_set<int>> graph;

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

int solve() 
{

	int X = 0;
	int Y = 0;
	std::cin >> X >> Y;

	for (int i = 0; i < X; i++) graph[i];

	for (int i = 0; i < Y; i++)
	{

		int xi = 0;
		int xj = 0;
		std::cin >> xi >> xj;

		graph[xi].insert(xj);
		graph[xj].insert(xi);

	}

	int counter = 0;
	std::unordered_set<int> visited;

	for (const auto& current : graph) 
	{

		if (visited.find(current.first) != visited.end()) continue;
		dfs(current.first, visited, graph);
		counter += 1;

	}

	graph.clear();
	return counter;

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
