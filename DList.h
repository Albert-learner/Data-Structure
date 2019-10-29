#pragma once
#include <iostream>
#include <string>
using namespace std;

typedef struct
{
	string name;
	int weight;
	int height;
	Node *next;
	Node *prev;
}Node;

class DList
{
private:
	Node *head;

};