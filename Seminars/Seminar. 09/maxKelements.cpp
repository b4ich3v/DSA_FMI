#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

class Solution 
{
public:

    long long maxKelements(std::vector<int>& nums, int k) 
    {

        std::priority_queue<long long> q;
        for (const auto& current : nums) q.push(current);

        int counter = 0;
        long long result = 0;

        while (!q.empty())
        {

            counter += 1;
            long long number = q.top();
            result += number;

            q.pop();
            number = (number  + 2) / 3;
            q.push(number);
            if (counter == k) break;

        }

        return result;
        
    }

};
