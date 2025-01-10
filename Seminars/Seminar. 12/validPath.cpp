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

    UnionFind(int size): parents(size), sizes(size) 
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

class Solution 
{
public:

    bool validPath(int n, std::vector<std::vector<int>>& edges, int source, int destination) 
    {

        UnionFind uf(n);
        for (const auto& current : edges) uf.unionTwoComponents(current[0], current[1]);
        return uf.areInOneSet(source, destination);

    }

};
