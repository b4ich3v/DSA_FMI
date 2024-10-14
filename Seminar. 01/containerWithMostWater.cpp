#include <iostream>
#include <vector>
#include <algorithm>

class Solution 
{
public:

    int maxArea(std::vector<int>& heights) 
    {

        int leftIndex = 0;
        int rightIndex = heights.size() - 1;
        int max = std::min(heights[leftIndex], heights[rightIndex]) * (rightIndex - leftIndex);

        while (leftIndex < rightIndex) 
        {

            int currentMax = std::min(heights[leftIndex], heights[rightIndex]) * (rightIndex - leftIndex);
            max = std::max(max, currentMax);

            if (heights[leftIndex] > heights[rightIndex]) 
            {

                rightIndex--;

            }
            else 
            {

                leftIndex++;

            }

        }

        return max;

    }

};
