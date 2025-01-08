#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>


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

class Solution 
{
public:

    int findCircleNum(std::vector<std::vector<int>>& isConnected)
    {

        int countOfNodes = isConnected.size();
        UnionFind uf(countOfNodes);

        int result = countOfNodes;

        for (int i = 0; i < countOfNodes; i++)
        {

            for (int j = 0; j < countOfNodes; j++)
            {

                if (isConnected[i][j] == 1 && !uf.areInOneSet(i, j))
                {

                    uf.unionTwoComponents(i, j);
                    result -= 1;

                }

            }

        }

        return result;

    }

};
