#include <iostream>
#include <vector>
#include <algorithm>

bool enough(const std::vector<long long>& array, long long time, long long N)
{

    long long counter = 0;
    long long size = array.size();

    for (long long i = 0; i < size; i++)
    {

        counter += time / array[i];
        if (counter >= N) return true;

    }

    return counter >= N;

}

long long calculateTime(const std::vector<long long>& array, long long N)
{

    long long left = 1;
    long long right = *max_element(array.begin(), array.end()) * N;
    long long neededTime = right;

    while (left <= right) 
    {

        long long middle = left + (right - left) / 2;

        if (enough(array, middle, N)) { neededTime = middle; right = middle - 1; }
        else left = middle + 1;

    }

    return neededTime;

}

int main() 
{

    long long N = 0;
    long long K = 0;

    std::cin >> N >> K;

    std::vector<long long> array(K);
    for (long long i = 0; i < K; i++) std::cin >> array[i];

    std::cout << calculateTime(array, N);

    return 0;

}
