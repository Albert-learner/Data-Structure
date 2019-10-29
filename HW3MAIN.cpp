#include "HW3.h"
#include <fstream>

int main()
{
	ifstream fin, fin1;
	fin.open("data1.txt");

	if (fin.fail())
	{
		cout << "data1 file open Error" << "\n";
		exit(1);
	}

	char name, grade;
	string major;
	int ID;

	List list1;

	for (int i = 0; i < 7; i++)
	{
		fin >> name >> ID >> major >> grade;
		list1.insert(&list1, name, ID, major, grade);
	}
	list1.displayList(&list1);
	cout << "-----------------------------" << "\n";
	list1.searchNode(&list1, 'A');

	List list2;
	fin1.open("data2.txt");

	if (fin.fail())
	{
		cout << "data2 file open Error" << "\n";
		exit(1);
	}

	for (int i = 0; i < 3; i++)
	{
		fin1 >> name >> ID >> major >> grade;
		list2.insert(&list2, name, ID, major, grade);
	}
	cout << "-----------------------------" << "\n";

	List list3;
	list3 = *list3.concat(&list1, &list2);
	list3.sortList(&list3);
	list3.search_major(&list3);
	return 0;
}