#include <iostream>

template <typename T>
class MyVector
{
private:
    T* arr;
    int allocatedSize;
    int currentSize;

public:
    MyVector()
    {
        arr = new T[1];
        allocatedSize = 1;
        currentSize = 0;
    }

    MyVector(const MyVector& vectorToCopy)
    {
        arr = new T[vectorToCopy.allocatedSize];
        allocatedSize = vectorToCopy.allocatedSize;
        currentSize = vectorToCopy.currentSize;
        for (int i = 0; i < currentSize; i++)
        {
            arr[i] = vectorToCopy.arr[i];
        }
    }

    MyVector& operator = (const MyVector& vectorToCopy)
    {
        allocatedSize = vectorToCopy.allocatedSize;
        currentSize =  vectorToCopy.currentSize;
        delete [] arr;
        arr = new T[allocatedSize];
        for (int i = 0; i < currentSize; i++)
        {
            arr[i] = vectorToCopy.arr[i];
        }
        return *this;
    }

    ~MyVector()
    {
        delete[] arr;
    }

    void push_bach(T element)
    {
        if (currentSize == allocatedSize)
        {
            T* temp = new T[2*allocatedSize];
            for (int i = 0; i < allocatedSize; i++)
            {
                temp[i] = arr[i];
            }

            delete[] arr;
            allocatedSize *= 2;
            arr = temp;
        }

        arr[currentSize] = element;
        currentSize++;
    }

    void push_bach(T element, int index)
    {
        if (index >= currentSize)
        {
            logError();
        }
        else
        {
            arr[index] = element;
        }
    }

    int size()
    {
        return currentSize;
    }

    T at(int index)
    {
        if (index >= currentSize)
        {
            logError();
            return 0;
        }
        else
        {
            return arr[index];
        }
    }

    T operator[] (int index)
    {
        if (index >= currentSize)
        {
            logError();
            return 0;
        }
        else
        {
            return arr[index];
        }
    }

    T* begin()
    {
        return &arr[0];
    }

    T* end()
    {
        return &arr[currentSize-1];
    }

    void print()
    {
        for (int i = 0; i < currentSize; i++)
        {
            std::cout<<arr[i]<<" ";
        }
        std::cout<<std::endl;
    }

private:
    void logError()
    {
        std::cout<<"element index out of range"<<std::endl;
    }

};
