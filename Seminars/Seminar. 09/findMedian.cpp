#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

class MedianFinder 
{
public:

    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    std::priority_queue<int, std::vector<int>, std::less<int>> maxHeap;

    void addNum(int num)
    {

        if (minHeap.size() == 0 || minHeap.top() < num) minHeap.push(num);
        else maxHeap.push(num);

        if (maxHeap.size() > minHeap.size() + 1) 
        {

            minHeap.push(maxHeap.top());
            maxHeap.pop();

        }
        else if (minHeap.size() > maxHeap.size() + 1)
        {

            maxHeap.push(minHeap.top());
            minHeap.pop();

        }

    }

    double findMedian() 
    {

        if (maxHeap.size() == minHeap.size()) return (maxHeap.top() + minHeap.top()) / 2.0;
        else return maxHeap.size() > minHeap.size() ? maxHeap.top() : minHeap.top();

    }

};
