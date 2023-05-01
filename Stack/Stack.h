#include <iostream>
using namespace std;

template <class T>
class AStack
{
    T Top;
    T *stack;
    int size;
    int cap; // capacity

public:
    AStack():size(0), cap(100){ stack = new T[cap]; }
    ~AStack() {delete stack;}
    void push(T element);
    T pop();
    T top();
    bool isEmpty();
    int stackSize();
    void clear();
    void print();
};