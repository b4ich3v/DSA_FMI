#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iostream>
#include <climits>
#include <algorithm>

class UnionFind
{
private:

    std::vector<int> parents;
    std::vector<int> sizes;

    int getParent(int node)
    {

        if (parents[node] == node) return node;
        else return parents[node] = getParent(parents[node]);

    }

public:

    UnionFind(int size) : parents(size), sizes(size)
    {

        for (int i = 0; i < size; i++)
        {

            parents[i] = i;
            sizes[i] = 1;

        }

    }

    bool areInOneSet(int first, int second)
    {

        return getParent(first) == getParent(second);

    }

    void unionTwoComponents(int first, int second)
    {

        int firstParent = getParent(first);
        int secondParent = getParent(second);

        if (firstParent == secondParent) return;
        if (sizes[firstParent] < sizes[secondParent]) std::swap(firstParent, secondParent);

        parents[secondParent] = firstParent;
        sizes[firstParent] += sizes[secondParent];

    }

};

struct Edge
{
public:

    int from = 0;
    int to = 0;
    int weight = 0;

};

bool pred(const Edge& e1, const Edge& e2)
{

    return e1.weight > e2.weight;

}

int main()
{

    int N = 0;
    int M = 0;
    std::cin >> N >> M;

    UnionFind uf(N + 1);
    int counter = N;
    int hour = 0;

    for (int i = 0; i < M; i++)
    {

        int node1 = 0;
        int node2 = 0;
        std::cin >> node1 >> node2;

        if (uf.areInOneSet(node1, node2)) continue;

        uf.unionTwoComponents(node1, node2);
        counter -= 1;

        if (counter == 1)
        {

            hour = i + 1;
            break;

        }

    }

    if (counter == 1) std::cout << hour;
    else std::cout << -1;

    return 0;

}
