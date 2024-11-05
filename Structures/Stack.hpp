#include <stdexcept>

template <typename T>
class Stack 
{
public:
   
    static const size_t MAX = 100;
    static const int EMPTY_STACK = -1;

private:

    T data[MAX];

    int top;

    bool full() const 
    {

        return top == MAX - 1;

    }

public:

    Stack() : top(EMPTY_STACK) {}

    bool empty() const 
    {

        return top == EMPTY_STACK;

    }

    void push(T const& x) 
    {

        if (full()) throw std::runtime_error("Error");  
        data[++top] = x;

    }

    T pop() 
    {

        if (empty()) throw std::runtime_error("Error");
        return data[top--];

    }

    T const& peek() const 
    {

        if (empty()) throw std::runtime_error("Error");
        return data[top];

    }

};
