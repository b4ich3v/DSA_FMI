#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

struct Edge
{

    int from;
    int to;
    int weight;

    bool operator < (const Edge& other) const
    {

        return weight > other.weight;

    }

};

std::vector<Edge> prim(int countOfNodes, int start, std::unordered_map<int, std::vector<Edge>>& graph)
{

    std::priority_queue<Edge> q;
    std::unordered_set<int> visited;
    q.push({ start, start, 0 });

    std::vector<Edge> mstEdges;

    while (!q.empty() && visited.size() < countOfNodes)
    {

        const auto current = q.top();
        q.pop();

        if (visited.find(current.to) != visited.end()) continue;

        visited.insert(current.to);
        mstEdges.push_back(current);

        for (const auto& child : graph[current.to])
        {

            if (visited.find(child.to) == visited.end()) q.push(child);

        }

    }

    return mstEdges;

}
