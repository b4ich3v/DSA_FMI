#include <cmath>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

struct Edge
{

    int from;
    int to;
    int weight;

};

class UnionFind
{
private:

    std::vector<int> parentsContainer;
    std::vector<int> sizes;

    int getParent(int node)
    {

        if (parentsContainer[node] == node) return node;
        return parentsContainer[node] = getParent(parentsContainer[node]);

    }

public:

    UnionFind(int countOfNodes) : parentsContainer(countOfNodes), sizes(countOfNodes)
    {

        for (int i = 0; i < countOfNodes; i++)
        {

            parentsContainer[i] = i;
            sizes[i] = 1;

        }

    }

    bool areInOneSet(int first, int second)
    {

        return getParent(first) == getParent(second);

    }

    void unionVertices(int first, int second)
    {

        int parentOfFirst = getParent(first);
        int parentOfSecond = getParent(second);

        if (parentOfFirst == parentOfSecond) return;

        if (sizes[parentOfFirst] < sizes[parentOfSecond]) std::swap(parentOfFirst, parentOfSecond);

        parentsContainer[parentOfSecond] = parentOfFirst;
        sizes[parentOfFirst] += sizes[parentOfSecond];

    }

};

int main() 
{
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N = 0;
    int M = 0;
    std::cin >> N >> M;
    
    std::vector<Edge> edges;

    UnionFind uf(N);
    int counter = 0;

    for (int i = 0; i < M; i++)
    {

        int node1 = 0;
        int node2 = 0;
        std::cin >> node1 >> node2;

        edges.push_back({ node1, node2, 1 });

    }

    for (int i = 0; i < M; i++)
    {

        if (uf.areInOneSet(edges[i].from, edges[i].to)) continue;

        uf.unionVertices(edges[i].from, edges[i].to);
        counter += 1;
        
        if (counter == N - 1) break;

    }

    int K = 0;
    std::cin >> K;
    std::vector<std::pair<int, int>> pairs(K);

    for (int i = 0; i < K; i++)
    {

        std::cin >> pairs[i].first;
        std::cin >> pairs[i].second;

    }

    for (const auto& current : pairs)
    {

        std::cout << uf.areInOneSet(current.first, current.second) << " ";

    }

    return 0;

}
