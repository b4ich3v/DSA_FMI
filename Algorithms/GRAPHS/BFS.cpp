#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_set>

void bfs(int start, std::unordered_map<int, std::unordered_set<int>>& graph) 
{

	std::queue<int> q;
	std::unordered_set<int> visited;

	q.push(start);
	visited.insert(start);

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


				}

			}

			std::cout << current << " ";

		}

	}

}
