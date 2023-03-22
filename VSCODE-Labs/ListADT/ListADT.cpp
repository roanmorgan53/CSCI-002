//Roan Morgan
//3.13.23
//List ADT
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
template <class T>
class Node {
private:
	T content;
	Node<T>* next;
	Node<T>* prev;
public:
	Node<T>();
	Node<T>(T c);
	Node<T>(T c, Node* n, Node* p);
	~Node<T>();
	//get and set methods
	T getContent(void);
	Node<T>* getNext(void);
	Node<T>* getPrev(void);
	Node<T>* getFirst(void);
	Node<T>* getLast(void);
	void setContent(T c);
	void setNext(Node<T>* n);
	void setPrev(Node<T>* p);
};

template <class T>
class DoublyLinkedList {
private:
	Node<T>* head;
	Node<T>* tail;
public:
	DoublyLinkedList<T>();

	//get and sets
	Node<T>* getHead(void);
	Node<T>* getTail(void);

	//useful methods
	void pushBack(T c);
	void popBack(void);
	void pushFront(T c);
	void insertAfter(T c, Node<T>* location);
	void nuke(void);
	Node<T>* searchFor(T data);
	int size(void);
};
template <typename T>
void print(DoublyLinkedList<T> wordList) {
	Node<T>* cur = wordList.getHead();
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
	DoublyLinkedList<string> nameList;

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
		cout << search << " found at address " << nameList.searchFor(search) <<
			endl;
	}
	else {
		cout << search << " not found" << endl;
	}

	//deallocate
	nameList.nuke();
	return 0;
}

template <typename T>
Node<T>::Node() {
	content = T();
	next = nullptr;
	prev = nullptr;
};

template <typename T>
Node<T>::Node(T c) {
	content = c;
	next = nullptr;
	prev = nullptr;
};

template <typename T>
Node<T>::Node(T c, Node* n, Node* p) {
	content = c;
	next = n;
	prev = p;
};

template <typename T>
Node<T>::~Node() {
	//cout << "Node Nuked" << endl;
}

//get and set methods
template <typename T>
T Node<T>::getContent(void) {
	return content;
}

template <typename T>
Node<T>* Node<T>::getNext(void) {
	return next;
}

template <typename T>
Node<T>* Node<T>::getPrev(void) {
	return prev;
}

template <typename T>
Node<T>* Node<T>::getFirst(void) {
	Node<T>* cur = this;
	while (cur->getPrev() != nullptr) {
		cur = cur->getPrev();
	}
	return cur;
}

template <typename T>
Node<T>* Node<T>::getLast(void) {
	Node<T>* cur = this;
	while (cur->getNext() != nullptr) {
		cur = cur->getNext();
	}
	return cur;
}

template <typename T>
void Node<T>::setContent(T c) {
	content = c;
}

template <typename T>
void Node<T>::setNext(Node<T>* n) {
	next = n;
}

template <typename T>
void Node<T>::setPrev(Node<T>* p) {
	prev = p;
}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
	head = nullptr;
	tail = nullptr;
}

//get and sets
template <typename T>
Node<T>* DoublyLinkedList<T>::getHead(void) {
	return head;
}

template <typename T>
Node<T>* DoublyLinkedList<T>::getTail(void) {
	return tail;
}

//useful methods
template <typename T>
void DoublyLinkedList<T>::pushBack(T c) {
	Node<T>* newNode = new Node<T>(c);
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

template <typename T>
void DoublyLinkedList<T>::popBack(void) {
	Node<T>* previous = tail->getPrev();
	previous->setNext(nullptr);
	delete tail;
	tail = previous;
};

template <typename T>
void DoublyLinkedList<T>::pushFront(T c) {
	Node<T>* newNode = new Node<T>(c);
	head->setPrev(newNode);
	Node<T>* oldHead = head;
	head = head->getPrev();
	head->setNext(oldHead);
};

template <typename T>
void DoublyLinkedList<T>::insertAfter(T c, Node<T>* location) {
	Node<T>* newNode = new Node<T>(c);
	Node<T>* locNext = location->getNext();
	location->setNext(newNode);
	newNode->setPrev(location);
	newNode->setNext(locNext);
};

template <typename T>
void DoublyLinkedList<T>::nuke(void) {
	Node<T>* buddy = head;
	while (buddy != nullptr) {
		Node<T>* rat = buddy->getNext();
		delete buddy;
		buddy = rat;
	}
}

template <typename T>
Node<T>* DoublyLinkedList<T>::searchFor(T data) {
	Node<T>* cur = head;
	while (cur->getContent() != data && cur->getNext() != nullptr) {
		cur = cur->getNext();
	}
	if (cur->getContent() == data) {
		return cur;
	}
	else {
		return nullptr;
	}
};

template <typename T>
int DoublyLinkedList<T>::size(void) {
	Node<T>* cur = head;
	int count = 0;
	while (cur->getNext() != nullptr) {
		count++;
		cur = cur->getNext();
	}
	return count;
}