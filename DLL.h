#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Node
{
	string name;
	int weight;
	int height;
	Node *next;
	Node *prev;
};

class DList
{
private:
	Node *head;
	

public:
	DList()
	{
		head = NULL;
	}

	void insertList(string n, int w, int h);
	void deleteList(string key);
	void backwardList();
	void forwardList();
	void searchList(string key);
	void quit();
	bool isEmpty();
	int listLength();
	void locateN(int n);
};