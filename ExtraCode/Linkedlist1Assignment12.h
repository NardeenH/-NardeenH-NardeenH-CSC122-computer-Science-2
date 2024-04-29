

#include <iostream>
#ifndef lINKEDlIST_H
#define lINKEDlIST_H
using namespace std;


typedef struct Node {
	double data;
	Node* next;
	Node* prev;
};


class LinkedList {
private:
	Node* head;
	Node* tail;
	int size;
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
	int get_size() {
		return size;
	}
	double& operator[](int index) {
		if (index < 0 || index >= size) {
			throw std::out_of_range("Index out of range");
		}

		Node* temp = head;
		for (int i = 0; i < index; i++) {
			temp = temp->next;
		}
		return temp->data;
	}
	LinkedList& operator+=(double d) {
		addValue(d);
		return *this;
	}
};

bool is_prime(int number) {
	if (number <= 1) {
		return false;
	}
	for (int i = 2; i * i <= number; i++) {
		if (number % i == 0) {
			return false;
		}
	}
	return true;
}

LinkedList prime_factorization(int number) {
	LinkedList factors;
	for (int i = 2; i <= number; i++) {
		while (number % i == 0) {
			factors += i;
			number /= i;
		}
	}
	return factors;
}
	


#endif
