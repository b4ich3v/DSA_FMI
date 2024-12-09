#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

class Solution
{
public:

    int lastStoneWeight(std::vector<int>& stones) 
    {

        std::priority_queue<int> q;
        for (const auto& current : stones) q.push(current);
        
        while (q.size() > 1) 
        {

            int h1 = q.top();
            q.pop();
            int h2 = q.top();
            q.pop();

            if (h1 < h2) q.push(h2 - h1); 
            else if(h1 > h2) q.push(h1 - h2);

        }


        if (q.empty()) return 0;
        else return q.top();

    }

};
