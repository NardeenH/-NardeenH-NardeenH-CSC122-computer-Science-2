

#include <iostream>
#ifndef lINKEDlIST_H
#define lINKEDlIST_H
using namespace std;


typedef struct Node {
	double data;
	Node* next;
	Node* prev;
}Node;

class LinkedList {
private:
	Node* head;
	Node* tail;
public:
	
	LinkedList() {
		head = nullptr;
		tail = nullptr;
	}

	void addValue(double data) {
		Node* node = new Node();
		node->data = data;
		node->next = head;
		node->prev = nullptr;
		if (head == nullptr) {
			head = node;
			tail = node;
			return;
		}
		head->prev = node;
		head = node;
	}
	void deleteValue(double data) {
		for (Node* temp = head; temp != nullptr; temp = temp->next) {
			if (temp->data == data) {
				if (temp->prev == nullptr)
					head = temp->next;
				else
					temp->prev->next = temp->next;
				if (temp->next == nullptr)
					tail = tail->prev;
				else
					temp->next->prev = temp->prev;
				delete temp;
				return;
			}
		}
	}
	void displayListForward() {
		for (Node* temp = head; temp != nullptr; temp = temp->next)
			cout << temp->data << " ";
		cout << endl;
	}
	void displayListBackward() {
		for (Node* temp = tail; temp != nullptr; temp = temp->prev)
			cout << temp->data << " ";
		cout << endl;
	}
};

#endif
