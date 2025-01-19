#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

struct Edge 
{
public:

	long long from;
	long long to;
	long long weight;

	bool operator < (const Edge& other) const
	{

		return weight > other.weight;

	}

};

std::unordered_map<long long, std::vector<Edge>> graph;

void prim(long long start, std::unordered_map<long long, std::vector<Edge>>& graph, std::unordered_set<long long>& visited,
		  long long& result, long long K)
{

	long long mstWeight = 0;
	long long countOfNodes = 0;
	std::priority_queue<Edge> q;

	q.push({ start, start, 0 });

	while (!q.empty())
	{

		const auto current = q.top();
		q.pop();

		if (visited.find(current.to) != visited.end()) continue;

		countOfNodes += 1;
		mstWeight += current.weight;
		visited.insert(current.to);
		
		for (const auto& child : graph[current.to]) 
		{

			if (visited.find(child.to) != visited.end()) continue;
			q.push(child);

		}

	}

	if (countOfNodes % K == 0) result += mstWeight;

}

int main() 
{

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	long long T = 0;
	std::cin >> T;

	for (long long i = 0; i < T; i++)
	{

		long long V = 0;
		long long E = 0;
		long long K = 0;
		std::cin >> V >> E >> K;

		for (long long i = 0; i < V; i++) graph[i];

		for (long long i = 0; i < E; i++)
		{

			long long node1 = 0;
			long long node2 = 0;
			long long weight = 0;
			std::cin >> node1 >> node2 >> weight;
			
			graph[node1].push_back({ node1, node2, weight });
			graph[node2].push_back({ node2, node1, weight });

		}

		std::unordered_set<long long> visited;
		long long result = 0;

		for (const auto& current: graph)
		{

			if (visited.find(current.first) != visited.end()) continue;
			prim(current.first, graph, visited, result, K);

		}

		std::cout << result << std::endl;
		graph.clear();

	}

	return 0;

}
