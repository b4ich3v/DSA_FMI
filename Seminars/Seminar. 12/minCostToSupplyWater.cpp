#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

struct Edge 
{
public:

	int from = 0;
	int to = 0;
	int weight = 0;

};

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

	void unionTwoComponets(int first, int second) 
	{

		int firstParent = getParent(first);
		int secondParent = getParent(second);

		if (firstParent == secondParent) return;
		if (sizes[firstParent] < sizes[secondParent]) std::swap(firstParent, secondParent);

		parents[secondParent] = firstParent;
		sizes[firstParent] += sizes[secondParent];

	}

};

bool pred(const std::vector<int>& p1, const std::vector<int>& p2) 
{

	return p1[2] < p2[2];

}

class Solution 
{
public:

	int minCostToSupplyWater(int n, std::vector<int>& wells, std::vector<std::vector<int>>& pipes) 
	{
		
		for (int i = 1; i <= n; i++) pipes.push_back({ 0, i, wells[i - 1] });

		std::sort(pipes.begin(), pipes.end(), pred);

		UnionFind uf(n + 1);
		int counter = 0;
		int result = 0;

		for (int i = 0; i < pipes.size(); i++)
		{

			if (uf.areInOneSet(pipes[i][0], pipes[i][1])) continue;

			counter += 1;
			result += pipes[i][2];

			if (counter == n) break;

		}

		return result;

	}

};
