#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

struct Edge
{
public:

    int from = 0;
    int to = 0;
    int weight = 0;

    bool operator < (const Edge& other) const
    {

        return weight > other.weight;

    }

};

class Solution 
{
public:

    int minCostConnectPoints(std::vector<std::vector<int>>& points) 
    {

        std::unordered_map<int, std::vector<Edge>> graph;

        for (int i = 0; i < points.size(); i++)
        {

            for (int j = i + 1; j < points.size(); j++)
            {

                int distance = std::abs(points[i][0] - points[j][0]) + std::abs(points[i][1] - points[j][1]);
                graph[i].push_back({ i, j,  distance });
                graph[j].push_back({ j, i,  distance });

            }

        }

        std::priority_queue<Edge> q;
        std::unordered_set<int> visited;
        int result = 0;

        q.push({ 0, 0, 0 });

        while (!q.empty() && visited.size() < points.size()) 
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

};
