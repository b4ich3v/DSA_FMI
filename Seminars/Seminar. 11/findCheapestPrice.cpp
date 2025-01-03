#include <cmath>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

class Solution 
{
public:

    int findCheapestPrice(int n, std::vector<std::vector<int>>& flights, int start, int end, int k) 
    {

        std::vector<int> distances(n, INT_MAX);
        distances[start] = 0;

        for (int i = 0; i <= k; i++)
        {

            std::vector<int> row(distances);

            for (const auto& current : flights) 
            {

                if (distances[current[0]] != INT_MAX) 
                {

                    row[current[1]] = std::min(row[current[1]], distances[current[0]] + current[2]);

                }

            }

            distances = std::move(row);

        }

        if (distances[end] == INT_MAX) return -1;
        else return distances[end];

    }

};
