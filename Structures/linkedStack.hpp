#ifndef LINKED_STACK_HPP
#define LINKED_STACK_HPP
#include <stdexcept>

template <typename T>
struct StackElement 
{

    T data;
    StackElement* next;

};

template <typename T>
class LinkedStack 
{
private:
  
    StackElement<T>* top;

    void copy(LinkedStack const& ls) 
    {

        if (ls.empty())  top = nullptr;    
        else 
        {
           
            top = new StackElement<T>{ ls.top->data, nullptr };
            StackElement<T>* toCopy = ls.top->next, * lastCopied = top;

            while (toCopy != nullptr) 
            {

                lastCopied->next = new StackElement<T>{ toCopy->data, nullptr };
                toCopy = toCopy->next;
                lastCopied = lastCopied->next;

            }

        }

    }

    void erase() 
    {

        while (!empty())  pop();
           
    }

public:

    LinkedStack() : top(nullptr) {}

    LinkedStack(LinkedStack const& ls) : top(nullptr) 
    {

        copy(ls);

    }

    LinkedStack& operator=(LinkedStack const& ls) 
    {

        if (this != &ls) 
        {

            erase();
            copy(ls);

        }

        return *this;

    }

    LinkedStack(LinkedStack&& rs) noexcept : top(rs.top) 
    {

        rs.top = nullptr;

    }

    LinkedStack& operator=(LinkedStack&& rs) noexcept 
    {

        if (this != &rs) 
        {

            erase();

            top = rs.top;
            rs.top = nullptr;

        }

        return *this;

    }

    ~LinkedStack() 
    {

        erase();

    }

    bool empty() const 
    {

        return top == nullptr;

    }

    void push(T const& x) 
    {

        top = new StackElement<T>{ x, top };

    }

    T pop() 
    {

        if (empty()) throw std::runtime_error("Error");
           
        const StackElement<T>* const toDelete = top;
        const T result = peek();
        top = top->next;
        delete toDelete;
        return result;

    }

    T const& peek() const
    {

        if (empty()) throw std::runtime_error("Error");
        return top->data;

    }

    T& peek() 
    {

        if (empty()) throw std::runtime_error("Error");
        return top->data;

    }

};

#endif 
