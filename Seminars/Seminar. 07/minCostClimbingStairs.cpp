#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
#include <queue>

class Solution
{
public:

    int minCostClimbingStairs(std::vector<int>& cost)
    {

        int size = cost.size();


        int prev2 = 0; 
        int prev1 = 0; 

        for (int i = 2; i <= size; i++) 
        {
            
            int current = std::min(prev1 + cost[i - 1], prev2 + cost[i - 2]);
            prev2 = prev1;
            prev1 = current;

        }

        return prev1;

    }

};

