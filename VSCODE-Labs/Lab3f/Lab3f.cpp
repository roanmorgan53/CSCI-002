//Roan Morgan
//3.10.23
//Lab 3f
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Node {
private:
	string content;
	Node* next;
	Node* prev;
public:
	//constructors
	Node() {
		content = "";
		next = nullptr;
		prev = nullptr;
	};
	Node(string w) {
		content = w;
	};
	Node(string w, Node* n, Node* p) {
		content = w;
		next = n;
		prev = p;
	}

	//get and sets
	string getContent(void) {
		return content;
	}
	Node* getNext(void) {
		return next;
	}
	Node* getPrev(void) {
		return prev;
	}
	Node* getFirst(void) {
		Node* cur = this;
		while (cur->getPrev() != nullptr) {
			cur = cur->getPrev();
		}
		return cur;
	}
	Node* getLast(void) {
		Node* cur = this;
		while (cur->getNext() != nullptr) {
			cur = cur->getNext();
		}
		return cur;
	}

	void setContent(string w) {
		content = w;
	}
	void setNext(Node* n) {
		next = n;
	}
	void setPrev(Node* p) {
		prev = p;
	}

	//useful methods
	void pushBack(string w) {
		Node* last = getLast();
		Node* newNode = new Node(w);
		last->setNext(newNode);
		newNode->setPrev(last);
	}




};

int main(void) {
	//seed random
	srand(time(0));
	
	//make a node ptr
	Node* fruitList;
	Node* cur = fruitList;

	//strings array
	string randStrings[] = { "Apple", "Banana", "Watermelon" };

	//instantiate
	for (int i = 0; i < 10; i++) {
		cur->setContent(randStrings[rand() % 3]);
		cur->setNext(new Node());
		cur->setPrev(cur);
		cur = cur->getNext();

	}


	return 0;
}