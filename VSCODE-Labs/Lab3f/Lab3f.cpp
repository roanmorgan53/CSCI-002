//Roan Morgan
//Lab 3f
//3.1.23
#include <iostream>
#include <cstdlib> 
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

};

class DoublyLinkedList{
    private:
        Node* head;
    public:
        DoublyLinkedList(void);
        
        void setHead(Node*);
        Node* getHead(void);
        void pushBack(string);

};

//regular c-type function for printing the Linked List
void printStringList(Node* beginningNodePtr);
void printStringListReverse(Node* beginningNodePtr);



int main(void){

    DoublyLinkedList list;

    list.pushBack("Joe");
    list.pushBack("Mama");
    list.pushBack("yo");

    
    printStringList(list.getHead());
    printStringListReverse(list.getHead());



    return 0;
}

void printStringList(Node* beginningNodePtr) {

 Node* tempNodePtr = beginningNodePtr;

 cout << "Forward:" << endl;
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
 cout << "" << endl;

}
void printStringListReverse(Node* beginningNodePtr) {

 Node* tempNodePtr = beginningNodePtr;

 if (tempNodePtr == nullptr) {
 cout << "List Empty" << endl;
 }
 else {
 while (tempNodePtr->getNextPtr() != nullptr) {
 tempNodePtr = tempNodePtr->getNextPtr();
 };
 // now tempNodePtr is at the end;
 cout << "Reverse:" << endl;
 while (tempNodePtr->getPrevPtr() != nullptr) {
 cout << tempNodePtr->getItem() << endl;
 tempNodePtr = tempNodePtr->getPrevPtr();
 };
 cout << tempNodePtr->getItem() << endl;
 cout << "" << endl;
 }

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

DoublyLinkedList::DoublyLinkedList(void){
    setHead(nullptr);
}

void DoublyLinkedList::setHead(Node* arg){
    head = arg;
}

Node* DoublyLinkedList::getHead(){
    return head;
}

void DoublyLinkedList::pushBack(string arg){
    Node* temp = getHead();
    Node* cur = new Node(arg);

    //one-off when list is empty
    if(getHead() == nullptr){
        setHead(cur);
    }
    else{
        while(temp->getNextPtr() != nullptr){
            temp = temp->getNextPtr();

        }

        temp->setNextPtr(cur);
        cur->setPrevPtr(getHead());
    }


}