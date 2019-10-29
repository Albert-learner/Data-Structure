#pragma once
#include <iostream>
using namespace std;

#define MAX_SIZE 7

class Hash
{
public:
	int key;
	bool empty;

	Hash()
	{
		empty = true;
	}
};

int hashKey(int key);
int findKey(int key);
void finding(int key);
void insertKey(int key);
void deleteKey(int key);
void printMatrix();

