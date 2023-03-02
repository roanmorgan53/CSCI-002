//Roan Morgan
//Lab3e
//3.2.23
// Class that defines the node object
#include <iostream>
#include <string>
using namespace std;

class Node {
private:
    string item;
    Node* nextPtr;

public:
    //constructors
    Node();
    Node(string);
    Node(string, Node*);

    //Accessor Methods
    void setItem(string);
    string getItem();
    void setNextPtr(Node*);
    Node* getNextPtr();

};

//regular c-type function for printing the Linked List
void printStringList(Node* beginningNodePtr);

int main(void) {

    return (0);
}

void printStringList(Node* beginningNodePtr) {

    Node* tempNodePtr = beginningNodePtr;

    cout << "******************" << endl;
    if (tempNodePtr == nullptr) {
        cout << "List Empty" << endl;
    }
    else {
        while (tempNodePtr->getNextPtr() != nullptr) {

            cout << tempNodePtr->getItem() << endl;
            tempNodePtr = tempNodePtr->getNextPtr();

        };
        cout << tempNodePtr->getItem() << endl;

    }
    cout << "******************" << endl;

}


//Node Implementation
Node::Node()
{
    setItem(""); //default to empty string
    setNextPtr(nullptr); //default to null pointer
}

Node::Node(string arg)
{
    setItem(arg);
    setNextPtr(nullptr);
}

Node::Node(string arg, Node* argPtr)
{
    setItem(arg);
    setNextPtr(argPtr);
}

void Node::setItem(string arg)
{
    item = arg;
}

string Node::getItem()
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