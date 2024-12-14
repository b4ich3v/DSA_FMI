#include <cmath>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

class Solution 
{
public:

    bool validPath(int n, std::vector<std::vector<int>>& edges, int source, int destination)
    {

        std::unordered_map<int, std::unordered_set<int>> graph;
        std::unordered_set<int> visited;
        std::queue<int> q;

        int start = source;
        int end = destination;

        for (int i = 0; i < n; i++) graph[i];

        for (int i = 0; i < edges.size(); i++)
        {

            graph[edges[i][0]].insert(edges[i][1]);
            graph[edges[i][1]].insert(edges[i][0]);

        }

        visited.insert(start);
        q.push(start);

        while (!q.empty())
        {

            int size = q.size();

            for (int i = 0; i < size; i++)
            {

                int current = q.front();
                q.pop();

                if (current == end) return true;

                for (const auto& child : graph[current])
                {

                    if (visited.find(child) == visited.end()) 
                    {

                        q.push(child);
                        visited.insert(child);

                    }

                }

            }

        }

        return false;

    }

};
