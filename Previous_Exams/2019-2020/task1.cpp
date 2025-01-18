
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <climits>

int main() 
{

	int N = 0;
	int M = 0;
	std::cin >> N >> M;

	std::vector<std::vector<int>> matrix(N, std::vector<int>(N, INT_MAX));

	for (int i = 0; i < M; i++)
	{

		int x = 0;
		int y = 0;
		int w = 0;
		std::cin >> x >> y >> w;

		matrix[y][x] = w;
		matrix[x][y] = w;

	}

	int K = 0;
	std::cin >> K;

	std::vector<int> array(K);

	for (int i = 0; i < K; i++) std::cin >> array[i];

	int result = 0;
	int index = 0;
	bool error = false;

	while (index + 1 < K)
	{

		int x = array[index];
		int y = array[index + 1];

		if (matrix[x][y] != INT_MAX) result += matrix[x][y];
		else { error = true; break; }

		index += 1;

	}

	if (error) std::cout << -1;
	else std::cout << result;

	return 0;

}
