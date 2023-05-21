//Roan Morgan
//First Binary Tree
//4.17.23
#include <iostream>
#include <iomanip>
using namespace std;

class Node {
public:
	Node(int);
	int data;
	Node* left;
	Node* right;

	int findDepth(int);
	void report(void);
};

class BinaryTree {
public:
	Node* root;

	int findDepth(int);
};


int main(void) {

	BinaryTree a;
	Node* cur = nullptr;

	
	//empty search tree
	a.root = nullptr;

	//first node
	a.root = new Node(8);
	a.root->left = nullptr;
	a.root->right = nullptr;

	cur = a.root;

	//second node
	cur->left = new Node(3);
	cur->right = new Node(10);
	cur = cur->left;
	cur->left = nullptr;
	cur->right = nullptr;
	
	//third node
	cur->left = new Node(1);
	cur->right = new Node(6);
	cur = cur->right;
	cur->left = nullptr;
	cur->right = nullptr;

	//fourth node
	cur->left = new Node(4);
	cur->right = new Node(7);
	cur = a.root->right;
	cur->left = nullptr;
	cur->right = nullptr;

	//5th node
	cur->right = new Node(14);
	cur = cur->right;
	cur->left = nullptr;
	cur->right = nullptr;

	//6th node
	cur->left = new Node(13);

	a.root->report();


	return(0);
}

int BinaryTree::findDepth(int i) {
	if (root)
		return (root->findDepth(i));
	else {
		return(-1);
	}
};

Node::Node(int _data)
{
	data = _data;
}

int Node::findDepth(int i) {
	if (i == data) return(0);

	int d;

	if (i < data) {
		if (left) d = left->findDepth(i);
		else d = -1;
	}
	if (i > data) {
		if (right) d = right->findDepth(i);
		else d = -1;
	}
	if (d == -1) return(-1);
	else return(d + 1);
};

void Node::report() {
	cout << data << " ";
	if (right) right->report();
	if (left) left->report();
};