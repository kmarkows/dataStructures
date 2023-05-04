#include <iostream>

template<typename T>
class Stack
{
    T* arr;
    int top;
    int size;

public:
    Stack(int givenSize)
    {
        arr = new T[givenSize];
        size = givenSize;
        top = 0;
    }

    ~Stack()
    {
        delete [] arr;
    }

    void push(T data)
    {
        if (isFull())
        {
            std::cout<<"stack overflow, unable to push data"<<std::endl;
            return;
        }
        arr[top] = data;
        top++;
    }

    void pop()
    {
        if (isEmpty())
        {
            std::cout<<"stack underflow, unable to pop data"<<std::endl;
            return;
        }
        top--;
    }

    bool isFull()
    {
        return top == size;
    }

    bool isEmpty()
    {
        return top == 0;
    }

    void print()
    {
        for (int i = 0; i < top; i++)
        {
            std::cout<<arr[i]<<" ";
        }
        std::cout<<std::endl;
    }

};
