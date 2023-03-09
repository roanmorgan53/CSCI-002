//Roan Morgan
//Lab 3e
//3.3.23

#include <iostream>  
#include <string>
using namespace std;

// Class that defines the node object
class Node {
private:
    char item;
    Node* nextPtr;

public:
    //constructors
    Node();
    Node(char);
    Node(char, Node*);

    //Accessor Methods
    void setItem(char);
    char getItem();
    void setNextPtr(Node*);
    Node* getNextPtr();

};

//regular c-type function for printing the Linked List
void printCharList(Node* beginningNodePtr);

int main(void) {
    //seed the random library
    srand(time(0));

    //init variables
    Node* charList = new Node();
    Node* cur = charList;
    char randomChar = ' ';
    int size = 100;

    //Title
    cout << "Lab 3e: 100 Chars in Linked List" << endl << endl;

    //populate the list with size amount of chars
    for (int i = 0; i < size; i++) {
        randomChar = rand() % 26 + 97;
        cur->setItem(randomChar);
        cur->setNextPtr(new Node());
        cur = cur->getNextPtr();

    }

    //bring cur back to the beginning
    cur = charList;

    //print
    printCharList(charList);



    return (0);
}

void printCharList(Node* beginningNodePtr) {

    Node* tempNodePtr = beginningNodePtr;
    int i = 1;

    if (tempNodePtr == nullptr) {
        cout << "List Empty" << endl;
    }
    else {
        while (tempNodePtr->getNextPtr() != nullptr) {
            cout << i << ") ";
            cout << tempNodePtr->getItem() << endl;
            tempNodePtr = tempNodePtr->getNextPtr();
            i++;
        };
        cout << tempNodePtr->getItem() << endl;
        i = 0;
    }

}


//Node Implementation
Node::Node()
{
    setItem(' '); //default to empty char
    setNextPtr(nullptr); //default to null pointer
}

Node::Node(char arg)
{
    setItem(arg);
    setNextPtr(nullptr);
}

Node::Node(char arg, Node* argPtr)
{
    setItem(arg);
    setNextPtr(argPtr);
}

void Node::setItem(char arg)
{
    item = arg;
}

char Node::getItem()
{
    return item;
}

void Node::setNextPtr(Node* argPtr)
{
    nextPtr = argPtr;
}

Node* Node::getNextPtr()
{
    return nextPtr;
}