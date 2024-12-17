#include <cmath>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

class Solution 
{
public:

    int findCelebrity(int n) 
    {

        int potentialCelebrity = 0;

        for (int i = 1; i < n; i++) 
        {

            if (knows(potentialCelebrity, i)) potentialCelebrity = i;

        }

        return isCelebrity(potentialCelebrity, n) ? potentialCelebrity : -1;

    }

    bool isCelebrity(int current, int n) 
    {

        for (int i = 0; i < n; i++)
        {

            if (i != current && (!knows(i, current) || knows(current, i))) return false;

        }

        return true;

    }

};
