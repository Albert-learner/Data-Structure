#include "DLL.h"
#include <fstream>

int main()
{
	ifstream fin;
	fin.open("data.txt");

	DList dlist;

	for (int i = 0; i < 5; i++)
	{
		string name;
		int weight, height;
		fin >> name >> weight >> height;
		dlist.insertList(name, weight, height);
	}

	dlist.forwardList();
	dlist.searchList("lee");
	dlist.backwardList();
	dlist.locateN(3);
	return 0;
}