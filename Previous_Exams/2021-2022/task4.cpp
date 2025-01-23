#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <string>
#include <stack>

bool isEnough(long long time, std::vector<long long>& array, long long target)
{

	long long result = 0;
	long long size = array.size();

	for (long long i = 0; i < size; i++)
	{

		if (result >= target) return true;
		result += time / array[i];

	}

	return result >= target;

}

long long binarySearch(long long left, long long right, std::vector<long long>& array, long long target)
{

	long long result = 0;

	while (left <= right) 
	{

		int middle = left + (right - left) / 2;

		if (isEnough(middle, array, target)) 
		{

			right = middle - 1;
			result = middle;

		}
		else left = middle + 1;

	}

	return result;

}

int main() 
{

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	long long N = 0;
	long long K = 0;
	std::cin >> N >> K;

	std::vector<long long> array(K, 0);
	for (long long i = 0; i < K; i++) std::cin >> array[i];

	long long left = 0;
	long long right = *std::max_element(array.begin(), array.end()) * N;
	long long result = binarySearch(left, right, array, N);
	std::cout << result;

	return 0;

}
