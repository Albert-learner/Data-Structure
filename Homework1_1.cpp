#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;

//�����̸��� �� ������ �´� �������� ������ ����ü ����
typedef struct
{
	string name;
	double base;
	double height;
	double radius;
	double side1;
	double side2;
	double area;
}Shape;

//Shape����ü�� ���� �̸��� ���� �� ������ �´� �������� ������ִ� printData�Լ�
void printData(Shape *sha)
{
	for (int i = 0; i < 7; i++)
	{
		if (sha[i].name.compare("circle") == 0)
		{
			cout << sha[i].name << ' ' << sha[i].radius << '\t' << sha[i].area << "\n";
		}
		else
		{
			if (sha[i].name.compare("triangle") == 0)
			{
				cout << sha[i].name << ' ' << sha[i].base << ' ' << sha[i].height << '\t' << sha[i].area << "\n";
			}
			else
			{
				cout << sha[i].name << ' ' << sha[i].side1 << ' ' << sha[i].side2 << '\t' << sha[i].area << "\n";
			}
		}
	}
}

int main()
{
	ifstream in;
	Shape sha[10];
	in.open("lab2.txt");

	if (in.fail())
	{
		cout << "Opening Failed" << "\n";
		return -1;
	}

	//���� ��������� �����̸�, ������ ���õ� �������� �Է¹ް�, �� ������ �´� ���̸� ����մϴ�.
	for (int i = 0; i < 7; i++)
	{
		in >> sha[i].name;
		if (sha[i].name.compare("circle") == 0)
		{
			in >> sha[i].radius;
			sha[i].area = pow(sha[i].radius, 2) * 3.14;
		}
		else if (sha[i].name.compare("rectangle") == 0)
		{
			in >> sha[i].side1 >> sha[i].side2;
			sha[i].area = sha[i].side1 * sha[i].side2;
		}
		else
		{
			in >> sha[i].base >> sha[i].height;
			sha[i].area = (sha[i].base * sha[i].height) / 2;
		}
	}

	//�Ҽ� ��° �ڸ����� ����ϱ� ���� �����Ͽ����ϴ�.
	cout << fixed;
	cout.precision(2);
	
	//����ü�� ����մϴ�.
	printData(sha);
	
	cout << "\n";
	
	return 0;
}

//line 52�� ����
//void sortData(Shape *sha, int max)
//{
//	int i, j, min;
//	Shape temp;
//
//	for (i = 0; i < max - 1; i++)
//	{
//		min = i;
//		for (j = i + 1; j < max; j++)
//		{
//			if (sha[min].name.compare(sha[j].name) < 0)
//				min = j;
//		}
//		temp = sha[i];
//		sha[i] = sha[min];
//		sha[min] = temp;
//	}
//	return ;
//}


/*
line 86�� ���� 
cout << "============== Before Sorting===============" << "\n";

line 88�� ����
sortData(sha, 7);

line90�� ����
cout << "============== After Sorting===============" << "\n";
	printData(sha);
*/