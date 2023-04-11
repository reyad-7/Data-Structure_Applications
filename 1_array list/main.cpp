#include <iostream>
using namespace std;

template<class T>

class arraylist{
    int length ;
    int maxSize;
    T *list;
public:
    arraylist(int size ){
        if(size < 0){
            cout <<"the array size should be positive \n an array of size 100 , created" ; 
            size=100;
        }
        maxSize= size;
        length = 0 ;
        list = new T[maxSize];
    }


    bool isItemAtEqual (int location,T item ){
        if (location> length){
            cout <<"out of range\n";
        }
        else {
            return (list[location]== item);
        }
    }

    void insert (T element ){
        if (isFull()){
            cout <<"cannot insert into full list \n";
        }
        else {
            list[length]=element;
            length++;
        }
    }


    void insertAt(int loc ,T item) {
        if(isFull())
            cout<<" The List is Full " << endl;
        else if(loc < 0 || loc > length)
            cout << "Out of Range " << endl;

        else
        {
            for(int i = length; i > loc; i--)
                list[i] = list[i - 1];	//shift right

            list[loc] = item;	//insert the item at the specified position
            length++;	//increment the length
        }
    }

    void replaceAt (int location , T newitem){
        if (location > length){
            cout <<"the location is out of range \n";
        }
        else {
            list[location]=newitem;
        }
    }

    void removeAt (int index){
        if (isEmpty()){
            cout << "the array is already empty \n";
        }
        if (index < 0 || index >= length) {
            cout << "Index is out of range." << endl;
            return;
        }
        else {
            for (int i = index; i < length -1 ; ++i) {
                list[i]=list[i+1];     //shift left
                length--;             // decrement the
            }
        }
    }

//    void removeAt(int index) {
//        if (isEmpty()) {
//            cout << "The array is already empty." << endl;
//            return;
//        }
//
//        if (index < 0 || index >= length) {
//            cout << "Index is out of range." << endl;
//            return;
//        }
//
//        // Shift all elements after index to the left
//        for (int i = index; i < length - 1; i++) {
//            list[i] = list[i + 1];
//        }
//
//        // Decrement the length of the array
//        length--;
//    }
//

    T retrieve_At(int index){
        return list[index];
    }

    void print (){
        for (int i = 0; i < length; ++i) {
            cout << list[i]<<" ";
        }
        cout << "\n";
    }

    int maxListSize()
    {
        return maxSize;
    }

    int listSize()
    {
        return length;
    }

    void clear()
    {
        length = 0;
    }

~arraylist(){
        delete [] list;
    }

    bool isEmpty (){
        return (length==0);
    }
    bool isFull(){
        return (length == maxSize);
    }
};

int main() {
   

//    arraylist<int> lst1(12);
//    for(int i = 0; i < 10 ; i++)
//        lst1.insert(i*2);
//
//    lst1.print();
//    cout <<endl ;
//
//    cout <<lst1.isEmpty();
//    cout <<endl ;
//
//    cout <<lst1.isFull();
//    cout <<endl ;
//
//    cout << lst1.listSize();
//    cout <<endl ;

//    cout << lst1.isItemAtEqual(4,8);
//    cout <<endl ;
//    lst1.insertAt(3,5);
//    lst1.print();
//    lst1.insert(44);
//    lst1.removeAt(5);
//    lst1.print();
//lst1.replaceAt(5,200);
//    lst1.print();
//    lst1.clear();
//        lst1.print();
}
