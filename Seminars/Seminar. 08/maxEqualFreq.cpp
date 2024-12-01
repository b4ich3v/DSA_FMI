#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <algorithm>

class Solution 
{
public:

    int maxEqualFreq(std::vector<int>& nums) 
    {

        int max = 0;
        std::unordered_map<int, int> freqCount;
        std::unordered_map<int, int> numberFreq;
        int result = 0;

        for (int i = 0; i < nums.size(); i++) 
        {

            int& freq = numberFreq[nums[i]];

            if (freqCount.count(freq)) freqCount[freq]--;
            
            freq += 1;

            freqCount[freq]++;
            max = std::max(max, freq);

            if (
                max == 1 ||
                (freqCount[1] == 1 && max * freqCount[max] == i) ||
                (freqCount[max] == 1 && (max - 1) * (freqCount[max - 1] + 1) == i)
                ) 
            {

                result = i + 1;

            }

        }

        return result;

    }

};
