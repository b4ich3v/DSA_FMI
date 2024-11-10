#include <string>
#include <stack>
#include <iostream>
#include <vector>

class Solution 
{
public:

    int evalRPN(std::vector<std::string>& tokens) 
    {

        int size = tokens.size();
        std::stack<std::string> st;

        for (int i = 0; i < size; i++) 
        {

            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") 
            {

                int num1 = stoi(st.top());
                st.pop();
                int num2 = stoi(st.top());
                st.pop();
                int answer = -1;

                if (tokens[i] == "+")  answer = num2 + num1;
                else if (tokens[i] == "-") answer = num2 - num1;
                else if (tokens[i] == "*") answer = num2 * num1;
                else answer = num2 / num1;

                std::string str = std::to_string(answer);
                st.push(str);

            }
            else
            {

                st.push(tokens[i]);

            }

        }

        int ans = stoi(st.top());
        return ans;

    }

};
