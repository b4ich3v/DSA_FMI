#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <queue>

class Solution 
{
public:

    int findJudge(int n, std::vector<std::vector<int>>& trust)
    {

        if (trust.size() < n - 1) return -1;

        std::vector<int> counter(n + 1, 0);

        for (auto& current : trust)
        {

            counter[current[0]]--;
            counter[current[1]]++;

        }

        for (int i = 1; i <= n; i++) 
        {

            if (counter[i] == n - 1) return i;

        }

        return -1;

    }

};

