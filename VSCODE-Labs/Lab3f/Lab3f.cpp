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
	Node() {
		content = "";
		next = nullptr;
		prev = nullptr;
	}
	Node(string c) {
		content = c;
		next = nullptr;
		prev = nullptr;
	}
	Node(string c, Node* n, Node* p) {
		content = c;
		next = n;
		prev = p;
	}
	~Node() {
		//cout << "Node Nuked" << endl;
	}

	//get and set methods
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


	void setContent(string c) {
		content = c;
	}
	void setNext(Node* n) {
		next = n;
	}
	void setPrev(Node* p) {
		prev = p;
	}
};

class DoublyLinkedList {
private:
	Node* head;
	Node* tail;
public:
	DoublyLinkedList() {
		head = nullptr;
		tail = nullptr;
	}

	//get and sets
	Node* getHead(void) {
		return head;
	}
	Node* getTail(void) {
		return tail;
	}

	//useful methods
	void pushBack(string c) {
		Node* newNode = new Node(c);
		if (head == nullptr) {
			head = newNode; 
			tail = newNode;
		}
		else {
			tail->setNext(newNode);
			newNode->setPrev(tail);
			tail = newNode;
		}
	};

	void popBack(void) {
		Node* previous = tail->getPrev();
		previous->setNext(nullptr);
		delete tail;
		tail = previous;
	};

	void pushFront(string c) {
		Node* newNode = new Node(c);
		head->setPrev(newNode);
		Node* oldHead = head;
		head = head->getPrev();
		head->setNext(oldHead);
	};

	void insertAfter(string c, Node* location) {
		Node* newNode = new Node(c);
		Node* locNext = location->getNext();
		location->setNext(newNode);
		newNode->setPrev(location);
		newNode->setNext(locNext);
	};

	void nuke(void) {
		Node* buddy = head;

		while (buddy != nullptr) {
			Node* rat = buddy->getNext();
			delete buddy;
			buddy = rat;

		}
	}

	Node* searchFor(string data) {
		Node* cur = head;

		while (cur->getContent() != data && cur->getNext() != nullptr) {
			cur = cur->getNext();
		}

		if(cur->getContent() == data){
			return cur; 
		}
		else {
			return nullptr;
		}
	};

	int size(void) {
		Node* cur = head;

		int count = 0;
		while (cur->getNext() != nullptr) {
			count++;
			cur = cur->getNext();
		}

		return count;
	}

};

void print(DoublyLinkedList wordList) {
	Node* cur = wordList.getHead();

	if (wordList.getHead() == nullptr) {
		cout << "Empty List" << endl;
		return;
	}

	cout << "Contents: ";
	while (cur->getNext() != nullptr) {
		if (cur->getNext()->getNext() != nullptr) {
			cout << cur->getContent() << ", ";
		}
		else {
			cout << cur->getContent() << endl;
		}
		cur = cur->getNext();
	}
};

int main(void) {

	//init dll
	DoublyLinkedList nameList;

	//push joe back 5 times
	for (int i = 0; i < 5; i++) {
		nameList.pushBack("Jane");
	}

	//get rid of 2 janes
	for (int i = 0; i < 1; i++) {
		nameList.popBack();
	}

	//put 3 Jacks in the front
	for (int i = 0; i < 3; i++) {
		nameList.pushFront("Jack");
	}

	//insert Marc after the first Jack
	nameList.insertAfter("Marc", nameList.getHead());

	//print the list
	print(nameList);

	//count the list
	cout << "# members: " << nameList.size() << endl;

	//search the list for string
	string search = "Marc";
	if (nameList.searchFor(search) != nullptr) {
		cout << search << " found at address " << nameList.searchFor(search) << endl;
	}
	else {
		cout << search << " not found" << endl;
	}

	//deallocate
	nameList.nuke();

	return 0;
}

