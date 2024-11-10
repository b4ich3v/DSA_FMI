#include <string>
#include <stack>
#include <iostream>
#include <vector>


class Solution
{
public:

    int maxDepth(std::string s)
    {

        int currentDepth = 0;
        int maxDepth = 0;

        for (char ch : s)
        {

            if (ch == '(')
            {

                currentDepth++;
                maxDepth = std::max(maxDepth, currentDepth);

            }
            else if (ch == ')')
            {

                currentDepth--;

            }

        }

        return maxDepth;

    }

};

