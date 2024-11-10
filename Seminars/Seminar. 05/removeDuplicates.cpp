#include <string>
#include <stack>
#include <algorithm>

class Solution 
{
public:

    std::string removeDuplicates(std::string str)
    {

        std::stack<char> st;

        for (char ch : str) 
        {

            if (!st.empty() && st.top() == ch) st.pop();
            else st.push(ch);

        }

        std::string result = "";

        while (!st.empty())
        {

            result += st.top();
            st.pop();

        }

        std::reverse(result.begin(), result.end());
        return result;
    }
};
