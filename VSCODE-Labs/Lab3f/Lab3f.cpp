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

	void popBack(void){
		Node* last = getLast();
		delete last->getNext();
		last = nullptr;


	}

};

void print(Node* arg);

int main(void) {
	//make a node ptr
	Node* fruitList = new Node();
	Node* cur = fruitList;

	//strings array
	string test = "test ";

	//instantiate
	for (int i = 0; i < 5; i++) {
		cur->setContent(test);
		cur->setNext(new Node());
		cur->setPrev(cur);
		cur = cur->getNext();
	}

	cur->pushBack("Pushed Back");

	print(fruitList);

	cur->popBack();

	print(fruitList);



	return 0;
}

void print(Node* arg){
	Node* cur = arg;
	while(cur->getNext() != nullptr){
		cout << cur->getContent() << endl;
		cur = cur->getNext();
	}

	delete cur;
}