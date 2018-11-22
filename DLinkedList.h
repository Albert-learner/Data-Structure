#pragma once
#include <iostream>
#include <string>
using namespace std;

typedef struct Node {
	string name;
	int weight;
	int height;
	Node *next;
	Node *prev;
};

class DList {
private:
	Node * head;
	int cur;
public:
	DList() { head = 0; cur = 0; };
	void insert(string n, int w, int h);
	void deleteList(string key);
	void backword();
	void forward();
	void search(string key);
	void quit();
	bool isEmpty();
	void locateN(int n);
};

bool DList::isEmpty() {
	if (head == 0) {
		return true;
	}
	else
		return false;
}

void DList::insert(string n, int w, int h) {
	Node *temp = new Node();
	temp->name = n;
	temp->weight = w;
	temp->height = h;

	Node *p, *q;

	if (head == 0) {
		head = temp;
	}
	else if (temp->name < head->name) {
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
	else {
		p = head;
		while ((p != 0) && !(temp->name < p->name)) {
			q = p;
			p = p->next;
		}

		if (p != 0) {
			temp->next = p;
			temp->prev = q;
			q->next = temp;
			p->prev = temp;
		}
		else {
			q->next = temp;
			temp->prev = q;
		}
	}
}

void DList::deleteList(string key) {
	Node *p, *q;

	if (head == 0) {
		cout << "List is Empty!" << endl;
		return;
	}
	else if (head->name == key) {
		if (head->next != 0) {
			p = head;
			head = head->next;
			head->prev = 0;
			delete p;
		}
		else {
			head = 0;
		}
	}
	else {
		p = head;
		q = head;
		while ((p != 0) && !(p->name == key)) {
			q = p;
			p = p->next;
		}

		if (p->next != 0 && p->name == key) {
			q->next = p->next;
			p->next->prev = q;
			delete p;
		}
		else if (p->next == 0 && p->name == key) {
			q->next = 0;
			delete p;
		}
		else {
			cout << "No key in DList" << endl;
			return;
		}
	}


}

void DList::backword() {
	if (!isEmpty()) {
		cur = 1;
		Node* p = head;
		Node *q;
		while (p->next != 0) {
			p = p->next;
		}
		cout << "-----Backward List------" << endl;

		while (p != 0) {
			cout << p->name << " " << p->weight << " " << p->height << endl;
			p = p->prev;
		}
	}
	else {
		cout << "List is empty!" << endl;
	}
}

void DList::forward() {
	Node *p;

	if (!isEmpty()) {
		p = head;
		cur = 0;
		cout << "---- Forward List ----" << endl;
		while (p != 0) {
			cout << p->name << " " << p->weight << " " << p->height << endl;
			p = p->next;
		}
	}
	else {
		cout << " List is empty!" << endl;
	}
}

void DList::search(string key) {
	Node *p = head;

	while ((p != 0) && !(p->name == key)) {
		p = p->next;
	}
	if (p != 0) {
		cout << " ---- Search ----" << endl;
		cout << p->name << " " << p->weight << " " << p->height << endl;
	}
	else {
		cout << "key is not in DList" << endl;
	}
}

void DList::quit() {

	while (head != 0) {
		Node *p;
		p = head;
		head = head->next;
		delete p;
	}
}

void DList::locateN(int n) {
	Node *p;
	int pos = 1;
	int length = 1;

	p = head;
	while (p != 0) {
		p = p->next;
		length++;
	}

	if (cur == 1) {
		n = length - n;
	}

	if (head == 0) {
		cout << " List is Empty!" << endl;
	}
	else {
		p = head;
		while (pos != n) {
			p = p->next;
			pos++;
		}
	}
	cout << "---- Find Nth ----" << endl;
	cout << p->name << " " << p->weight << " " << p->height << endl;
}
