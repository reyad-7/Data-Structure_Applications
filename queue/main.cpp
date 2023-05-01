#include<bits/stdc++.h>
using namespace std;
//template<class elementType>
template<class elementType>

class queueList{
private:
    list<elementType> lst;
public:
    queueList()= default;
    int queuesize(){
        return lst.size();
    }
    template<class t>

    void enqueue(t element){
        lst.push_back(element);
    }

    template<class t>
    t dequeue(){
        t tmp=lst.front();
        lst.pop_front();
        return tmp;
    }
    template<class t>
    t first(){
        return lst.front();
    }

    bool isEmpty(){
        return lst.empty();
    }

    void clear(){
        lst.clear();
    }
    int operator[](int i){
        int temp=lst.front();
        lst.pop_front();
        return temp;
    }
    void print()
    {
        for (auto const &i: lst) {
            std::cout << i <<" ";
        }
    }

};
//problem#1"Write a function that generates and prints all binary integers from 1 to N."

void print_binary_numbers_to_N(int n){
    queueList<string> queue1;
    queue1.enqueue("1");
    while (n--){
        string first=queue1.first<string>();
        queue1.dequeue<string>();
        cout<<first<<" ";
        string second=first;
        queue1.enqueue(first.append("0"));
        queue1.enqueue(second.append("1"));
    }
}
template<class t>
class Stackwithqueue{
private:
    queueList<t> queueList1;
public:
    void push(t element){
        queueList1.enqueue(element);
    }

    void pop(){
        queueList1.template dequeue<t>();
    }
//    void print_Stack_elements(){
//
//            for (auto &i: queueList1) {
//                std::cout << i <<" ";
//            }
//
//    }
    int stackSize(){
        return queueList1.queuesize();
    }
};
template<class elementType>

void sortQueue(queueList<int> queueList){
    vector<int> vector1;
    for (int i = 0; i < queueList.queuesize(); ++i) {
        vector1[i]=queueList[i];
    }

    std::sort(vector1.begin(), vector1.end());
    queueList.clear();
    for (int i : vector1) {
        queueList.enqueue(i);
    }

    for (int i : vector1) {
        cout<<i<<" ";
    }
//    ::queueList<int> sortedQueue;
//    for (int i = 0; i < queueList.queuesize(); ++i) {
//        sortedQueue.enqueue(vector1[i]);
//    }
}
int main(){




    queueList<int> queue1;
    queueList<int> queue2;

    //test cases for all functions of the queue
    queue1.enqueue(10);
    queue1.enqueue(15);
    queue1.dequeue<int>();
    cout<<queue1.first<int>()<<" ";
    cout<<queue1.isEmpty()<<" ";
    cout<<queue1.queuesize()<<" ";
    queue1.print();
//test case for problem #1
    print_binary_numbers_to_N(6);

//problem #2 implement stack with queue and print the size
    Stackwithqueue<int> stackwithqueue1;
    stackwithqueue1.push(10);
    stackwithqueue1.push(20);
    cout<<stackwithqueue1.stackSize()<<" ";
    stackwithqueue1.pop();
    cout<<stackwithqueue1.stackSize();


//problem #3 sorting a queue

    queue2.enqueue(5);
    queue2.enqueue(4);
    queue2.enqueue(8);
    queue2.enqueue(1);
    sortQueue<int>(queue1);
}