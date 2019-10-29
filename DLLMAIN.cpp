#include "DLL.h"
#include <fstream>

int main()
{
	ifstream fin;
	fin.open("data.txt");

	if (fin.fail())
	{
		cout << "File open Failed" << "\n";
		exit(1);
	}

	DList dlist;
	string name;
	int weight, height;
	for (int i = 0; i < 4; i++)
	{
		fin >> name >> weight >> height;
		dlist.insertList(name, weight, height);
	}
	dlist.forwardList();

	dlist.searchList("lee");
	dlist.deleteList("lee");
	dlist.forwardList();
	dlist.insertList("park", 73, 176);
	dlist.forwardList();
	dlist.locateN(2);
	dlist.backwardList();
	return 0;
}