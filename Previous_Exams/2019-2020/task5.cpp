#include <cmath>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

int bfs(int start, int end, std::unordered_map<int, std::unordered_set<int>>& graph,
    std::unordered_set<int>& attractionsSet)
{

    int counter = 0;

    std::unordered_set<int> visited;
    std::queue<int> q;
    q.push(start);

    while (!q.empty()) 
    {

        counter += 1;
        int size = q.size();

        for (int i = 0; i < size; i++)
        {

            const auto current = q.front();
            q.pop();

            for (const auto& child : graph[current])
            {

                if (child == end) return counter;

                if (visited.find(child) == visited.end() &&
                    attractionsSet.find(child) == attractionsSet.end())
                {

                    visited.insert(child);
                    q.push(child);

                }

            }

        }

    }

    return -1;

}

int main() 
{

    int N = 0;
    int M = 0;
    std::cin >> N >> M;
    std::unordered_map<int, std::unordered_set<int>> graph;

    for (int i = 0; i < N; i++) graph[i];

    for (int i = 0; i < M; i++)
    {

        int a = 0;
        int b = 0;
        std::cin >> a >> b;

        graph[a].insert(b);

    }

    int K = 0;
    std::cin >> K;
    std::vector<int> attractions(K);

    for (int i = 0; i < K; i++) std::cin >> attractions[i];

    std::unordered_set<int> attractionsSet(attractions.begin(), attractions.end());
    attractionsSet.erase(attractions[0]);
    int result = 0;

    for (int i = 0; i < K - 1; i++)
    {

        attractionsSet.erase(attractions[i + 1]);
        int currentLen = bfs(attractions[i], attractions[i + 1], graph, attractionsSet);
        
        if (currentLen == -1) 
        {

            std::cout << -1;
            return 0;

        }
        else
        {

            result += currentLen;

        }

    }

    std::cout << result;
    return 0;

}
