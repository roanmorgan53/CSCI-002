//Roan Morgan
//Lab 3g
//3.12.23
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

class Circle {
private:
	double radius;
	string color;
public:
	//constructor
	Circle() {
		radius = -1;
		color = "white";
	}
	Circle(double r, string c) {
		radius = r;
		color = c;
	};

	//get methods
	double getRadius(void) {
		return radius;
	};
	string getColor(void) {
		return color;
	};

	//set methods
	void setRadius(double r) {
		radius = r;
	};
	void setColor(string c) {
		color = c;
	};

};

class Node {
private:
	Circle content;
	Node* next;
	Node* prev;
public:
	Node() {
		content = Circle(-1, "white");
		next = nullptr;
		prev = nullptr;
	}
	Node(Circle c) {
		content = c;
		next = nullptr;
		prev = nullptr;
	}
	Node(Circle c, Node* n, Node* p) {
		content = c;
		next = n;
		prev = p;
	}
	~Node() {
		//cout << "Node Nuked" << endl;
	}

	//get and set methods
	Circle getContent(void) {
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


	void setContent(Circle c) {
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
	void pushBack(Circle c) {
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

	void pushFront(Circle c) {
		Node* newNode = new Node(c);
		head->setPrev(newNode);
		Node* oldHead = head;
		head = head->getPrev();
		head->setNext(oldHead);
	};

	void insertAfter(Circle c, Node* location) {
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

	Node* searchForColor(string data) {
		Node* cur = head;

		while (cur->getContent().getColor() != data && cur->getNext() != nullptr) {
			cur = cur->getNext();
		}

		if (cur->getContent().getColor() == data) {
			return cur;
		}
		else {
			return nullptr;
		}
	};

	Node* searchForRadius(double data) {
		Node* cur = head;

		while (cur->getContent().getRadius() != data && cur->getNext() != nullptr) {
			cur = cur->getNext();
		}

		if (cur->getContent().getRadius() == data) {
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
	int count = 1;

	if (wordList.getHead() == nullptr) {
		cout << "Empty List" << endl;
		return;
	}

	cout << "Circle List: " << endl;
	while (cur->getNext() != nullptr) {
		cout << count << ")\t Color: " << cur->getContent().getColor() << "\t\tRadius: " << cur->getContent().getRadius() << endl;
		cur = cur->getNext();
		count++;
	}
};

int main(void) {
	srand(time(0));
	cout << setprecision(4) << fixed;

	//init dll
	DoublyLinkedList circleList;

	//make some random colors
	string colors[] = { "white", "blue", "red", "green", "rainbow" };

	//make 50 circles and push them back into the list at runtime
	Circle temp;
	for (int i = 0; i < 51; i++) {
		temp.setColor(colors[rand() % 5]);
		temp.setRadius(1.0*rand() / RAND_MAX + rand() % 100);
		circleList.pushBack(temp);
	}

	print(circleList);

	

	return 0;
}

