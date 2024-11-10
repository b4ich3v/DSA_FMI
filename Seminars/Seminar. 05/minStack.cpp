#include <vector>
#include <deque>
#include <iostream>
#include <stack>
#include <limits.h>

class MinStack 
{
private:

    std::stack<int> dataStack; 
    std::stack<int> minStack;  

public:

    MinStack() 
    {
        
        minStack.push(INT_MAX);

    }

    void push(int val)
    {

        dataStack.push(val);
        minStack.push(std::min(val, minStack.top()));

    }

    void pop()
    {

        dataStack.pop();
        minStack.pop(); 

    }

    int top() 
    {

        return dataStack.top();

    }

    int getMin() 
    {

        return minStack.top();

    }

};

