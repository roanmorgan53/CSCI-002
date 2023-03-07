//Roan Morgan
<<<<<<< HEAD
//Lab 3e
//3.3.23

#include <iostream> 
#include <string>
using namespace std;

// Class that defines the node object
class Node {
private:
    char item;
=======
//Lab3e
//3.2.23
// Class that defines the node object
#include <iostream>
#include <string>
using namespace std;

class Node {
private:
    string item;
>>>>>>> b9bd6111eb3ca854b2ba7c479241ae24fff5970a
    Node* nextPtr;

public:
    //constructors
    Node();
<<<<<<< HEAD
    Node(char);
    Node(char, Node*);

    //Accessor Methods
    void setItem(char);
    char getItem();
=======
    Node(string);
    Node(string, Node*);

    //Accessor Methods
    void setItem(string);
    string getItem();
>>>>>>> b9bd6111eb3ca854b2ba7c479241ae24fff5970a
    void setNextPtr(Node*);
    Node* getNextPtr();

};

//regular c-type function for printing the Linked List
<<<<<<< HEAD
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


=======
void printStringList(Node* beginningNodePtr);

int main(void) {
>>>>>>> b9bd6111eb3ca854b2ba7c479241ae24fff5970a

    return (0);
}

<<<<<<< HEAD
void printCharList(Node* beginningNodePtr) {

    Node* tempNodePtr = beginningNodePtr;
    int i = 1;

=======
void printStringList(Node* beginningNodePtr) {

    Node* tempNodePtr = beginningNodePtr;

    cout << "******************" << endl;
>>>>>>> b9bd6111eb3ca854b2ba7c479241ae24fff5970a
    if (tempNodePtr == nullptr) {
        cout << "List Empty" << endl;
    }
    else {
        while (tempNodePtr->getNextPtr() != nullptr) {
<<<<<<< HEAD
            cout << i << ") ";
            cout << tempNodePtr->getItem() << endl;
            tempNodePtr = tempNodePtr->getNextPtr();
            i++;
        };
        cout << tempNodePtr->getItem() << endl;
        i = 0;
    }
=======

            cout << tempNodePtr->getItem() << endl;
            tempNodePtr = tempNodePtr->getNextPtr();

        };
        cout << tempNodePtr->getItem() << endl;

    }
    cout << "******************" << endl;
>>>>>>> b9bd6111eb3ca854b2ba7c479241ae24fff5970a

}


//Node Implementation
Node::Node()
{
<<<<<<< HEAD
    setItem(' '); //default to empty char
    setNextPtr(nullptr); //default to null pointer
}

Node::Node(char arg)
=======
    setItem(""); //default to empty string
    setNextPtr(nullptr); //default to null pointer
}

Node::Node(string arg)
>>>>>>> b9bd6111eb3ca854b2ba7c479241ae24fff5970a
{
    setItem(arg);
    setNextPtr(nullptr);
}

<<<<<<< HEAD
Node::Node(char arg, Node* argPtr)
=======
Node::Node(string arg, Node* argPtr)
>>>>>>> b9bd6111eb3ca854b2ba7c479241ae24fff5970a
{
    setItem(arg);
    setNextPtr(argPtr);
}

<<<<<<< HEAD
void Node::setItem(char arg)
=======
void Node::setItem(string arg)
>>>>>>> b9bd6111eb3ca854b2ba7c479241ae24fff5970a
{
    item = arg;
}

<<<<<<< HEAD
char Node::getItem()
=======
string Node::getItem()
>>>>>>> b9bd6111eb3ca854b2ba7c479241ae24fff5970a
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