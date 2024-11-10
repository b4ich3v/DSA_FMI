#include <string>
#include <stack>
#include <algorithm>

class Solution
{
public:

    std::string stackToString(std::stack<char> st) 
    {

        std::string result("");

        while (!st.empty())
        {

            result += st.top();
            st.pop();

        }

        std::reverse(result.begin(), result.end());
        return result;

    }

    bool backspaceCompare(std::string s, std::string t)
    {

        std::stack<char> s1;
        std::stack<char> s2;

        for (char ch : s) 
        {

            if (ch != '#') s1.push(ch);
            else
            {

                if (s1.empty()) continue;
                else s1.pop();

            }

        }

        for (char ch : t)
        {

            if (ch != '#') s2.push(ch);
            else
            {

                if (s2.empty()) continue;
                else s2.pop();

            }

        }

        return stackToString(s1) == stackToString(s2);

    }

};
