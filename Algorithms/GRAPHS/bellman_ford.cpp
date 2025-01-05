#include <vector>
#include <iostream>

struct Edge
{
public:

	int from = 0;
	int weight = 0;
	int to = 0;

};

std::vector<int> bellman_ford(int start, int countOfNodes, std::vector<Edge>& graph)
{

	std::vector<int> distances(countOfNodes, INT_MAX);
	distances[start] = 0;

	for (int i = 0; i < countOfNodes - 1; i++)
	{

		for (const auto& current : graph)
		{

			if (distances[current.from] != INT_MAX && 
				distances[current.from] + current.weight < distances[current.to]) 
			{

				distances[current.to] = distances[current.from] + current.weight;

			}

		}

	}

	for (const auto& current : graph) 
	{

		if (distances[current.from] != INT_MAX &&
			distances[current.from] + current.weight < distances[current.to])
		{

			throw std::logic_error("Negative cycle");

		}

	}

	return distances;

}
