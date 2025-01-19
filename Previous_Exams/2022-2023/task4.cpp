#include <cmath>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

long long bfs(long long start, long long end, std::unordered_set<long long>& blockedSet, std::unordered_set<long long>& pathSet,
    std::unordered_map<long long, std::unordered_set<long long>>& graph)
{

    if (start == end) return 0;

    std::queue<long long> q;
    std::unordered_set<long long> visited;
    long long counter = 0;

    q.push(start);
    visited.insert(start);

    while (!q.empty())
    {

        counter += 1;
        long long size = q.size();

        for (int i = 0; i < size; i++)
        {

            const auto current = q.front();
            q.pop();

            for (const auto& child : graph[current])
            {

                if (child == end) return counter;

                if (visited.find(child) == visited.end() &&
                    blockedSet.find(child) == blockedSet.end() &&
                    pathSet.find(child) == pathSet.end())
                {

                    q.push(child);
                    visited.insert(child);

                }

            }

        }

    }

    return -1;

}

int main()
{

    long long N = 0;
    long long M = 0;
    std::cin >> N >> M;
    std::unordered_map<long long, std::unordered_set<long long>> graph;

    for (long long i = 0; i < N; i++) graph[i];

    for (long long i = 0; i < M; i++)
    {

        long long node1 = 0;
        long long node2 = 0;
        std::cin >> node1 >> node2;

        graph[node1].insert(node2);
        graph[node2].insert(node1);

    }

    long long P = 0;
    std::cin >> P;
    std::vector<long long> path(P);
    for (long long i = 0; i < P; i++) std::cin >> path[i];

    long long K = 0;
    std::cin >> K;
    std::vector<long long> blocked(K);
    for (long long i = 0; i < K; i++) std::cin >> blocked[i];

    std::unordered_set<long long> pathSet(path.begin(), path.end());
    std::unordered_set<long long> blockedSet(blocked.begin(), blocked.end());

    long long result = 0;
    pathSet.erase(path[0]);

    for (long long i = 0; i < P - 1; i++)
    {

        long long currentLen = bfs(path[i], path[i + 1], blockedSet, pathSet, graph);

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
