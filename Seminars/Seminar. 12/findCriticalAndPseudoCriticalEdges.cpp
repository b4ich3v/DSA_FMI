#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <stack>
#include <string>

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

    bool areInOneSet(int left, int right) 
    {

        return getParent(left) == getParent(right);

    }

    void unionTwo(int left, int right) 
    {

        int parentLeft = getParent(left);
        int parentRight = getParent(right);

        if (parentLeft == parentRight) return;
        if (sizes[parentLeft] < sizes[parentRight]) std::swap(parentLeft, parentRight);

        parents[parentRight] = parentLeft;
        sizes[parentLeft] += sizes[parentRight];

    }

};

bool pred(const std::vector<int>& e1, const std::vector<int>& e2) 
{

    return e1[2] < e2[2];

}

class Solution 
{
public:

    std::vector<std::vector<int>> findCriticalAndPseudoCriticalEdges(int n, std::vector<std::vector<int>>& edges) 
    {

        for (int i = 0; i < edges.size(); i++) edges[i].push_back(i);

        std::sort(edges.begin(), edges.end(), pred);
        std::vector<std::vector<int>> result(2, std::vector<int>());

        UnionFind uf1(n);
        int componentsCount1 = n;
        int actualWeight = 0;

        for (int i = 0; i < edges.size(); i++)
        {

            if (uf1.areInOneSet(edges[i][0], edges[i][1])) continue;
            uf1.unionTwo(edges[i][0], edges[i][1]);
            actualWeight += edges[i][2];
            componentsCount1 -= 1;
            if (componentsCount1 == 1) break;

        }

        for (int i = 0; i < edges.size(); i++)
        {

            UnionFind uf2(n);
            int componentsCount2 = n;
            int currentWeight1 = 0;

            for (int j = 0; j < edges.size(); j++)
            {

                if(i == j || uf2.areInOneSet(edges[j][0], edges[j][1])) continue;
                uf2.unionTwo(edges[j][0], edges[j][1]);
                currentWeight1 += edges[j][2];
                componentsCount2 -= 1;
                if (componentsCount2 == 1) break;

            }

            if (currentWeight1 != actualWeight || componentsCount2 > 1) result[0].push_back(edges[i][3]);
            else
            {

                UnionFind uf3(n);
                uf3.unionTwo(edges[i][0], edges[i][1]);
                int componentsCount3 = n;
                int currentWeight2 = edges[i][2];

                for (int j = 0; j < edges.size(); j++)
                {

                    if (i == j || uf3.areInOneSet(edges[j][0], edges[j][1])) continue;
                    uf3.unionTwo(edges[j][0], edges[j][1]);
                    currentWeight2 += edges[j][2];
                    componentsCount3 -= 1;
                    if (componentsCount3 == 1) break;

                }

                if (currentWeight2 == actualWeight) result[1].push_back(edges[i][3]);

            }

        }

        return result;

    }

};
