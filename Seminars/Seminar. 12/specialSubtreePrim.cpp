#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

struct Edge 
{

	int from = 0;
	int to = 0;
	int weight = 0;

	bool operator < (const Edge& other) const 
	{

		return weight > other.weight;

	}

};

int prims(int n, std::vector<std::vector<int>> edges, int start) 
{

	std::unordered_map<int, std::vector<Edge>> graph;

	for (const auto& current : edges)
	{

		graph[current[0]].push_back({ current[0],current[1],current[2] });
		graph[current[1]].push_back({ current[1],current[0],current[2] });

	}

	std::priority_queue<Edge> q;
	std::unordered_set<int> visited;
	int result = 0;

	q.push({ start, start, 0 });

	while (!q.empty() && visited.size() < n) 
	{

		const auto current = q.top();
		q.pop();

		if (visited.find(current.to) != visited.end()) continue;

		visited.insert(current.to);
		result += current.weight;

		for (const auto& child : graph[current.to])
		{

			if (visited.find(child.to) != visited.end()) continue;
			q.push(child);

		}

	}

	return result;

}
