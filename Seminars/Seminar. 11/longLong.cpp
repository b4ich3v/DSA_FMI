#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

struct Edge
{
public:

    int from = 0;
    int to = 0;
    long long weight = 0;

};

int main() 
{
   
    int countOfNodes = 0;
    int countOfEdges = 0;
    int start = 0;
    int end = 0;

    std::cin >> countOfNodes >> countOfEdges >> start >> end;
    std::vector<Edge> edges;

    for (int i = 0; i < countOfEdges; i++)
    {

        int node1 = 0;
        int node2 = 0;
        long long weight = 0;

        std::cin >> node1 >> node2 >> weight;

        edges.push_back({ node1 , node2, weight });

    }

    std::vector<long long> distances(countOfNodes + 1, LLONG_MIN);
    distances[start] = 0;

    for (int i = 0; i < countOfNodes; i++)
    {

        for (const auto& current : edges) 
        {

            distances[current.to] = std::max(distances[current.to], distances[current.from] + current.weight);

        }

    }

    if (distances[end] == LLONG_MIN) std::cout << -1;
    else std::cout << distances[end];

    return 0;

}
