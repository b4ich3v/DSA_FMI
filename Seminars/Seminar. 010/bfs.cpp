#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_set>

std::vector<int> bfs(int n, int m, std::vector<std::vector<int>> edges, int s) 
{

    std::vector<std::vector<int>> graph(n, std::vector<int>());

    for (int i = 0; i < m; i++)
    {

        int node1 = edges[i][0];
        int node2 = edges[i][1];
        
        graph[node1 - 1].push_back(node2 - 1);
        graph[node2 - 1].push_back(node1 - 1);

    }

    std::vector<int> result(n, -1);
    std::vector<bool> visited(n, false);
    std::queue<int> q;

    int start = s - 1;
    q.push(start);
    visited[start] = true;
    result[start] = 0;

    while (!q.empty()) 
    {

        int size = q.size();

        for (int i = 0; i < size; i++)
        {

            int current = q.front();
            q.pop();

            const auto& children = graph[current];

            for (auto& child : children)
            {

                if (!visited[child])
                {

                    visited[child] = true;
                    q.push(child);
                    result[child] = result[current] + 6;

                }

            }

        }

    }

    std::vector<int> finalResult;

    for (int i = 0; i < n; i++)
    {

        if (i != start) finalResult.push_back(result[i]);

    }

    return finalResult;

}


