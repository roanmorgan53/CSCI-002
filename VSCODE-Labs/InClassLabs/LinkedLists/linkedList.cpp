#include <iostream>
#include <cstdlib>
using namespace std;

struct Node{
    string contents;
    Node* next;
    
};

int main(void){

    Node* a = new Node();
 
    a->contents = "Hello";

    a->next = new Node();
    a->next->contents = "Linked";

    a->next->next = new Node();
    a->next->next->contents = "Lists";
    a->next->next->next = nullptr;

    Node* cur = a; //iterator

    do{
        cout << cur->contents << endl;
        cur = cur->next; //iteration step

    }while(cur != nullptr);

    delete a;

    return(0);
}