#include <iostream>
#include <fstream>
#include <string>
#include "HW2.h"
using namespace std;


int main()
{
	ifstream fin;
	fin.open("data1.txt");

	
	//�Է� ���� ������ �ӽ÷� ���� ���� ����
	char name, grade;
	string major;
	int ID;
	
	//�̸� ���ĺ� ������������ ����Ʈ�� ���� ����ϱ�
	List li;
	createList(&li);

	for (int i = 0; i < 7; i++)
	{
		fin >> name >> ID >> major >> grade;
		addFirst(&li, name, ID, major, grade);
	}
	displayList(&li);
	cout << "------------------------" << '\n';
	searchNode(&li, 'A');
	

	List li_;
	createList(&li_);
	ifstream in;
	in.open("data2.txt");
	for (int i = 0; i < 3; i++)
	{
		in >> name >> ID >> major >> grade;
		addFirst(&li_, name, ID, major, grade);
	}
	cout << "-------------------------------\n";
	Node *nS;
	 
	Node* temp = li_.head;
	
	searchNode_3(li);

	fin.close();
	in.close();
	return 0;
}

/*for (int i = 0; i < 3; i++)
	{
		nS = li.head;
		int flag = 0;
		while (nS->next != NULL)
		{
			if (nS->next->Name > temp->Name)
			{
				Node* g = nS->next;
				nS->next = temp;
				temp = temp->next;
				nS = nS->next;
				nS->next = g;
				flag = 1;
				break;
			}
			nS = nS->next;
		}
		if (flag == 0)
		{
			nS->next = temp;
			temp = temp->next;
			nS->next->next = NULL;
		}
	}*/