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
        else  return middle;

    }

    return -1;

}

int pivotIndex(const std::vector<int>& array) 
{

    int left = 0;
    int right = array.size() - 1;

    while (left < right)
    {

        int middle = left + (right - left) / 2; 

        if (middle < right && array[middle] > array[middle + 1]) return middle;
        if (middle > left && array[middle] < array[middle - 1]) return middle - 1;

        if (array[left] == array[middle] && array[middle] == array[right]) { left++, right--; }
        else if (array[middle] > array[left]) left = middle + 1;
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
    for (int i = 0; i < Q; i++)
    {

        int currentNumber = 0;
        std::cin >> currentNumber;

        int index = pivotIndex(array);

        if (index == -1) std::cout << binarySearch(array, 0, array.size() - 1, currentNumber) << std::endl;
        else
        {

            if (currentNumber >= array[0]) std::cout << binarySearch(array, 0, index - 1, currentNumber) << std::endl;
            else std::cout << binarySearch(array, index, array.size() - 1, currentNumber) << std::endl;
           
        }

    }

    return 0;

}
