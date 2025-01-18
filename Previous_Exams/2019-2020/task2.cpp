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
	std::cin >> N;

	std::vector<int> array(N);

	for (int i = 0; i < N; i++) std::cin >> array[i];

	int	Q = 0;
	std::cin >> Q;

	for (int i = 0; i < Q; i++)
	{

		int number = 0;
		std::cin >> number;

		auto left = std::lower_bound(array.begin(), array.end(), number);
		int position1 = left - array.begin();

		if (std::binary_search(array.begin(), array.end(), number))
		{

			auto right = std::upper_bound(array.begin(), array.end(), number);
			int position2 = (right - array.begin()) - 1;

			std::cout << position1 << " " << position2 << std::endl;

		}
		else
		{
			
			std::cout << position1 << std::endl;

		}

	}

	return 0;

}
