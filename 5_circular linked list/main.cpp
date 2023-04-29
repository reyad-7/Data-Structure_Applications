#include<bits/stdc++.h>

using namespace std;

class linked_list {
private:
    struct node {
        int info;
        node *next;
    };
    node *head;
    node *tail;
    int length;

public:
    linked_list() {
        head = tail = NULL;
        length = 0;
    }

    bool isEmpty() {
        return length == 0;
    }

    void insertAtHead(int value) {
        node *newnode = new node;
        newnode->info = value;
        if (length == 0) {
            head = tail = newnode;
            newnode->next = head;
        } else {
            newnode->next = head;
            head = newnode;
            tail->next = head;
        }
        length++;
    }

    void insertAtEnd(int value) {
        node *newnode = new node;
        newnode->info = value;
        if (length == 0) {
            head = tail = newnode;
            newnode->next = NULL;
        } else {
            tail->next = newnode;
            newnode->next = head;
            tail = newnode;
        }
        length++;
    }

    void insertAt(int pos, int value) {
        node *newnode = new node;
        newnode->info = value;
        if (length == 0) {
            insertAtHead(value);
        } else {
            node *cur;
            cur = head;
            for (int i = 0; i < pos; ++i) {
                cur = cur->next;
            }
            newnode->next = cur->next;
            cur->next = newnode;

        }
        length++;
    }

    void print() {
        node *cur = head;
        while (cur->next != head) {
            cout << cur->info << " ";
            cur = cur->next;
        }
        cout << cur->info << " ";
        cout << endl;
    }

    int circularLinkedListSize() {
        return length;
    }

    void clear() {
        length = 0;
    }


    void removeAtHead() {
        if (length == 0) {
            cout << "the list is empty";
        } else if (length == 1) {
            head = tail = NULL;
            length--;
        } else {
            node *cur = head;
            head = head->next;
            tail->next = head;
            delete cur;
            length--;
        }

    }

    void printTailNext() {
        cout << tail->next->info;
    }

    void removeAtEnd() {
        if (length == 0) {
            cout << "the list is empty";
        } else if (length == 1) {
            head = tail = NULL;
            length--;
        } else {
            node *cur = head->next;
            node *prev = head;
            while (cur != tail) {
                prev = cur;
                cur = cur->next;
            }
            prev->next = head;
            delete cur;
            tail = prev;
            length--;
        }
    }

    void removeAt(int index) {
        if (index < 0 || index > length) {
            cout << "out of the range";
            return;
        } else if (length == 0) {
            cout << "the list is empty";
        } else if (index == 0) {
            removeAtHead();
        } else {
            node *cur = head->next;
            node *prev = head;
            for (int i = 0; i < index - 1; ++i) {
                prev = cur;
                cur = cur->next;
            }
            if (cur->next == head) {
                prev->next = head;
                tail = prev;
                delete cur;
                length--;
            } else {
                prev->next = cur->next;
                delete cur;
                length--;
            }
        }

    }

    void removeOf(int element) {
        if (length == 0) {
            cout << "the list is empty";
        } else if (head->info == element) {
            removeAtHead();
        } else {
            node *cur = head->next;
            node *prev = head;
            while (cur != NULL && cur->info != element) {
                prev = cur;
                cur = cur->next;
            }
            if (cur->next == NULL) {
                prev->next = NULL;
                tail = prev;
                delete cur;
                length--;
            } else {
                prev->next = cur->next;
                delete cur;
                length--;
            }
        }
    }

    void reverse() {
        node *prev = NULL;
        node *cur = head;
        node *next;
        while (cur != NULL) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
    }

    template<class elementType>
    bool search(elementType element) {
        node *cur = head;
        while (cur->next != head) {
            if (cur->info == element)
                return true;
            cur = cur->next;
        }
        return false;
    }

    template<class elementType>
    bool isItemAtEqual(elementType element, int index) {
        node *cur = head;
        for (int i = 0; i < index; ++i) {
            cur = cur->next;
        }
        if (cur->info == element) {
            return true;
        } else {
            return false;
        }
    }

    template<class elementType>
    elementType retrieveAt(int index) {
        node *cur = head;
        for (int i = 0; i < index; ++i) {
            cur = cur->next;
        }
        return cur->info;
    }

    template<class elementType>
    void replaceAt(elementType newElement, int index) {
        node *cur = head;
        for (int i = 0; i < index; ++i) {
            cur = cur->next;
        }
        cur->info = newElement;
    }

    void swap(int firstItemIdx, int secondItemIdx) {
        if (firstItemIdx<0 || secondItemIdx<0||firstItemIdx>length|| secondItemIdx>length){
            cout<<"out of the range";
        }
        node *prev = NULL;
        node *first = head;
        node *second = head->next;


        for (int i = 0; i < min(firstItemIdx,secondItemIdx); ++i) {
            prev = first;
            first = second;
            second = second->next;
        }

        prev->next=first->next;
        first->next=second->next;
        second->next=first;

    }

};


int main() {
    linked_list l;
    l.insertAtHead(10);
    l.insertAtEnd(30);
    l.insertAt(0, 20);
    l.insertAtHead(0);
    l.insertAtEnd(40);
    l.insertAtEnd(50);
    l.insertAtHead(-2);
    l.insertAtEnd(60);
//    l.replaceAt(100, 2);
//    cout << l.isItemAtEqual(10, 0);
//    l.removeAtEnd();
//    l.removeAt(9);
    l.removeAtHead();
//    l.printTailNext();
//cout<<l.circularLinkedListSize();
//l.reverse();
//l.swap(4,2);

    l.print();
//cout<<l.search(100);
}
