#include <string>
#include <stack>

class Solution 
{
public:

    bool isValid(std::string str) 
    {

        int size = str.size();
        std::stack<char> s;

        for (char ch : str)
        {

            if (ch == '(' || ch == '[' || ch == '{') 
            {

                s.push(ch);

            }
            else
            {

                if (s.empty()) return false;

                char top = s.top();

                if (top == '(' && ch == ')') s.pop();
                else if (top == '[' && ch == ']') s.pop();
                else if (top == '{' && ch == '}') s.pop();
                else return false;

            }

        }

        return s.empty();

    }

};
