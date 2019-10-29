#include "SinglyLinkedList.h"
#include <fstream>
#include <string>

int main()
{
	ifstream fin;
	fin.open("data1.txt");

	//입력 받을 데이터 임시로 갖는 변수 생성
	char name, grade;
	string major;
	int ID;

	List list;
	createList(&list);
	for (int i = 0; i < 8; i++)
	{
		fin >> name >> ID >> major >> grade;
		addFirst(&list, name, ID, major, grade);
	}
	displayList(&list);
	cout << "----------------------------" << "\n";
	searchNode(&list, 'A');

	List list1;
	createList(&list1);
	ifstream fin1;
	fin1.open("data2.txt");
	for (int i = 0; i < 3; i++)
	{
		fin1 >> name >> ID >> major >> grade;
		addFirst(&list1, name, ID, major, grade);
	}
	cout << "----------------------------" << "\n";
	Node *Snode;
	Snode = list.head;

	while (Snode->next != NULL)
	{
		Snode = Snode->next;
	}
	Snode->next = list1.head;
	searchNode_pos(list);

	fin.close();
	fin1.close();
	return 0;
}