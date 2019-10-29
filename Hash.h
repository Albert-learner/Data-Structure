#pragma once
#include <iostream>
using namespace std;

#define NODE_CNT 7

class Node
{
public:
	int key;
	bool empty;
	Node *next;


	Node(int key, bool empty)
	{
		this->key = key;
		this->empty = empty;
		this->next = NULL;
	}
	friend class Hash;
};

class Hash
{
public:
	Node *table;

	Hash()
	{
		Node **htable = new Node*[NODE_CNT];

		for (int i = 0; i < NODE_CNT; i++)
		{
			htable[i] = NULL;
		}
	}
	int hashKey(int key);
	int findKey(int key);
	void finding(int key);
	void insertKey(int key);
	void deleteKey(int key);
};