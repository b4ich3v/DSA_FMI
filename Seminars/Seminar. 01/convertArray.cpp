#include <vector>
#include <algorithm>

class Solution
{
public:

    std::vector<std::vector<int>> findMatrix(std::vector<int>& nums)
    {
        
        int max_num = *std::max_element(nums.begin(), nums.end());
        std::vector<int> count(max_num + 1, 0); 

        for (int num : nums)
        {

            count[num]++;

        }

        std::vector<std::vector<int>> result;

        while (true)
        {

            std::vector<int> row;

            for (int i = 0; i <= max_num; i++)
            {

                if (count[i] > 0)
                {

                    row.push_back(i);
                    count[i]--; 

                }

            }

            if (row.empty())
            {

                break;

            }

            result.push_back(row);  

        }

        return result;

    }

};



