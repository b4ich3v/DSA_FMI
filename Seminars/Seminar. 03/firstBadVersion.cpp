#include <iostream>
#include <vector>
#include <algorithm>

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution 
{
public:

    bool isBadVersion(int i) const { return true; }

    int firstBadVersion(int n)
    {

        int left = 1;
        int right = n;

        while (left < right) 
        {

            int middle = left + (right - left) / 2;

            if (isBadVersion(middle))  right = middle;
            else left = middle + 1;

        }

        return left; 

    }

};


