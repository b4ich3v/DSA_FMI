#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

void addNum(int num, std::priority_queue<int>& maxHeap, std::priority_queue<int, std::vector<int>, std::greater<int>>& minHeap)
{

    maxHeap.push(num);

    if (!minHeap.empty() && maxHeap.top() > minHeap.top()) 
    {

        int temp = maxHeap.top();
        maxHeap.pop();
        minHeap.push(temp);

    }

    if (maxHeap.size() > minHeap.size() + 1) 
    {

        int temp = maxHeap.top();
        maxHeap.pop();
        minHeap.push(temp);

    }
    else if (minHeap.size() > maxHeap.size()) 
    {

        int temp = minHeap.top();
        minHeap.pop();
        maxHeap.push(temp);

    }

}

double findMedian(const std::priority_queue<int>& maxHeap, const std::priority_queue<int, std::vector<int>, std::greater<int>>& minHeap) 
{

    if (maxHeap.size() > minHeap.size()) 
    {

        return maxHeap.top(); 

    }
    else 
    {

        return (maxHeap.top() + minHeap.top()) / 2.0; 

    }

}

int main() 
{

    int N;
    std::cin >> N;

    std::priority_queue<int> maxHeap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    for (int i = 0; i < N; i++)
    {

        int number;
        std::cin >> number;

        addNum(number, maxHeap, minHeap);
        std::cout << findMedian(maxHeap, minHeap) << std::endl;

    }

    return 0;

}

