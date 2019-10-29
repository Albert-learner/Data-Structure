#pragma once
#include <iostream>
using namespace std;

class Node
{
private:
	int data;
	Node *next;

	Node(int value)
	{
		data = value;
		next = NULL;
	}
	friend class linkedStack;
};

class linkedStack
{
private:
	Node *head;

public:
	linkedStack()
	{
		head = NULL;
	}

	void createStack();
	int isEmpty();
	void push(int data);
	int pop();
	void displayStack();
	Node *invertStack(Node *head);
	void searchStack(int data);
	void invert() 
	{
		head = invertStack(head);
	}
};