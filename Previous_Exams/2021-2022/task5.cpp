#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <string>
#include <stack>

std::unordered_set<int> visited;

void bfs(int start, std::unordered_map<int, std::unordered_set<int>>& graph, int& result)
{

	std::queue<int> q;
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

					result += child;
					q.push(child);
					visited.insert(child);

				}

			}

		}


	}

}

int main() 
{

	int M = 0;
	int T = 0;
	std::cin >> M >> T;

	std::unordered_map<int, std::unordered_set<int>> graph;
	std::vector<int> array(T);

	for (int i = 0; i < M; i++)
	{

		int node1 = 0;
		int node2 = 0;
		std::cin >> node1 >> node2;

		graph[node1].insert(node2);

	}

	for (int i = 0; i < T; i++)
	{

		int index = 0;
		std::cin >> index;

		array[i] = index;

	}

	for (int i = 0; i < T; i++)
	{

		int result = 0;
		int currentStart = array[i];
		bfs(currentStart, graph, result);

		std::cout << result << std::endl;
		visited.clear();

	}

	return 0;

}
