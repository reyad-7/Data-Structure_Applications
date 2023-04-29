#include<bits/stdc++.h>
using namespace std;
//template<class elementType>
class queueList{
private:

    list<int> lst;
public:
    queueList()= default;
    int queuesize(){
        return lst.size();
    }
    template<class elementType>

    void enqueue(elementType element){
        lst.push_back(element);
    }

    template<class elementType>
    elementType dequeue(){
        elementType tmp=lst.front();
        lst.pop_front();
        return tmp;
    }
    template<class elementType>
    elementType first(){
        return lst.front();
    }

    bool isEmpty(){
        return lst.empty();
    }

    void clear(){
        lst.clear();
    }

    void print()
    {
        for (auto const &i: lst) {
            std::cout << i <<" ";
        }
    }

};




int main(){


    queueList queue1;
queue1.enqueue(10);
queue1.enqueue(15);
//queue1.dequeue<int>();
//cout<<queue1.first<int>();
//cout<<queue1.isEmpty();
//cout<<queue1.queuesize();
queue1.print();
}