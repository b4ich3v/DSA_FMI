#include <vector>
#include <queue>
#include <iostream>
#include <deque>
#include <limits.h>

class MaxQueue
{
private:

    std::queue<int> dataQueue;  
    std::deque<int> maxQueue;   

public:

    MaxQueue() {}

    void push(int val)
    {

        dataQueue.push(val);

        while (!maxQueue.empty() && maxQueue.back() < val) maxQueue.pop_back();
        maxQueue.push_back(val);

    }

    void pop()
    {

        if (dataQueue.front() == maxQueue.front()) maxQueue.pop_front();
        dataQueue.pop();

    }

    int front()
    {

        return dataQueue.front();

    }

    int getMax()
    {

        return maxQueue.front();

    }

};

class Solution
{
public:

    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k)
    {

        MaxQueue q;
        std::vector<int> result;
  
        for (int i = 0; i < k; i++) q.push(nums[i]);
      
        result.push_back(q.getMax());

        for (int i = k; i < nums.size(); i++)
        {
            q.pop();          
            q.push(nums[i]); 
            result.push_back(q.getMax()); 

        }

        return result;

    }

};
