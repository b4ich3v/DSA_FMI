#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int binarySearch(const std::vector<int>& array, int left, int right, int target)
{

    while (left <= right)
    {

        int middle = left + (right - left) / 2;

        if (array[middle] > target) right = middle - 1;
        else if (array[middle] < target) left = middle + 1;
        else return middle;

    }

    return -1;

}

int findPivot(const std::vector<int>& array)
{

    int left = 0;
    int right = array.size() - 1;

    while (left < right) 
    {

        int middle = left + (right - left) / 2;

        if (middle < right && array[middle] > array[middle + 1]) return middle;
        if (left < middle && array[middle] < array[middle - 1]) return middle - 1;

        if (array[left] == array[middle] && array[middle] == array[right]) { left++; right--; }
        else if (array[left] <= array[middle]) left = middle + 1;
        else right = middle - 1;

    }

    return -1;

}

int main() 
{
    
    int N = 0;
    int Q = 0;
    std::cin >> N;

    std::vector<int> array(N);
    for (int i = 0; i < N; i++) std::cin >> array[i];

    std::cin >> Q;
    std::vector<int> targets(Q);
    for (int i = 0; i < Q; i++) std::cin >> targets[i];

    int pivotIndex = findPivot(array);
    
    for (int i = 0; i < Q; i++)
    {

        int target = targets[i];
        int result = -1;

        if (pivotIndex == -1)  result = binarySearch(array, 0, N - 1, target);
        else
        {
            
            if (target >= array[0])  result = binarySearch(array, 0, pivotIndex, target);
            else result = binarySearch(array, pivotIndex + 1, N - 1, target);

        }

        std::cout << result << std::endl;

    }

    return 0;

}
