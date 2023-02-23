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
void print(Node* arg);
void printR(Node* arg);
void insert(Node* Target, string Contents);
int count(Node* arg);

int main(void) {

    Node* a = nullptr; //LL
    Node* temp = nullptr; //iterator
    string userin = "err";

    pushBack(a, "Does");
    pushBack(a, "this");
    pushBack(a, "work");

    temp = a;
    temp = temp->next;

    insert(temp, "thing");



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

void insert(Node* target, string contents){

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
