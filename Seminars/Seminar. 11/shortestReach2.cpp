#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>

struct Edge 
{

    int to;
    int weight;

};

struct Node 
{

    int node;
    int distance;

    bool operator < (const Node& other) const 
    {

        return distance > other.distance;

    }

};

std::vector<int> shortestReach(int n, std::vector<std::vector<int>> edges, int s) 
{

    std::unordered_map<int, std::vector<Edge>> graph;

    for (int i = 0; i < edges.size(); i++) 
    {

        graph[edges[i][0]].push_back({ edges[i][1], edges[i][2] });
        graph[edges[i][1]].push_back({ edges[i][0], edges[i][2] });

    }

    std::vector<int> distances(n, INT_MAX);
    distances[s - 1] = 0;
    std::priority_queue<Node> q;
    q.push({ s, 0 });

    while (!q.empty()) 
    {

        const auto current = q.top();
        q.pop();

        if (current.distance > distances[current.node - 1]) continue;

        for (const auto& child : graph[current.node]) 
        {

            int newDistance = current.distance + child.weight;

            if (newDistance < distances[child.to - 1]) 
            {

                distances[child.to - 1] = newDistance;
                q.push({ child.to, newDistance });

            }

        }

    }

    distances.erase(distances.begin() + s - 1);

    for (int i = 0; i < distances.size(); i++) 
    {

        if (distances[i] == INT_MAX) distances[i] = -1;

    }

    return distances;

}
