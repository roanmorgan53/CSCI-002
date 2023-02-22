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

void print(Node* arg);
void printR(Node* arg);
int count(Node* arg);

int main(void) {

    Node* a = nullptr; //LL
    Node* cur = nullptr; //iterator

    bool isFirst = true;
    char userin = 'y';
    string temp = "N/A";

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

        cout << "add element? (y/n):";
        cin >> userin;

        cout << endl;

    } while (userin == 'y');

    cur->next = nullptr;

    cur = a;

    cout << "Forwards: ";
    print(a);
    cout << endl;

    cout << "Backwards: ";
    printR(a);
    cout << endl;

    cout << "Elements #: " << count(a) << endl;

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
    vector<string> r;

    do {
        if (cur != nullptr) {
            r.push_back(cur->contents);
        }

        cur = cur->next;

    } while (cur != nullptr);
    
    for (int i = r.size() - 1; i >= 0; i--) {
        cout << r[i] << " ";
    }
     
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
