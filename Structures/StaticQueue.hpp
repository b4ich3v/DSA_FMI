#ifndef SQUEUE_HPP
#define SQUEUE_HPP
#include <stdexcept>

template <typename T>
class StaticQueue 
{
public:

        static const size_t MAX = 100;

private:
    
    T data[MAX];
    int front, back;

public:

    StaticQueue() : front(0), back(-1) {}

    bool empty() const 
    {

        return (back + 1) % MAX == front;

    }

    bool full() const 
    {

        return (back + 2) % MAX == front;

    }

    void enqueue(T const& x) 
    {

        if (full()) throw std::runtime_error("Error");
        data[++back %= MAX] = x;

    }

    T dequeue()
    {

        if (empty()) throw std::runtime_error("Error");
            
        T const& result = data[front];
        ++front %= MAX;
        return result;

    }

    T const& head() const 
    {

        if (empty()) throw std::runtime_error("Error");
        return data[front];

    }

};

#endif 
