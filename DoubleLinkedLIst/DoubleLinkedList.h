#include <iostream>
using namespace std;

template<class T>
class Node{
    public:
    Node *next;
    Node *prev; // previous 
    T data; 
    Node() : next(nullptr), prev(nullptr), data(T()) {}
    Node(T element) : next(nullptr), prev(nullptr), data(element) {}
};
template <class T>
class DoubleLinkedList{
    public:
    Node<T> *head;
    Node<T> *tail;
    T length;     
    DoubleLinkedList() : length(0), head(nullptr), tail(nullptr) {};
    DoubleLinkedList(Node<T>* head, Node<T>* tail, T length) : head(head), tail(tail), length(length){}
    void insertAtHead(T element);  
    void insertAtTail(T element); 
    void insertAt(T element, int index);
    void insertAfter(Node<T>* prev, T data); 
    void removeAtHead(); 
    void removeAtTail(); 
    void removeAt(int index);
    T retrieveAt(int index); 
    void replaceAt(T newElement, int index);
    bool isExist(T element); 
    bool isItemAtEqual(T element, int index); 
    void swap(int firstItemIdx, int SecondItemIdx); 
    void reverse(); 
    bool isEmpty(); 
    int doubleLinkedListSize(); 
    void clear(); 
    void forwardTraversal();  
    void backwardTraversal(); 
    Node<T> *PtrNode(int index); //  (added by me, not required)
};