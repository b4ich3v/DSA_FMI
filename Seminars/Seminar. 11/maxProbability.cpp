#include <cmath>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

struct Edge 
{

    int to = 0;
    double probability = 0;

};

struct Node 
{

    int node = 0;
    double probability = 0;

    bool operator < (const Node& other) const 
    {

        return probability < other.probability;

    }

};

class Solution 
{
public:

    double maxProbability(int n, std::vector<std::vector<int>>& edges, std::vector<double>& succProb, int startNode, int endNode) 
    {

        std::unordered_map<int, std::vector<Edge>> graph;

        for (int i = 0; i < edges.size(); i++) 
        {

            graph[edges[i][0]].push_back({ edges[i][1], succProb[i] });
            graph[edges[i][1]].push_back({ edges[i][0], succProb[i] });

        }

        std::vector<double> probRating(n, 0);
        probRating[startNode] = 1;
        std::priority_queue<Node> q;
        q.push({ startNode, 1 });

        while (!q.empty())
        {

            const auto current = q.top();
            q.pop();

            if (current.probability > probRating[current.node]) continue;
            if (current.node == endNode) return probRating[endNode];

            for (const auto& child : graph[current.node]) 
            {

                double newProbability = probRating[current.node] * child.probability;

                if (probRating[child.to] < newProbability) 
                {

                    probRating[child.to] = newProbability;
                    q.push({ child.to, newProbability });

                }

            }

        }

        return probRating[endNode];

    }

};
