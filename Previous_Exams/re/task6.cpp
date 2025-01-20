#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

class UnionFind
{
private:

    std::vector<long long> parents;
    std::vector<long long> sizes;
    
    long long getParent(long long node)
    {

        if (parents[node] == node) return node;
        else return parents[node] = getParent(parents[node]);

    }

public:

    UnionFind(long long size) : parents(size), sizes(size)
    {

        for (long long i = 0; i < size; i++)
        {

            parents[i] = i;
            sizes[i] = 1;

        }

    }

    bool areInOneSet(long long first, long long second)
    {

        return getParent(first) == getParent(second);

    }

    void unionTwo(long long first, long long second)
    {

        long long firstParent = getParent(first);
        long long secondParent = getParent(second);

        if (firstParent == secondParent) return;
        if (sizes[firstParent] < sizes[secondParent]) std::swap(firstParent, secondParent);

        parents[secondParent] = firstParent;
        sizes[firstParent] += sizes[secondParent];

    }

};

struct Edge 
{
public:

    long long from;
    long long to;
    long long weight;

};

bool pred(const Edge& e1, const Edge& e2)
{

    return e1.weight > e2.weight;

}

long long kruskal(long long N, std::vector<Edge>& edges)
{

    std::sort(edges.begin(), edges.end(), pred);

    UnionFind uf(N + 1);
    long long result = 0;
    long long counter = 0;

    for (long long i = 0; i < edges.size(); i++)
    {

        if (uf.areInOneSet(edges[i].from, edges[i].to)) continue;

        uf.unionTwo(edges[i].from, edges[i].to);
        result += edges[i].weight;
        counter += 1;

        if (counter == N - 1) break;

    }

    return result;

}

int main() 
{
    
    long long N = 0;
    long long M = 0;
    std::cin >> N >> M;

    std::vector<Edge> edges;
    long long countOfAllRibs = 0;

    for (long long i = 0; i < M; i++)
    {

        long long x = 0;
        long long y = 0;
        long long w = 0;
        std::cin >> x >> y >> w;

        edges.push_back({ x,y,w });
        countOfAllRibs += w;

    }

    long long resultForMaxTree = kruskal(N, edges);
    std::cout << countOfAllRibs - resultForMaxTree;

    return 0;

}
