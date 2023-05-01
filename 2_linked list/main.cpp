// created by mohamed reyad on 11 / 4 / 2023

#include <iostream>
using namespace std ;
template<class T>

struct node{
    T item ;
    node *next;
};

template<class T>

class linkedList{
public :
    node<T>* first ;
    node<T> *last ;
    int length ;

    node<T>* getFirst(){
        return this->first;
    }
    node<T>* getLast(){
        return this->last;
    }

    linkedList(){
        first = last = NULL;
        length = 0;
    }
    bool isEmpty (){
        return(first == NULL);
    }

    void insertAtHead(T element ){
        node<T>* newNode;
        newNode = new node<T>;
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
        node<T> *newNode;
        newNode = new node<T>;
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
            node<T>*newNode=new node<T> ;
            newNode->item = element ;
            if (pos == 0){
                insertAtHead(element);
            }
            if(pos == length){
                insertAtTail(element);
            }
            else {
                node <T> *cur=first;
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
        node<T> *cur=first;
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
            node<T> *temp=new node<T> ;
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
            node<T>*cur;
            node<T>*pre;
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
        node <T>*cur;
        node<T>*pre;
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
        node<T>*cur=first;
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
        node<T> *cur = first ;
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
        node<T>*cur = first ;
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
        node<T>*cur = first ;
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
            node<T> *secondCur = first;
            node<T>*secondPrev = NULL;
            for (int i = 0; i < secondItemIdx; ++i) {
                secondPrev = secondCur;
                secondCur = secondCur->next;
            }

            node <T>*temp = secondCur->next;

            secondPrev->next = first;
            node <T>*firstNext = first->next;
            first->next = temp;
            secondCur->next = firstNext;

            first = secondCur;
            return;
        }

        // Case 2: Swap non-tail and tail node
        if (firstItemIdx != 0 && secondItemIdx == length - 1) {
            node<T> *firstCur = first, *firstPrev = NULL;
            for (int i = 0; i < firstItemIdx; ++i) {
                firstPrev = firstCur;
                firstCur = firstCur->next;
            }
            node<T> *secondPrev = first;
            node<T>*secondCur = secondPrev->next;
            while (secondCur->next != NULL) {
                secondPrev = secondCur;
                secondCur = secondCur->next;
            }
            node<T>* temp = secondCur->next;

            firstPrev->next=secondCur;
            secondPrev->next=firstCur;
            secondCur->next=firstCur->next;
            firstCur->next=temp;

            last=firstCur;

            return;
        }

        // Case 3: Swap head and tail node
        if (firstItemIdx == 0 && secondItemIdx == length - 1) {
            node <T>*firstCur = first;
            node<T>*firstPrev = NULL;
            for (int i = 0; i < firstItemIdx; ++i) {
                firstPrev = firstCur;
                firstCur = firstCur->next;
            }
            node<T> *secondPrev = first;
            node<T>*secondCur = secondPrev->next;
            while (secondCur->next != NULL) {
                secondPrev = secondCur;
                secondCur = secondCur->next;
            }

            node<T>*temp = secondCur->next;

            firstPrev->next = secondCur;
            secondCur->next = firstCur->next;
            secondPrev->next = firstCur;
            firstCur->next = temp;

            first = secondCur;

            return;
        }

        // Case 4: Swap non-head and non-tail node
        node<T> *firstCur = first;
        node<T>*firstPrev = NULL;
        for (int i = 0; i < firstItemIdx; ++i) {
            firstPrev = firstCur;
            firstCur = firstCur->next;
        }
        node<T> *secondCur = first;
        node<T>*secondPrev = NULL;
        for (int i = 0; i < secondItemIdx; ++i) {
            secondPrev = secondCur;
            secondCur = secondCur->next;
        }

        node<T>*temp = secondCur->next;

        firstPrev->next = secondCur;
        secondPrev->next = firstCur;
        secondCur->next = firstCur->next;
        firstCur->next = temp;
    }

    void clear() {
        node<T>*cur = first;
        while (cur != NULL) {
            node<T>*temp = cur;
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


template<class T>
void combineNodesBetweenZeros(linkedList<int>& list) {
    node<int> * current= list.getFirst();
    node <int>*zero= nullptr;
    int sum = 0;
    while (current != nullptr) {
        if (current->item == 0) {
            if (zero != nullptr) {
                zero->item=sum;
                zero->next=current;
            }
            sum = 0;
            zero = current;
        } else {
            sum += current->item;
        }
        current = current->next;
    }
    if (zero != nullptr) {
        zero->item=sum;
        zero->next=nullptr;
    }
    while (list.getFirst() != nullptr && list.getFirst()->item == 0) {
        list.removeAtHead();
    }
    while (list.getLast() != nullptr && list.getLast()->item == 0) {
        list.removeAtTail();
    }
}
//Problem 2
    node<int>* merge_K_Lists(node<int> *arr[],int k) {
    node<int>* head = new node<int>;
    head->next= NULL;
    node<int>* tail = new node<int>;
    tail =head;
    bool ck = true;
    while (ck) {
        int mini = INT_MAX;
        int mini_index = -1;
        ck = false;
        for (int i = 0; i < k; i++) {
            if (arr[i] != NULL && arr[i]->item < mini) {
                mini = arr[i]->item;
                mini_index = i;
                ck = true;
            }
        }
        if (ck) {
            tail->next = arr[mini_index];
            tail = tail->next;
            arr[mini_index] = arr[mini_index]->next;
        }
    }
    return head->next;
}

int main() {
//     Test 1: Create a linked list of integers and insert elements at head and tail
    linkedList<int> intList;
    cout << "Inserting elements at head: ";
    for (int i = 5; i >= 1; i--) {
        intList.insertAtHead(i);
    }

    intList.print();
    cout << endl;

    cout << "Inserting elements at tail: ";
    for (int i = 6; i <= 10; i++) {
        intList.insertAtTail(i);
    }
    intList.print();
    cout << endl;

    // Test 2: Remove elements from head and tail
    intList.removeAtHead();
    cout << "After removing head element: ";
    intList.print();
    cout << endl;

    intList.removeAtTail();
    cout << "After removing tail element: ";
    intList.print();
    cout << endl;

    // Test 3: Insert an element at a specific position
    intList.insertAt(4, 20);
    cout << "After inserting an element at position 4: ";
    intList.print();
    cout << endl;

    // Test 4: Remove an element from a specific position
    intList.removeAt(3);
    cout << "After removing an element from position 3: ";
    intList.print();
    cout << endl;

    // Test 5: Retrieve an element at a specific position
    cout << "Element at position 2: " << intList.retrieveAt(2) << endl;

    // Test 6: Check if an element exists in the list
    int element = 7;
    if (intList.isExist(element)) {
        cout << element << " exists in the list." << endl;
    }
    else {
        cout << element << " does not exist in the list." << endl;
    }

    // Test 7: Check if an element at a specific position is equal to a given value
    int index = 6;
    if (intList.isItemAtEqual(10, index)) {
        cout << "Element at position " << index << " is equal to 10." << endl;
    }
    else {
        cout << "Element at position " << index << " is not equal to 10." << endl;
    }

    // Test 8: Replace an element at a specific position with a new value
    intList.replaceAt(30, 2);
    cout << "After replacing element at position 2 with 30: ";
    intList.print();
    cout << endl;

    // Test 9: Swap two elements at specific positions
    intList.swap(2, 5);
    cout << "After swapping elements at positions 2 and 5: ";
    intList.print();
    cout << endl;

//Test 10: Create a linked list of integers and combine nodes between  any two consecutive 0s    // problem 1

    linkedList<int> list;
    list.insertAtTail(0);
    list.insertAtTail(3);
    list.insertAtTail(1);
    list.insertAtTail(0);
    list.insertAtTail(4);
    list.insertAtTail(5);
    list.insertAtTail(2);
    list.insertAtTail(0);
    cout <<"\nproblem 1 \nlist before combining between 2 zeros \n";
    list.print();
    cout <<"\n";
    combineNodesBetweenZeros<int>(list);
    cout <<"result after combining between 2 zeros \n";
    list.print();
    cout <<"\n";

    linkedList<int> list1;
    list1.insertAtTail(0);
    list1.insertAtTail(1);
    list1.insertAtTail(0);
    list1.insertAtTail(3);
    list1.insertAtTail(0);
    list1.insertAtTail(2);
    list1.insertAtTail(2);
    list1.insertAtTail(0);

    cout <<"\nproblem 1 \nlist before combining between 2 zeros \n";
    list1.print();
    cout <<"\n";
    combineNodesBetweenZeros<int>(list1);
    cout <<"result after combining between 2 zeros \n";
    list1.print();
    cout<<endl;
//________________________________________________________________
    linkedList<int>l1,l2,l3,l4,l5,l6;
    l1.insertAtHead(5);
    l1.insertAtHead(4);
    l1.insertAtHead(1);
    l2.insertAtHead(4);
    l2.insertAtHead(2);
    l2.insertAtHead(1);
    l3.insertAtHead(6);
    l3.insertAtHead(2);
    l4.insertAtHead(7);
    l4.insertAtHead(5);
    l4.insertAtHead(3);
    l4.insertAtHead(1);
    l5.insertAtHead(8);
    l5.insertAtHead(6);
    l5.insertAtHead(4);
    l5.insertAtHead(2);
    l6.insertAtHead(10);
    l6.insertAtHead(9);
    l6.insertAtHead(0);
    //________________________________________________________________
    cout<<endl;
    cout<<"Problem 2\n";
    cout<<"1st test case ::\n";
    cout<<"lists before merge:\n";
    l1.print();
    cout<<endl;
    l2.print();
    cout<<endl;
    cout<<endl;
    l3.print();
    cout<<endl;
    cout<<"After Merging ::\n";
    node<int>* arr[]= {l1.first,l2.first,l3.first};
    node<int>* merged_list = merge_K_Lists(arr,3);
    while (merged_list) {
        cout << merged_list->item << " ";
        merged_list = merged_list->next;
    }
    cout<<endl<<endl;
    cout<<"2nd test case ::\n";
    cout<<"lists before merge:\n";
    l4.print();
    cout<<endl;
    l5.print();
    cout<<endl;
    cout<<endl;
    l6.print();
    cout<<endl;
    cout<<"After Merging ::\n";
    node<int>* arr1[]= {l4.first,l5.first,l6.first};
    merged_list = merge_K_Lists(arr1,3);
    while (merged_list) {
        cout << merged_list->item << " ";
        merged_list = merged_list->next;
    }
}
