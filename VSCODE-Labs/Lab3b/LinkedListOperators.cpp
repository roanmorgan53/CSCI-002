//Roan Morgan
//Lab 3b: Linked List Operators
//2.16.23
#include <iostream>
#include <cstdlib>
using namespace std;

struct Node{
    Node* next;
    string contents;

};

int main(void){

    Node* a = nullptr; //LL
    Node* cur = nullptr; //iterator

    char userin = 'y';

    do{


        cout << "\n would you like to add another element (y/n):";
        cin >> userin;
        
    }while(userin == 'y');

    return(0);
}