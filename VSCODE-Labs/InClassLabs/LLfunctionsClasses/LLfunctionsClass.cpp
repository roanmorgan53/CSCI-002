// Notes: Singly Linked List 
// An abstraction of an array.

#include <iostream> 
#include <string>
using namespace std;

// Class that defines the node object
class Node {
private:
 string item;
 Node* nextPtr;
 Node* prevPtr;

public:
 //constructors
 Node();
 Node(string);
 Node(string, Node*);
 Node(string, Node*, Node*);

 //Accessor Methods
 void setItem(string);
 string getItem();
 void setNextPtr(Node*);
 Node* getNextPtr();
 void setPrevPtr(Node*);
 Node* getPrevPtr();

 //functions

};

struct SinglyLinkedList{
    Node* head;

    void pushBack(string arg);
};

//regular c-type function for printing the Linked List
void printStringList(Node* beginningNodePtr);
void printStringListReverse(Node* beginningNodePtr);

void pushBack(string);

int main(void) {

SinglyLinkedList a;
a.pushBack("Hello");




}

//Node Implementation
Node::Node()
{
 setItem(""); //default to empty string
 setNextPtr(nullptr); //default to null pointer
 setPrevPtr(nullptr);
}

Node::Node(string arg)
{
 setItem(arg);
 setNextPtr(nullptr);
 setPrevPtr(nullptr);

}

Node::Node(string arg, Node* argPtr)
{
 setItem(arg);
 setNextPtr(argPtr);
 setPrevPtr(nullptr);
}
Node::Node(string arg, Node* argNextPtr, Node* argPrevPtr)
{
 setItem(arg);
 setNextPtr(argNextPtr);
 setPrevPtr(argPrevPtr);
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

void Node::setPrevPtr(Node * arg)
{
 prevPtr = arg;
}

Node * Node::getPrevPtr()
{
 return prevPtr;
}

void printStringList(Node* arg){
    Node* cur = arg;
    
    while (cur != nullptr)
    {
        cout << cur->getItem() << endl;
        cur = cur->getNextPtr();
    }
    
}

void pushBack(string arg){

}