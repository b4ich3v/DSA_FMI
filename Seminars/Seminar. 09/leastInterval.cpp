#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <queue>

class Solution 
{
public:

    int leastInterval(std::vector<char>& tasks, int n) 
    {

        std::unordered_map<char, int> taskCount;
        for (char task : tasks) taskCount[task]++;

        std::priority_queue<int> q;
        for (const auto& current : taskCount) q.push(current.second);

        int time = 0;
        std::queue<std::pair<int, int>> waitQueue;

        while (!q.empty() || !waitQueue.empty()) 
        {

            time += 1;

            if (!waitQueue.empty() && waitQueue.front().second == time)
            {

                q.push(waitQueue.front().first);
                waitQueue.pop();

            }
            if (!q.empty())
            {

                int freq = q.top();
                q.pop();
                if (freq > 1) waitQueue.push({ freq - 1, time + n + 1 });

            }

        }

        return time;

    }

};

