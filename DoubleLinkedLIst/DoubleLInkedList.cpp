#include "DoubleLinkedList.h"

int main(){
    DoubleLinkedList<int> list;
    /* nsertAtHead(), insertAtTail(), insertAt() */
    list.insertAtHead(30);
    list.insertAtHead(20);
    list.insertAtHead(10);
    list.insertAtTail(50); list.forwardTraversal(); // 10 20 30 50
    list.insertAt(40, 3);  list.forwardTraversal(); // 10 20 30 40 50 
    Node<int>* ptr = list.PtrNode(3);
    list.insertAfter(ptr, 100); list.forwardTraversal(); // 10 20 30 100 50 40
    list.reverse(); list.forwardTraversal(); // 40 50 100 30 20 10
    list.reverse();
    
    /* removeAtHead(), removeAtTail(), removeAt() */
    list.removeAtHead();
    list.removeAtTail(); list.forwardTraversal(); // 20 30 100 50
    list.removeAt(1);    list.forwardTraversal(); // 20 100 50
    
    /* retrieveAt(), replaceAt()*/
    list.replaceAt(200, 1);
    list.forwardTraversal();
    printf("%d \n", list.retrieveAt(1)); // 200

    /* isExist(), isItemEqual() */
    printf("%d \n", list.isExist(20)); // true
    printf("%d \n", list.isExist(9)); //  false
    printf("%d \n", list.isItemAtEqual(20, 0)); // true
    printf("%d \n", list.isItemAtEqual(100, 0)); // false

    list.backwardTraversal(); // 50 200 20
    list.clear();
    list.backwardTraversal(); // 
}

template<class T>
void DoubleLinkedList<T>::insertAtHead(T element){
    Node<T> *newNode = new Node<T>();
    newNode->data = element;

    if(length == 0){
        head = tail = newNode;
        newNode->next = newNode->prev = nullptr;
    }else{
        newNode->prev = nullptr;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    length++;
}

template<class T>
void DoubleLinkedList<T>::insertAtTail(T element){
    Node<T>* newNode = new Node<T>();
    newNode->data = element;

    if(length == 0){
        head = tail = newNode;
        newNode->next = newNode->prev = nullptr;
    }else{
        newNode->next = nullptr;
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    length++;
}

template<class T>
void DoubleLinkedList<T>::insertAt(T element, int index){
    if(index < 0 || index > length){
        printf("Error, out of range..!");
        cout << "  index: " << index << endl;
        return;
    }
    else if(index == 0)
        insertAtHead(element);
    else if(index == length-1)
        insertAtTail(element);
    else{
        Node<T> *newNode = new Node<T>();
        newNode->data = element;

        Node<T> *curr = head;
        for(int i = 1; i < index; i++){
            curr = curr->next;
        }
        newNode->next = curr->next;
        newNode->prev = curr;
        curr->next->prev = newNode;
        curr->next = newNode;
        length++;
    }
}

template<class T>
void DoubleLinkedList<T>::insertAfter(Node<T>* prev, T element){
    if(prev == nullptr || length == 0)
        insertAtHead(element);
    else{
        Node<T> *curr = head;
        for(int i = 0; i < length; i++){
            curr = curr->next;
            if(curr == prev){
                insertAt(element, i);
                break;
            }
        }
        if(curr == nullptr){
            cout << "Error, Node Not Found..!" << endl;
        }
    }
}

template<class T>
bool DoubleLinkedList<T>::isEmpty(){
    return head == nullptr;
}

template<class T>
void DoubleLinkedList<T>::forwardTraversal(){
    Node<T> *curr = head;
    printf("[");
    for(int i = 0; i < length; i++){
        cout << curr->data << " ";
        curr = curr->next;
    }printf("]\n");
}
 
template<class T>
void DoubleLinkedList<T>::backwardTraversal(){
    Node<T> *curr= tail;
    printf("[");
    while (curr != nullptr){
        cout << curr->data << " ";
        curr = curr->prev;
    }
    printf("]\n");
}

template<class T>
Node<T>* DoubleLinkedList<T>::PtrNode(int index){
    Node<T>* curr = head;
    for(int i = 0; i < length+1; i++){
        if(i-1 == index)
            return curr;
        curr = curr->next;
    }
    return nullptr;
}

template<class T>
void DoubleLinkedList<T>::removeAtHead(){
    if(isEmpty()){
        printf("Error, Empty List..!");
        return;
    }else if(length == 1){
        delete head;
        head = tail = nullptr;
        length = 0;
    }else{
        Node<T> *tempPtr;
        tempPtr = head;
        head = head->next;
        delete tempPtr;
        head->prev = nullptr;
        length--;
    }
}

template<class T>
void DoubleLinkedList<T>::removeAtTail(){
    if(isEmpty()){
        printf("Error, Empty List..!");
        return;
    }else if(length == 1){
        delete head;
        head = tail = nullptr;
        length = 0;
    }else{
        Node<T> *curr = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete curr;
        length--;
    }
}

template<class T>
void DoubleLinkedList<T>::removeAt(int index){
    if(index < 0 || index > length){
        printf("Error, out of range..!");
        return;
    }else if(isEmpty()){
        printf("Error, Empty List..!");
        return;
    }else if(index == 0){
        cout <<"remove At head \n";
        removeAtHead();
    }
    else if(index == length-1){
        cout <<"remove At tail \n";
        removeAtTail();
    }
    else{
        Node<T> *curr = head;
        for(int i = 1; i <= index; i++){
            curr = curr->next;
        }

        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
        length--;
    }

}

template<class T>
T DoubleLinkedList<T>::retrieveAt(int index){
    if(index < 0 || index > length){
        printf("Error, Out Of Range..!");
        return -1;
    }else if(isEmpty()){
        printf("Error, Can Not retrieve From Empty List..!");
        return -1;
    }
    else
    {

        Node<T> *curr = head;
        for (int i = 0; i < index; i++)
        {
            curr = curr->next;
        }
        return curr->data;
    }
}

template<class T>
void DoubleLinkedList<T>::replaceAt(T newElement, int index){
    if(index < 0 || index > length){
        printf("Error, Out Of Range..!");
        return;
    }else if(isEmpty()){
        printf("Error, Can Not edit on Empty List..!");
        return;
    }
    else
    {
        Node<T> *curr = head;
        for (int i = 0; i < index; i++)
        {
            curr = curr->next;
        }
        curr->data = newElement;
    }
}

template<class T>
bool DoubleLinkedList<T>::isExist(T element){
    Node<T> *curr= head;
    for(int i = 0; i < length; i++){
        if(curr->data == element){
            return true;
        }
        curr = curr->next;
    }
    return false;
}

template<class T>
bool DoubleLinkedList<T>::isItemAtEqual(T element, int index){
    if (index < 0 || index > length)
    {
        printf("Error, Out Of Range..!");
        return false;
    }
    else if (isEmpty())
    {
        printf("Error, Can Not check on Empty List..!");
        return false;
    }else{
        Node<T> *curr = head;
        for(int i = 0; i < index; i++){
            curr = curr->next;
        }
        return (curr->data == element);
    }
}

template<class T>
void DoubleLinkedList<T>::swap(int firstItemIdx, int secondItemIdx){
    if(firstItemIdx < 0 || secondItemIdx < 0 || firstItemIdx > length || secondItemIdx > length){
        printf("Error, Out Of Range..!"); return; 
    }else{
        Node<T> *curr1;
        Node<T> *curr2;
        for(int i = 0; i < max(firstItemIdx, secondItemIdx); i++){
            if (i < firstItemIdx)
                curr1 = curr1->data;
            if(i < secondItemIdx)
                curr2 = curr2->data;
        }
        Node<T> *temp = curr1->prev;
        curr1->prev = curr2->prev;
        curr2->prev = temp;

        temp = curr1->next;
        curr1->next = curr2->next;
        curr2->next = temp;
    }
}

template<class T>
void DoubleLinkedList<T>::reverse(){
    if(isEmpty()){
        printf("Error, Can Not Reverese an Empty List..!");
        return;
    }else if(length == 1){
        return;
    }else{
        Node<T> *ptr1 = head;
        Node<T> *ptr2 = head->next;

        ptr1->next = nullptr;
        ptr1->prev = ptr2;
        while(ptr2->next != nullptr){
            ptr2->prev = ptr2->next;
            ptr2->next = ptr1;
            ptr1 = ptr2;
            ptr2 = ptr2->prev;
        }
        ptr2->next = ptr1;
        ptr2->prev = nullptr;
        tail = head;
        head = ptr2;
    }
}

template<class T>
int DoubleLinkedList<T>::doubleLinkedListSize(){ return length; }

template<class T>
void DoubleLinkedList<T>::clear(){
    Node<T>* current = head;
    Node<T>* next = nullptr;

    while (current != nullptr){
        next = current->next;
        delete current;
        current = next;
    }

    head = tail = nullptr;
    length = 0;
}