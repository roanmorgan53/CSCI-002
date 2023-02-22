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
void printR(Node* arg);
int count(Node* arg);

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

        cout << "\twould you like to add another element(y / n) :";
        cin >> userin;

        cout << endl;

    } while (userin == 'y');

    cur->next = nullptr;

    cur = a;

    cout << "Forwards: ";
    print(a);
    cout << endl;

    cout << "Elements #: " << count(a) << endl;

    cout << "Backwards: ";
    printR(a);
    cout << endl;

    delete a;

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

void printR(Node* arg)
{
    Node* cur = arg;
    Node* prev = nullptr;
    Node* next = nullptr;

    do {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    } while (cur != nullptr);

    cur = prev;

    do {
        cout << cur->contents << " ";
        cur = cur->next;

    } while (cur != nullptr);
     
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
