#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

struct comparator
{

    bool operator()(const std::vector<int>& v1, const std::vector<int>& v2) 
    {

        return v1[0] * v1[0] + v1[1] * v1[1] > v2[0] * v2[0] + v2[1] * v2[1];

    }

};

class Solution
{
public:

    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) 
    {

        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, comparator> q;
        for (const auto& current : points) q.push(current);
        
        std::vector<std::vector<int>> result;
        
        int counter = 0;

        while (!q.empty())
        {

            counter += 1;
            result.push_back(q.top());
            q.pop();
            if (counter == k) break;

        }

        return result;

    }

};
