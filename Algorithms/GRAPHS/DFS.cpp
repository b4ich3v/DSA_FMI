#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_set>

void dfs(int current, std::unordered_map<int, std::unordered_set<int>>& graph, std::vector<bool>& visited)
{

	std::cout << current << " ";
	visited[current] = true;

	for (const int child : graph[current]) 
	{

		if (!visited[child]) 
		{

			visited[child] = true;
			dfs(child, graph, visited);

		}

	}

}
