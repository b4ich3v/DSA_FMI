#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <map>

class Solution 
{
public:

    std::vector<int> nextGreaterElements(std::vector<int>& nums) 
    {

        std::vector<int> res(nums.size(), -1);
        std::stack<int> st;

        for (int i = 0; i < nums.size() * 2; i++)
        {

            int current = nums[i % nums.size()];

            while (!st.empty() && nums[st.top()] < current)
            {

                int index = st.top();
                st.pop();
                res[index] = current;

            }

            if (i < nums.size()) st.push(i);

        }

        return res;

    }

};

