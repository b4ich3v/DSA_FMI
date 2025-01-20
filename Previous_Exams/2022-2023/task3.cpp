#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <set>

struct Node1
{
public:

	int startTime;
	int endTime;
	int index;

};

struct Node2
{
public:

	int endTime;
	int chairId;

	bool operator < (const Node2& other) const
	{

		return endTime > other.endTime;

	}

};

bool pred(const Node1& node1, const Node1& node2) 
{

	return node1.startTime < node2.startTime;

}

int main()
{

	int N = 0;
	std::cin >> N;

	std::vector<Node1> array(N);

	for (int i = 0; i < N; i++)
	{

		int timeA = 0;
		int timeB = 0;
		std::cin >> timeA >> timeB;

		array[i] = { timeA, timeB , i};

	}

	std::sort(array.begin(), array.end(), pred);

	int T = 0;
	int nextChair = 0;
	std::cin >> T;

	std::priority_queue<Node2> q;
	std::priority_queue<int, std::vector<int>, std::greater<int>> freeChairs;
	std::vector<int> chairsId(N, -1);

	for (int i = 0; i < N; i++)
	{

		while (!q.empty() && q.top().endTime <= array[i].startTime)
		{

			freeChairs.push(q.top().chairId);
			q.pop();

		}

		int chair = 0;

		if (!freeChairs.empty())
		{

			chair = freeChairs.top();
			freeChairs.pop();

		}
		else
		{

			chair = nextChair;
			nextChair += 1;

		}

		q.push({ array[i].endTime , chair});
		chairsId[array[i].index] = chair;
		
	}

	std::cout << chairsId[T];

	return 0;

}
