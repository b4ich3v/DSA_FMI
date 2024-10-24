#include <iostream>
#include <vector>
#include <algorithm>

class Solution 
{
public:

	void printSpecialSorted(const std::vector<int>& arr)
	{

		int N = arr.size();
		int K = *max_element(arr.begin(), arr.end()) + 1;
		std::vector<int> counter(K, 0);

		for (int i = 0; i < N; i++) counter[arr[i]]++;

		while (true)
		{

			bool hasElements = false;

			for (int i = 0; i < K; i++)
			{

				if (counter[i] != 0)
				{

					std::cout << i << " ";
					counter[i]--;
					hasElements = true;

				}

			}

			if (!hasElements) break;
			std::cout << std::endl;

		}

	}

};


