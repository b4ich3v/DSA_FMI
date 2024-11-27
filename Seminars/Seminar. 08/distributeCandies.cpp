#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

class Solution 
{
public:

    int distributeCandies(std::vector<int>& candyType) 
    {

        std::unordered_set<int> s;
        for (const auto& current : candyType) s.insert(current);
        return std::min(candyType.size() / 2, s.size());

    }

};
