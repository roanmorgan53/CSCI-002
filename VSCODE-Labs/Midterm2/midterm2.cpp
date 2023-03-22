//Roan Morgan
//Midterm: Hardcode a Singly Linked List
//3.20.23
#include <iostream>
#include <iomanip>
using namespace std;

template<class T>
class Node {
public:
	T obj;
	Node* next;
	Node* prev;
};

template<typename T>
void printForward(Node<T>* head);

template<typename T>
void printReverse(Node<T>* head);

template<typename T>
int countElement(Node<T>* head);

template<typename T>
void delete2nd(Node<T>* head);


int main(void) {
	
	//project description
	cout << "Hardcode a Singly Linked List\n" << endl;

    Node<string>* head = new Node<string>;
    Node<string>* cur = head;
    Node<string>* prev;

    cur->prev = nullptr;
    cur->obj = "C++";
    prev = cur;
    cur->next = new Node<string>;
    cur = cur->next;
    cur->prev = prev;

    cur->obj = "Data";
    prev = cur;
    cur->next = new Node<string>;
    cur = cur->next;
    cur->prev = prev;

    cur->obj = "Structure";
    cur->next = nullptr;

    printForward(head);

    cout << endl;

    printReverse(head);

    cout << endl;
     
    cout << countElement(head) << " elements in the list...\n" << endl;

    //delete the second element
    delete2nd(head);

    printForward(head);

    cout << endl;

    printReverse(head);





	return(0);
}

template<typename T>
void printForward(Node<T>* head) {
    Node<T>* cur = head;
    if (cur == nullptr) {
        cout << "List Empty" << endl;
    }
    else {
        do {
            cout << cur->obj << endl;
            cur = cur->next;
        } while (cur != nullptr);
    }

}

template<typename T>
void printReverse(Node<T>* head) {
    Node<T>* cur = head;
    if (cur == nullptr) {
        cout << "List Empty" << endl;
    }
    else {
        //iterate to end;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cout << cur->obj << endl;
        while (cur->prev != nullptr) {
            cur = cur->prev;
            cout << cur->obj << endl;
        }
    }
}

template<typename T>
int countElement(Node<T>* head)
{
    Node<T>* cur = head;
    int count = 1;

    while (cur->next != nullptr) {
        count++;
        cur = cur->next;
    };
    return count;
}

template<typename T>
void delete2nd(Node<T>* head){
    Node<T>* cur = head;
    Node<T>* prev;
    Node<T>* next;

    prev = cur;
    cur = cur->next;
    next = cur->next;


    cur = head;
    prev = cur;
    cur->next = next;
    next->prev = head;

}
