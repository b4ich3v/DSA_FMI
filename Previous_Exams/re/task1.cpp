#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <set>

int main() 
{

	int x = 0;
	int y = 0;
	std::cin >> x >> y;

	std::vector<int> firstArr(x);
	std::vector<int> secondArr(y);

	for (int i = 0; i < x; i++) std::cin >> firstArr[i];
	for (int i = 0; i < y; i++) std::cin >> secondArr[i];

	std::sort(firstArr.begin(), firstArr.end());

	for (int i = 0; i < y; i++)
	{

		auto iter = std::lower_bound(firstArr.begin(), firstArr.end(), secondArr[i]);
		int dist = std::distance(firstArr.begin(), iter);

		std::cout << dist << " ";

	}

	return 0;

}
