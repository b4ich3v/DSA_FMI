#include <vector>
#include <deque>
#include <iostream>
#include <stack>
#include <limits.h>

class MaxStack 
{
private:

    std::stack<int> dataStack; 
    std::stack<int> maxStack;  

public:

    MaxStack() 
    {
        
        maxStack.push(INT_MIN);

    }

    void push(int val)
    {

        dataStack.push(val);
        maxStack.push(std::max(val, maxStack.top()));

    }

    void pop()
    {

        dataStack.pop();
        maxStack.pop(); 

    }

    int top() 
    {

        return dataStack.top();

    }

    int getMin() 
    {

        return maxStack.top();

    }

};

