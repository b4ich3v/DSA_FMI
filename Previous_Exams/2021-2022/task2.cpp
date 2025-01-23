#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <algorithm>

std::unordered_map<int, std::unordered_set<int>> graph;

void bfs(int start, int N) 
{

	std::vector<int> distances(N + 1, -1);
	std::queue<int> q;
	std::unordered_set<int> visited;

	distances[start] = 0;
	q.push(start);
	visited.insert(start);

	while (!q.empty()) 
	{

		int size = q.size();

		for (int i = 0; i < size; i++)
		{

			const auto current = q.front();
			q.pop();

			for (const auto& child : graph[current]) 
			{

				if (visited.find(child) == visited.end()) 
				{

					q.push(child);
					visited.insert(child);
					distances[child] = distances[current] + 6;

				}

			}

		}

	}

	for (int i = 1; i <= N; i++)
	{

		if (i == start) continue;
		std::cout << distances[i] << " ";

	}

}

int main() 
{

	int Q = 0;
	std::cin >> Q;

	for (int i = 0; i < Q; i++)
	{

		int N = 0;
		int M = 0;
		std::cin >> N >> M;

		for (int j = 1; j <= N; j++) graph[j];

		for (int j = 0; j < M; j++)
		{

			int x = 0;
			int y = 0;
			std::cin >> x >> y;

			graph[x].insert(y);
			graph[y].insert(x);

		}

		int index = 0;
		std::cin >> index;

		bfs(index, N);
		std::cout << std::endl;
		graph.clear();

	}

	return 0;

}
