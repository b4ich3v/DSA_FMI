#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_set>

std::vector<int> bfs(int n, int m, std::vector<std::vector<int>> edges, int s)
{

	std::unordered_map<int, std::unordered_set<int>> graph;
	int start = s - 1;

	for (int i = 0; i < n; i++)
	{

		graph[i];

	}

	for (const auto& current : edges)
	{

		int node1 = current[0];
		int node2 = current[1];

		graph[node1 - 1].insert(node2 - 1);
		graph[node2 - 1].insert(node1 - 1);

	}

	std::queue<int> q;
	std::unordered_set<int> visited;
	std::vector<int> result(n, -1);

	result[start] = 0;
	visited.insert(start);
	q.push(start);

	while (!q.empty())
	{

		int size = q.size();

		for (int i = 0; i < size; i++)
		{

			int current = q.front();
			q.pop();

			for (const auto& child : graph[current]) 
			{

				if (visited.find(child) == visited.end())
				{

					q.push(child);
					visited.insert(child);
					result[child] = result[current] + 6;

				}

			}

		}

	}

	std::vector<int> finaltResult;

	for (int i = 0; i < n; i++)
	{

		if (i != start) finaltResult.push_back(result[i]);

	}

	return finaltResult;

}
