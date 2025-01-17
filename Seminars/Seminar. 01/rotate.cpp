#include <iostream>
#include <stack>
#include <vector>

class Solution 
{
public:

    void rotate(std::vector<int>& nums, int k) 
    {

        k = k % nums.size();
        std::stack<int> st;
        std::stack<int> helperSt;

        for (int i = nums.size() - 1; i >= nums.size() - k; i--) st.push(nums[i]);

        while (!st.empty()) 
        {

            helperSt.push(st.top());
            st.pop();

        }

        for (int i = 0; i <= nums.size() - k - 1; i++) helperSt.push(nums[i]);

        std::vector<int> result;

        while (!helperSt.empty()) 
        {

            result.push_back(helperSt.top());
            helperSt.pop();

        }

        std::reverse(result.begin(), result.end());
        nums.clear();
        nums = result;

    }

};

