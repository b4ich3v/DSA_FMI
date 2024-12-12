#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_set>

void bfs(int start, const std::unordered_map<int, std::unordered_set<int>>& graph)
{

	std::queue<int> q;
	std::vector<bool> visited(graph.size(), false);

	visited[start] = true;
	q.push(start);


	while (!q.empty())
	{

		int size = q.size();

		for (int i = 0; i < size; i++)
		{

			int current = q.front();
			q.pop();

			for (const int child : graph[current])
			{

				if (!visited[child]) 
				{

					q.push(child);
					visited[child] = true;

				}

			}

			std::cout << current << " ";

		}

	}

}


