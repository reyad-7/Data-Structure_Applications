#include "Stack.h"
// int main(){
//     AStack<int> stack;
//     stack.push(50);
//     stack.push(60); stack.print(); // [50 60]
//     stack.clear();  stack.print(); // []

//     stack.push(50);
//     stack.push(60);
//     stack.push(70);
//     stack.push(80);
//     stack.push(90); stack.print(); // [50 60 70 80 90]

//     cout  << "popedValue: "<< stack.pop() << endl; //
//     stack.pop(); stack.print(); // [50 60 70]

//     cout<<stack.top()<<'\n'; // 70

// }

template<class T>
void AStack<T>::push(T element){
    if(size >= cap){
        printf("Error, The Stack Is Full..!");
    }else{
        stack[size++] = element;
    }
}

template<class T>
T AStack<T>::top(){
    return stack[size-1];
}

template<class T>
void AStack<T>::clear(){ size =0; }

template<class T>
void AStack<T>::print(){
    printf("[");
    for(int i = 0; i < size; i ++){
        cout << stack[i] << " "; 
    }printf("]\n");
}

template <class T>
T AStack<T>::pop(){
    if(isEmpty()){
        printf("Error, Can Not Pop form Empty Stack");
        return -1;
    }else{
        T val = stack[size-1];
        size--;
        return val; 
    }
}

template<class T>
int AStack<T>::stackSize() { return size;}

template <class T>
bool AStack<T>::isEmpty(){ return size == 0; }