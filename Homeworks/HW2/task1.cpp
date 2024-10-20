#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

void binarySearch(const std::vector<int>& array, int target, bool& found) 
{

    int left = 0;
    int right = array.size() - 1;

    while (left <= right)
    {

        int middle = left + (right - left) / 2;

        if (array[middle] > target) right = middle - 1;
        else if (array[middle] < target) left = middle + 1;
        else { found = true; return; }

    }

    found = false;

}

int main()
{
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N = 0;
    int K = 0;

    std::cin >> N;
    std::cin >> K;

    std::vector<int> array(N);

    for (int i = 0; i < N; i++)
    {

        std::cin >> array[i];

    }

    std::sort(array.begin(), array.end());
    int counter = 0;

    for (int i = 0; i < N; i++)
    {

        bool found = false;
        binarySearch(array, array[i] - K, found);

        if (found) counter++;

    }

    std::cout << counter;

    return 0;

}
