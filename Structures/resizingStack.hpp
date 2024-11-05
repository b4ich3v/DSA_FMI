#include <stdexcept>

template <typename T>
class ResizingStack 
{
public:
    
    static const size_t INITIAL_CAPACITY = 10;
    static const int EMPTY_STACK = -1;

private:

    T* data;
    int top;
    size_t capacity;

    bool full() const 
    {

        return top == capacity - 1;

    }

    void copyData(const T* const other_data) 
    {

        for (int i = 0; i <= top; i++)
            data[i] = other_data[i];

    }

    void copy(ResizingStack const& rs)
    {

        top = rs.top;
        capacity = rs.capacity;
        data = new T[capacity];
        copyData(rs.data);

    }

    void resize() 
    {

        capacity *= 2;
        std::clog << "... " << capacity << std::endl;
        const T* const old_data = data;
        data = new T[capacity];
        copyData(old_data);
        delete[] old_data;

    }
public:

    ResizingStack() : top(EMPTY_STACK), capacity(INITIAL_CAPACITY)
    {

        data = new T[capacity];

    }

    ResizingStack(ResizingStack const& rs) 
    {

        copy(rs);

    }

    ResizingStack& operator=(ResizingStack const& rs) 
    {

        if (this != &rs) 
        {

            delete[] data;
            copy(rs);

        }

        return *this;

    }

    ResizingStack(ResizingStack&& rs) noexcept
        : top(rs.top), capacity(rs.capacity), data(rs.data) 
    {

        rs.top = EMPTY_STACK;
        rs.capacity = INITIAL_CAPACITY;
        rs.data = nullptr;

    }

    ResizingStack& operator=(ResizingStack&& rs) noexcept
    {

        if (this != &rs) 
        {

            delete[] data;

            top = rs.top;
            capacity = rs.capacity;
            data = rs.data;

            rs.top = EMPTY_STACK;
            rs.capacity = INITIAL_CAPACITY;
            rs.data = nullptr;

        }

        return *this;

    }

    ~ResizingStack() 
    {

        delete[] data;

    }

    bool empty() const 
    {

        return top == EMPTY_STACK;

    }

    void push(T const& x) 
    {

        if (full())
            resize();
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
