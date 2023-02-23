//Roan Morgan
//Lab 3b: Linked List Operators
//2.16.23
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

struct Node {
    Node* next;
    string contents;

};

void pushBack(Node*& arg, string str);
void pushFront(Node*& arg, string str);
void print(Node* arg);
void printR(Node* arg);
void insert(Node* Target, string Contents);
int count(Node* arg);

int main(void) {

    Node* a = nullptr; //LL
    Node* temp = nullptr; //iterator
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

void pushBack(Node*& arg, string str)
{
    Node* temp = arg;

    if (arg == nullptr) {
        arg = new Node();
        arg->contents = str;
        arg->next = nullptr;
        return;
    }

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = new Node();
    temp = temp->next;
    temp->contents = str;
    temp->next = nullptr;
}

void pushFront(Node*& arg, string str) {
    Node* cur = new Node();
    cur->contents = str;
    cur->next = arg;

    arg = cur;
}

void print(Node* arg)
{
    Node* cur = arg;

    do {
        cout << cur->contents << " ";
        cur = cur->next;

    } while (cur != nullptr);
}

void printR(Node* arg)
{
    Node* cur = arg;
    
    //make another node and store the variables of arg backwards
    Node* temp = nullptr;

    //reverse the list order
    while (cur != nullptr) {
        Node* next = cur->next;
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
        Node* next = cur->next;
        cur->next = temp; //bring cur to the end
        temp = cur;
        cur = next;
    }

}

void insert(Node* target, string contents) {

    Node* toAdd = new Node();
    toAdd->contents = contents;
    toAdd->next = target->next;

    target->next = toAdd;





}

int count(Node* arg)
{
    Node* cur = arg;
    int count = 0;

    do {
        cur = cur->next;
        count++;
    } while (cur != nullptr);

    return count;

}