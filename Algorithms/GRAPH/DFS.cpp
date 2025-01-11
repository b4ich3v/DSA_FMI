#include <string>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_set>

void dfs(int current, std::unordered_map<int, std::unordered_set<int>>& graph, std::unordered_set<int>& visited) 
{

	std::cout << current << " ";
	visited.insert(current);

	for (const auto& child : graph[current])
	{

		if (visited.find(child) == visited.end())
		{

			dfs(child, graph, visited);

		}

	}

}
