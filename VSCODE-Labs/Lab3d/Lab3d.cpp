//Roan Morgan
//Singly Linked List Template
//2.22.23
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

template <typename T>
struct Node {
    Node* next;
    T contents;

};

template <typename T>
void pushBack(Node<T>*& arg, string str);

template <typename T>
void pushFront(Node<T>*& arg, string str);

template <typename T>
void print(Node<T>* arg);

template <typename T>
void printR(Node<T>* arg);

template <typename T>
void insert(Node<T>* Target, string Contents);

template <typename T>
int count(Node<T>* arg);

int main(void) {

    Node<string>* a = nullptr; //LL
    Node<string>* temp = nullptr; //iterator
    string userin = "err";
    char userEnter = 'y';
    char runAgain = 'y';

    do {
        a = nullptr; //LL
        system("cls");
        cout << "Linked List Operators!\n---------------------" << endl;

        do {
            cout << "Enter a word: ";
            cin >> userin;

            pushBack(a, userin);

            cout << "Add Element (y/n): ";
            cin >> userEnter;
            cout << endl;
        } while (userEnter == 'y');

        cout << "Forwards: ";
        print(a);
        cout << endl;

        cout << "Backwards: ";
        printR(a);
        cout << endl;

        cout << "Elements #: " << count(a) << endl << endl;

        cout << "Run Again? (y/n):";
        cin >> runAgain;
    } while (runAgain == 'y');



    delete a;

    return(0);
}

template <typename T>
void pushBack(Node<T>*& arg, string str)
{
    Node<T>* temp = arg;

    if (arg == nullptr) {
        arg = new Node<T>();
        arg->contents = str;
        arg->next = nullptr;
        return;
    }

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = new Node<T>();
    temp = temp->next;
    temp->contents = str;
    temp->next = nullptr;
}

template <typename T>
void pushFront(Node<T>*& arg, string str) {
    Node<T>* cur = new Node<T>();
    cur->contents = str;
    cur->next = arg;

    arg = cur;
}

template <typename T>
void print(Node<T>* arg)
{
    Node<T>* cur = arg;

    do {
        cout << cur->contents << " ";
        cur = cur->next;

    } while (cur != nullptr);
}

template <typename T>
void printR(Node<T>* arg)
{
    Node<T>* cur = arg;

    //make another node and store the variables of arg backwards
    Node<T>* temp = nullptr;

    //reverse the list order
    while (cur != nullptr) {
        Node<T>* next = cur->next;
        cur->next = temp; //bring cur to the end
        temp = cur;
        cur = next;
    }

    arg = temp;

    print(arg);

    cur = arg;
    temp = nullptr;

    //reverse the list again
    while (cur != nullptr) {
        Node<T>* next = cur->next;
        cur->next = temp; //bring cur to the end
        temp = cur;
        cur = next;
    }

}

template <typename T>
void insert(Node<T>* target, string contents) {

    Node<T>* toAdd = new Node<T>();
    toAdd->contents = contents;
    toAdd->next = target->next;

    target->next = toAdd;





}

template <typename T>
int count(Node<T>* arg)
{
    Node<T>* cur = arg;
    int count = 0;

    do {
        cur = cur->next;
        count++;
    } while (cur != nullptr);

    return count;

}