#include <iostream>
#include <string>
#include <fstream>
#include "DLinkedList.h"
using namespace std;

int main()
{
	ifstream fin;
	fin.open("data.txt");

	int i;
	DList p;
	for (i = 0; i < 5; i++)
	{
		string name;
		int weight, height;
		fin >> name >> weight >> height;
		p.insert(name, weight, height);
	}
	
	p.forward();
	p.search("lee");
	p.backword();
	p.locateN(3);
	return 0;
}