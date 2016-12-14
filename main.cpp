#include <iostream>
#include <vector>
#include <iterator>

template <typename T, int s>

class CircularBuffer
{
public:
    
    CircularBuffer()
    {
        std::vector<T> arr1(s);
        head = tail = length = 0;
        bufferSize = s;
        arr = new T[bufferSize];
    }
    
    ~CircularBuffer()
    {
        arr1.~vector();
        delete[] arr;
    }
    
    T operator[] (int n)
    {
        if (n>=0 || n<size())
            return arr[n];
        else return 0;
    }
    
    
    void put(const T & value)
    {
        if (tail == bufferSize)
        {
            tail = 0;
        }
        
        arr[tail] = value;
        ++tail;
        ++length;
    }
    
    
    
    T & pop()
    {
        if (head == bufferSize) {
            head = 0;
        }
        T & elem = arr[head];
        ++head;
        --length;
        return elem;
    }
   
    size_t size() const
    {
        return length;
        //return arr.size();
    }
    
    size_t capacity() const
    {
        return bufferSize;
        //return arr1.size();
    }
    
    void printBuffer()
    {
        if (size() > 0)
        {
            std::cout << "Head: " << head << ", Elements: ";
            int i = 0;
            for (i = 0; i <= size(); i++)
                std::cout << arr[i]<< " ";
            std::cout <<"i="<< i << "; Tail: " << tail<<" SIZE:"<<size()<<"\n";
        }
    }
    
private:
    std::vector<T> arr1;
    int * arr;
    int bufferSize;
    int length;
    int head;
    int tail;
};


int main()
{
    CircularBuffer<int, 5> buf;
    
    for (int i = 0; i < 10; ++i)
    {
        buf.put(i * 2);
        if (buf.size() == buf.capacity()) {
            std::cout << "---------------" << std::endl;
            while (buf.size()) {
                std::cout << buf.pop() << std::endl;
                buf.printBuffer();
            }
        }
    }
    
    std::cout << "---------------" << std::endl;
    while (buf.size()) {
        std::cout << buf.pop() << std::endl;
        buf.printBuffer();
    }
    //std::cout << "SIZE:" << buf.size();
    //buf.printBuffer();
    
    return 0;
}