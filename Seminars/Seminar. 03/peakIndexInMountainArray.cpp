#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:

    static bool pred(const std::pair<int, int>& p1, const std::pair<int, int>& p2)
    {

        return p1.first > p2.first; 

    }

    int peakIndexInMountainArray(std::vector<int>& arr)
    {

        int size = arr.size();
        std::vector<std::pair<int, int>> newArr(size);

        for (int i = 0; i < size; i++) newArr[i] = { arr[i], i };
        std::sort(newArr.begin(), newArr.end(), pred);

        int peakIndex = newArr[0].second; 
        return peakIndex; 

    }

};


