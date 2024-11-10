#include <vector>
#include <queue>
#include <algorithm>

class Solution 
{
public:

    double findMaxAverage(std::vector<int>& nums, int k)
    {

        std::queue<double> q;
        double firstSum = 0;
        double max = 0;

        for (int i = 0; i < k; i++) { q.push(nums[i]); firstSum += nums[i]; }
        max = firstSum / k;

        double currentSum = firstSum;
        double current = 0;

        for (int i = k; i < nums.size(); i++)
        {

            currentSum += nums[i];
            currentSum -= q.front();
            q.pop();
            q.push(nums[i]);

            current = currentSum / k;
            max = std::max(max, current);

        }

        return max;

    }

};
