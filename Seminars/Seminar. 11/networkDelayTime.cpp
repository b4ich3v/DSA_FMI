#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>

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

class Solution 
{
public:

    int networkDelayTime(std::vector<std::vector<int>>& times, int n, int k)
    {

        std::unordered_map<int, std::vector<Edge>> graph;

        for (int i = 0; i < times.size(); i++)
        {

            graph[times[i][0]].push_back({ times[i][1], times[i][2] });

        }

        std::vector<int> distances(n + 1, INT_MAX);
        std::priority_queue<Node> q;

        distances[k] = 0;
        q.push({ k, 0 });

        while (!q.empty())
        {

            const auto current = q.top();
            q.pop();

            for (const auto& child : graph[current.node]) 
            {

                int newDistance = current.distance + child.weight;

                if (newDistance < distances[child.to]) 
                {

                    distances[child.to] = newDistance;
                    q.push({ child.to, newDistance });

                }

            }

        }

        int result = 0;

        for (int i = 1; i <= n; i++)
        {

            result = std::max(distances[i], result);

        }

        if (result == INT_MAX) return -1;
        else return result;

    }

};
