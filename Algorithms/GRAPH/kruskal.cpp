#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

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

bool pred(const Edge& e1, const Edge& e2) 
{

    return e1.weight < e2.weight;

}

std::vector<Edge> kruskal(int countOfNodes, std::vector<Edge>& edges) 
{
    
    std::sort(edges.begin(), edges.end(), pred);

    UnionFind uf(countOfNodes);
    std::vector<Edge> mstEdges;

    for (int i = 0; i < edges.size(); i++) 
    {

        if (uf.areInOneSet(edges[i].from, edges[i].to)) continue;

        uf.unionVertices(edges[i].from, edges[i].to);
        mstEdges.push_back(edges[i]);

        if (mstEdges.size() == countOfNodes - 1) break;

    }

    return mstEdges;

}
