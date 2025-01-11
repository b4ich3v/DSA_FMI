#include <vector>
#include <unordered_map>
#include <queue>

struct Node
{
public:

	int node = 0;
	int distance = 0;

	bool operator < (const Node& other) const
	{

		return distance > other.distance;

	}

};

struct Edge
{
public:

	int to = 0;
	int weight = 0;

};

std::vector<int> dijkstra(int start, int countOfNodes, std::unordered_map<int, std::vector<Edge>>& graph)
{

	std::vector<int> distances(countOfNodes, INT_MAX);
	std::priority_queue<Node> q;

	distances[start] = 0;
	q.push({ start, 0 });

	while (!q.empty())
	{

		const auto& current = q.top();
		q.pop();

		for (const auto& child : graph[current.node])
		{

			int newWeight = current.distance + child.weight;

			if (newWeight < distances[child.weight])
			{

				distances[child.to] = newWeight;
				q.push({ child.to, newWeight });

			}

		}

	}

	return distances;

}
