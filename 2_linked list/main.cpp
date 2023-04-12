#include <iostream>
using namespace std ;

template<class T>

class linkedList{
    struct node{
        T item ;
        node *next;
    };
    node* first ;
    node* last ;
    int length ;

public :
    linkedList(){
    first = last = NULL;
    length = 0;
}
bool isEmpty (){
    return(first == NULL);
}

void insertAtHead(T element ){
    node* newNode;
    newNode = new node;
    newNode->item=element;
    if (length== 0){
        first=last=newNode;
        newNode->next=NULL;
    }
    else{
        newNode->next=first;
        first=newNode;
    }
    length++;
}

void insertAtTail (T element) {
    node *newNode;
    newNode = new node;
    newNode->item = element;
    if (length == 0) {
        first = last = newNode;
        newNode->next = NULL;
    }
    else {
        last->next = newNode;
        newNode->next = NULL;
        last = newNode;
    }
    length++;
}

    void insertAt(int pos , int element ){
    if (pos<0 || pos>length){
        cout <<"out of range \n";
    }
    else {
        node*newNode=new node ;
        newNode->item = element ;
    if (pos == 0){
        insertAtHead(element);
    }
    if(pos == length){
        insertAtTail(element);
    }
    else {
        node *cur=first;
        for (int i = 1; i < pos ; ++i) {
            cur=cur->next;
        }
        newNode->next=cur->next;
        cur->next=newNode;
        length++;
        }

        }
}
    void print (){
    node *cur=first;
        while (cur!=NULL) {
            cout << cur->item<<" ";
            cur=cur->next;
        }
}

void removeAtHead (){
    if (length == 0){
        cout <<"the list is already empty ";
    }
    if (length ==1 ){
        delete first;
        first=last=NULL;
        length--;
    }
    else{
        node *temp=new node ;
        temp=first;
        first =first->next;
        delete temp ;
        length--;
    }
}

void removeAtTail() {
       if (length == 0){
            cout <<"the list is already empty ";
        }
        if (length ==1 ){
            delete first;
            first=last=NULL;
            length--;
        }
        else {
            node*cur,*pre;
            cur=first->next;
            pre=cur;
            while(cur!= last){
                pre=cur;
                cur=cur->next;
            }
            delete cur;
            pre->next=NULL;
            last=pre;
            length-=1;

        }

    }

void removeAt (int index ) {
    node *cur,*pre;
    if (index<0 || index> length ){
        cout <<"out of range \n";
    }
    if (length == 0){
        cout <<"the list is already empty ";
    }
    if (index == 0 ){
        removeAtHead();
    }
    if (index==length){
        removeAtTail();
    }
    else {
        cur=first->next;
        pre=first;
        for (int i = 0; i < index-1 ; ++i) {    //cur pointer on the index .... pre pointer on the node before cur
            pre = cur;
            cur=cur->next;
        }
            pre->next=cur->next;
            delete cur;
            length--;

    }
    }

    bool isExist (int element){
        node *cur=first;
        while (cur!=NULL) {
            if (cur->item==element){
                return true ;
            }
            else {
                cur=cur->next;
            }
        }
        return false;
    }


    T retrieveAt (int index) {
    node *cur = first ;
    if(index == 0){
        return first->item;
    }
    if (index == length ){
        return last->item;
    }
    else {
        for (int i = 0; i < index ; ++i){
            cur=cur->next;
        }
        return cur->item;
    }

}
   bool isItemAtEqual (T element , int index) {
       node*cur = first ;
        if (index==0){
            return (first->item == element);
        }
        if (index==length){
            return (last->item == element);
        }
        else {
            for (int i = 0; i < index ; ++i) {
                cur=cur->next;
            }
            return (element==cur->item);
        }

}
   void replaceAt (T newElement, int index){
       node*cur = first ;
       if (index==0){
           first->item = newElement ;
       }
       if (index==length){
            last->item = newElement ;
       }
       else {
           for (int i = 0; i < index ; ++i) {
               cur=cur->next;
           }
           cur->item = newElement ;

       }


   }

    void swap (int firstItemIdx, int secondItemIdx){
        if (firstItemIdx == secondItemIdx) {
            return;
        }
        if ((firstItemIdx < 0 || firstItemIdx >= length) || (secondItemIdx < 0 || secondItemIdx >= length)) {
            cout << "Invalid index\n";
            return;
        }

        // Case 1: Swap head and non-head node
        if (firstItemIdx == 0 && secondItemIdx != 0) {
            node *secondCur = first, *secondPrev = NULL;
            for (int i = 0; i < secondItemIdx; ++i) {
                secondPrev = secondCur;
                secondCur = secondCur->next;
            }

            node* temp = secondCur->next;

            secondPrev->next = first;
            node *firstNext = first->next;
            first->next = temp;
            secondCur->next = firstNext;

            first = secondCur;
            return;
        }

        // Case 2: Swap non-tail and tail node
        if (firstItemIdx != 0 && secondItemIdx == length - 1) {
            node *firstCur = first, *firstPrev = NULL;
            for (int i = 0; i < firstItemIdx; ++i) {
                firstPrev = firstCur;
                firstCur = firstCur->next;
            }
            node *secondPrev = first, *secondCur = secondPrev->next;
            while (secondCur->next != NULL) {
                secondPrev = secondCur;
                secondCur = secondCur->next;
            }
            node* temp = secondCur->next;

            firstPrev->next=secondCur;
            secondPrev->next=firstCur;
            secondCur->next=firstCur->next;
            firstCur->next=temp;

            last=firstCur;

            return;
        }

        // Case 3: Swap head and tail node
        if (firstItemIdx == 0 && secondItemIdx == length - 1) {
            node *firstCur = first, *firstPrev = NULL;
            for (int i = 0; i < firstItemIdx; ++i) {
                firstPrev = firstCur;
                firstCur = firstCur->next;
            }
            node *secondPrev = first, *secondCur = secondPrev->next;
            while (secondCur->next != NULL) {
                secondPrev = secondCur;
                secondCur = secondCur->next;
            }

            node* temp = secondCur->next;

            firstPrev->next = secondCur;
            secondCur->next = firstCur->next;
            secondPrev->next = firstCur;
            firstCur->next = temp;

            first = secondCur;

            return;
        }

        // Case 4: Swap non-head and non-tail node
        node *firstCur = first, *firstPrev = NULL;
        for (int i = 0; i < firstItemIdx; ++i) {
            firstPrev = firstCur;
            firstCur = firstCur->next;
        }
        node *secondCur = first, *secondPrev = NULL;
        for (int i = 0; i < secondItemIdx; ++i) {
            secondPrev = secondCur;
            secondCur = secondCur->next;
        }

        node* temp = secondCur->next;

        firstPrev->next = secondCur;
        secondPrev->next = firstCur;
        secondCur->next = firstCur->next;
        firstCur->next = temp;
}

    void clear() {
        node* cur = first;
        while (cur != NULL) {
            node* temp = cur;
            cur = cur->next;
            delete temp;
        }
        first = last = NULL;
        length = 0;
        cout <<"inside clear function \n";
    }


    int linkedListSize (){
        return length ;
    }
};


int main() {

//    linkedList<int> myList;
//    myList.insertAtTail(5);
//    myList.insertAtTail(7);
//    myList.insertAtTail(10);
//    myList.removeAt(1);
//    myList.print(); // expected output: 5 10

//    linkedList<int> myList;
//    myList.insertAtTail(5);
//    myList.insertAtTail(7);
//    myList.insertAtTail(10);
//    bool exists = myList.isExist(10);
//    cout << exists << endl; // expected output: 1 (true)

//    linkedList<int> myList;
//    myList.insertAtTail(5);
//    myList.insertAtTail(7);
//    myList.insertAtTail(10);
//    int value = myList.retrieveAt(1);
//    cout << value << endl; // expected output: 7

//    linkedList<int> myList;
//    myList.insertAtTail(5);
//    myList.insertAtTail(7);
//    myList.insertAtTail(10);
//    bool isEqual = myList.isItemAtEqual(10, 3);
//    cout << isEqual << endl; // expected output: 1 (true)


//    linkedList<int> myList;
//    myList.insertAtTail(5);
//    myList.insertAtTail(7);
//    myList.insertAtTail(10);
//    myList.replaceAt(8, 1);
//    myList.print(); // expected output: 5 8 10
//    cout <<endl;
//    myList.clear();
//    myList.print(); // expected output:

        linkedList<int> list;
        list.insertAtTail(10);
        list.insertAtTail(20);
        list.insertAtTail(30);
        list.insertAtTail(40);
        cout << "Before swapping: ";
        list.print(); // Output: 10 20 30 40
        cout << endl;
        list.swap(1,3); // Swap the second and third elements
        cout << "After swapping: ";
        list.print(); // Output: 10 30 20 40
        cout << endl;
        return 0;
}
