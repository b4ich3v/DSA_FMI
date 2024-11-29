#include <string>
#include <vector>
#include <unordered_map>

class Solution 
{
public:

    int findLength(std::vector<int>& nums1, std::vector<int>& nums2)
    {

        int rows = nums1.size();
        int cols = nums2.size();

        std::vector<std::vector<int>> dp(rows + 1, std::vector<int>(cols + 1, 0));
        int result = 0;

        for (int i = 1; i <= rows; i++) 
        {

            for (int j = 1; j <= cols; j++)
            {

                if (nums1[i - 1] == nums2[j - 1]) 
                {

                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    result = std::max(result, dp[i][j]);

                }

            }

        }

        return result;

    }

};
