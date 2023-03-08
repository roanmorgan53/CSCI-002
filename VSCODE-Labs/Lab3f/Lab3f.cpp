//Roan Morgan
//Lab 3f: Methods for Doubly Linked Lists
//3.8.23
#include <iostream>
#include <string>
using namespace std;

class Node {
private:
	//init variables
	string content;
	Node* next;
	Node* prev;

public:
	//constructors
	Node();
	Node(string);
	Node(string, Node*);
	Node(string, Node*, Node*);

	//deconstructor
	~Node() { cout << "BOOM" << endl; }

	//get & sets
	string getContent(void){
		return content;
	};
	Node* getNext(void) {
		return next;
	};
	Node* getPrev(void) {
		return prev;
	};
	void setContent(string arg) {
		content = arg;
	};
	void setNext(Node* nextPtr) {
		next = nextPtr;
	};
	void setPrev(Node* prevPtr) {
		prev = prevPtr;
	};

};

class DoublyLinkedList {
private:
	Node* head;
	Node* tail;

public:
	//constructor
	DoublyLinkedList() {
		head = nullptr;
		tail = nullptr;
	}

	//get & sets
	Node* getHead(void) {
		return head;
	};
	Node* getTail(void) {
		return tail;
	};

	void pushBack(string);
	void print(void);

};

int main(void) {
	//seed random
	srand(time(0));

	//init variables
	DoublyLinkedList list;
	int count = 10;
	string randString[] = {"Apple", "Banana", "Watermelon", "Bread", "House"};

	//populate the list
	for (int i = 0; i < 10; i++) {
		list.pushBack(randString[rand() % 5]);
	}

	//print the list
	list.print();
	
	return 0;
}

Node::Node()
{
	next = new Node();
	content = "N/A";
}

Node::Node(string arg)
{
	content = arg;
}

Node::Node(string arg, Node* argNext)
{
	content = arg;
	next = argNext;
}

Node::Node(string arg, Node* argNext, Node* argPrev)
{
	content = arg;
	next = argNext;
	prev = argPrev;
}

void DoublyLinkedList::pushBack(string arg)
{
	Node* cur = getHead();

	if (cur == nullptr) {
		cur = new Node(arg);
		cur->setPrev(cur);
		cur->setNext(nullptr);
		return;
	}
	else {
		while (cur->getNext() != nullptr) {
			cur->setPrev(cur);
			cur = cur->getNext();
		}
		cur->setNext(new Node(arg));
		cur->setPrev(cur);
		cur = cur->getNext();
		cur->setNext(nullptr);
	}


}

void DoublyLinkedList::print(void)
{
	Node* cur = getHead();

	if (cur == nullptr) {
		cout << "Empty List";
		return;
	}
	else {
		while (cur->getNext() != nullptr) {
			cout << cur->getContent() << ", ";
			cur = cur->getNext();
		}
	}
}
