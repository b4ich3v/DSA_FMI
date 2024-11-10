#include <string>
#include <stack>
#include <iostream>
#include <vector>

class Solution
{
public:

    std::vector<int> asteroidCollision(std::vector<int>& array) 
    {

        std::stack<int> st;

        for (int i = 0; i < array.size(); i++) 
        {

            if (array[i] > 0) st.push(array[i]);
            else
            {

                while (!st.empty() && st.top() > 0 && st.top() < std::abs(array[i])) st.pop();

                if (st.empty() || st.top() < 0) st.push(array[i]);
                else if (!st.empty() && st.top() == std::abs(array[i])) st.pop();

            }

        }

        std::vector<int>result;

        while (!st.empty())
        {

            result.push_back(st.top());
            st.pop();

        }

        std::reverse(result.begin(), result.end());
        return result;

    }
};
