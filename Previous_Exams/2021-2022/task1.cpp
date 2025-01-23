#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <algorithm>

int main() 
{

	int N = 0;
	int M = 0;
	std::cin >> N >> M;

	std::unordered_map<std::string, int> counter;

	for (int i = 0; i < N; i++)
	{

		std::string current;

		for (int j = 0; j < M; j++)
		{

			char ch = 'a';
			std::cin >> ch;
			current += ch;

		}

		counter[current] += 1;

	}

	int result = 0;

	for (const auto& current : counter)
	{

		if (current.second == 1) result += 1;

	}

	std::cout << result;
	return 0;

}
