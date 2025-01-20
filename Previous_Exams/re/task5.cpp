#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <set>

int main() 
{

	int K = 0;
	int T = 0;
	int B = 0;
	std::cin >> K >> T >> B;

	int N = 0;
	std::cin >> N;

	std::priority_queue<int, std::vector<int>, std::greater<int>> q;

	for (int i = 1; i <= N; i++)
	{

		int number = 0;
		std::cin >> number;
		q.push(number);

		if (i % T == 0 && B != 0) 
		{

			for (int j = 0; j < K && !q.empty(); j++)
			{

				std::cout << q.top() << " ";
				q.pop();

			}

			B -= 1;

		}

	}

	while (B) 
	{

		for (int i = 0; i < K && !q.empty(); i++)
		{

			std::cout << q.top() << " ";
			q.pop();

		}

		B -= 1;

	}

	return 0;

}
