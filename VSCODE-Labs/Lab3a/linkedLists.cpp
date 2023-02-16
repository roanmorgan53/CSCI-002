//Roan Morgan
//Lab 3b: Linked List Operators
//2.16.23
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

struct Node {
    Node* next;
    string contents;

};

void print(Node* arg);

int main(void) {

    Node* a = nullptr; //LL
    Node* cur = nullptr; //iterator

    bool isFirst = true;
    char userin = 'y';
    string temp = "N/A";

    cout << endl;

    do {

        if (isFirst) {
            cur = new Node();
            cout << "Input a word: ";
            cin >> temp;
            cur->contents = temp;

            a = cur;

            isFirst = false;
        }
        else {
            cur->next = new Node();
            cur = cur->next;
            cout << "Input a word: ";
            cin >> temp;
            cur->contents = temp;
        }

        cout << "\n would you like to add another element (y/n):";
        cin >> userin;

        cout << endl;

    } while (userin == 'y');

    cur->next = nullptr;

    cur = a;

    print(a);

    return(0);
}

void print(Node* arg)
{
    Node* cur = arg;

    do {
        cout << cur->contents << " ";
        cur = cur->next;

    } while (cur != nullptr);
}
