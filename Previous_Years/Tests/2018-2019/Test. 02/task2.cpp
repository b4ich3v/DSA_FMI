#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int binarySearch(const std::vector<int>& array, int target, int& counter) 
{

    int left = 0;
    int right = array.size() - 1;

    while (left <= right) 
    {

        int middle = left + (right - left) / 2;

        if (array[middle] > target) right = middle - 1;
        else if (array[middle] < target) left = middle + 1;
        else return middle;

        counter++;

    }

    return -1;

}

int main() 
{
    
    int N = 0;
    int K = 0;
    std::cin >> N;

    std::vector<int> array(N);
    for (int i = 0; i < N; i++) std::cin >> array[i];

    std::cin >> K;
    std::vector<int> targets(K);
    for (int i = 0; i < K; i++) std::cin >> targets[i];

    std::vector<int> indexes(K);
    std::vector<int> count(K);

    for (int i = 0; i < K; i++)
    {

        int currentTarget = targets[i];
        int counter = 1;

        indexes[i] = binarySearch(array, targets[i], counter);
        if (indexes[i] == -1) counter--;
        count[i] = counter;

    }

    for (int i = 0; i < K; i++) std::cout << indexes[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i < K; i++) std::cout << count[i] << " ";

    return 0;

}

