// Singly Linked Lists From Scratch

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string contents;
    Node* next;

    ~Node() { cout << "destroyed muahhahhahahah" << endl;}
};

void printLL(Node* arg);
void pushBack(Node*& arg, string str);
void popBack(Node*& arg);
void pushFront(Node*& arg, string str);
int getSize(Node* arg);
void insertAfter(Node* target, string argContents);
void clear(Node*& arg);

int main(void) {

    Node* a = nullptr;  //linked list
    Node* temp = nullptr;

    pushFront(a, "john");
    pushBack(a, "Roan");
    pushBack(a, "Preston");
    pushBack(a, "Andrew");
    pushBack(a, "Iron Man");
    pushBack(a, "Peter Parker");

    int size = getSize(a);

    cout << "list size: " << getSize(a) << endl;
    printLL(a);

    clear(a);

    cout << "list size: " << getSize(a) << endl;
    printLL(a);

    return(0);
}

void pushBack(Node*& arg, string str) {
    Node* temp = arg;

    if (arg == nullptr) {
        arg = new Node();
        arg->contents = str;
        arg->next = nullptr;
        return;
    }

    while (temp->next != nullptr) {
        temp = temp->next;
    };
    
    temp->next = new Node();
    temp = temp->next;
    temp->contents = str;
    temp->next = nullptr;
}

void popBack(Node*& arg){
    Node* cur = arg;

    if(cur->next == nullptr){
        delete cur;
        arg = nullptr;
        return;
    }

    while(cur->next->next != nullptr){
        cur = cur->next;
    }

   delete cur->next;
   cur->next = nullptr;
}

void pushFront(Node*& arg, string str) {
    Node* cur = new Node();
    cur->contents = str;
    cur->next = arg;

    arg = cur;

}
int getSize(Node* arg) {
    Node* cur = arg;
    int count = 0;

    while (cur != nullptr) {
        count++;
        cur = cur->next;
    }

    return count;
}
void insertAfter(Node* target, string argContents) {

    Node* toAdd = new Node();
    toAdd->contents = argContents;
    toAdd->next = target->next;

    target->next = toAdd;
}

void printLL(Node* arg) {
    //print functionality
    Node* temp = arg;
    if (arg == nullptr) {
        cout << "Empty List" << endl;
        return;
    }

    do {
        cout << temp->contents << endl;
        temp = temp->next;

    } while (temp!= nullptr);
}

void clear(Node*& arg){
    while(getSize(arg) != 0){
        popBack(arg);
    }
}