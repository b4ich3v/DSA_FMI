#include <vector>
#include <iostream>
#include <queue>
#include <set>

class Solution 
{
public:

    bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int indexDiff, int valueDiff)
    {

        if (indexDiff <= 0 || valueDiff < 0) return false;

        std::set<long> window;

        for (int i = 0; i < nums.size(); i++) 
        {
         
            long num = (long)nums[i]; 

  
            auto lower = window.lower_bound(num - (long)valueDiff);  
            if (lower != window.end() && *lower <= num + valueDiff)  return true;

            window.insert(num); 
           
            if (i >= indexDiff) window.erase((long)nums[i - indexDiff]);

        }

        return false; 

    }

};

