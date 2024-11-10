#include <iostream>
#include <queue>
#include <vector>

int main()
{

	int N = 0;
	int K = 0;
	std::cin >> N;
	std::cin >> K;

	std::vector<int> arr(N);
	for (int i = 0; i < N; i++) std::cin >> arr[i];

	int maxSum = 0;
	std::queue<int> q;
	for (int i = 0; i < K; i++) { maxSum += arr[i]; q.push(arr[i]); }

	int currentSum = maxSum;
	for (int i = K; i < N; i++)
	{

		currentSum += arr[i];
		currentSum -= q.front();
		q.pop();
		q.push(arr[i]);
		maxSum = std::max(maxSum, currentSum);

	}

	std::cout << maxSum;
	return 0;

}
