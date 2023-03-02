//Roan Morgan
//Lab 3d
//3.1.23
#include <iostream>
#include <string>
using namespace std;

struct Node {
	Node* next;
	int contents;
};

void print(Node*);

Node* merge(Node* head, Node* head2);

int main(void) {

	//init lists
	Node* list = new Node();
	Node* list2 = new Node();

	//init iterator
	Node* cur = list;

	//instantiate contents L1
	for (int i = 0; i < 5; i++) {
		cur->contents = i;
		cur->next = new Node();
		cur = cur->next;
	}

	//set null
	cur->next = nullptr;

	//set iterator to the beginning of the second list
	cur = list2;

	//instantiate contents L2
	for (int i = 5; i < 11; i++) {
		cur->contents = i;
		cur->next = new Node();
		cur = cur->next;
	}

	//set null
	cur->next = nullptr;

	//assign the merge to a node*
	Node* list3 = merge(list, list2);

	//print results
	cout << "First List: {";
	print(list);
	cout << "}\n";
	cout << "Second List: {";
	print(list2);
	cout << "}\n";
	cout << "Merged List: {";
	print(list3);
	cout << "}\n";

	return 0;
}

void print(Node* list) {
	Node* cur = list;
	
	if (cur == nullptr) {
		cout << "empty list" << endl;
		return;
	}

	while (cur->next != nullptr) {
		cout << cur->contents << ", ";
		cur = cur->next;
	}
}

Node* merge(Node* head, Node* head2)
{
	//init merged LL as well as iterator
	Node* head3 = new Node();
	Node* temp = head3;
	Node* cur = head;

	//run through the first list and assign the contents to the merged contents
	while (cur->next != nullptr) {
		temp->contents = cur->contents;
		cur = cur->next;
		temp->next = new Node();
		temp = temp->next;
	}

	cur = head2;

	//again!
	while (cur->next != nullptr) {
		temp->contents = cur->contents;
		cur = cur->next;
		temp->next = new Node();
		temp = temp->next;
	}

	return head3;
}
