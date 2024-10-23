#include <iostream>
#include <vector>
#include <algorithm>

int main() 
{

    int N, K;
    std::cin >> N >> K;

    std::vector<int> times(K);

    for (int i = 0; i < K; i++) std::cin >> times[i];

    long long left = 1;
    long long right = (long long)*std::min_element(times.begin(), times.end()) * N;
    long long answer = right;

    while (left <= right) 
    {

        long long mid = left + (right - left) / 2;
        long long pancakesMade = 0;

        for (int i = 0; i < K; i++) 
        {

            pancakesMade += mid / times[i];
            if (pancakesMade >= N) break;

        }

        if (pancakesMade >= N) { answer = mid; right = mid - 1; }
        else left = mid + 1;

    }

    std::cout << answer << std::endl;
    return 0;

}
