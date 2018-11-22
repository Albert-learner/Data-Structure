#include <iostream>
#include <string>
#include <fstream>
using namespace std;

typedef struct {
	string name;
	double base;
	double height;
	double area;
}Shape;

void printData(Shape *sha)
{
	for (int i = 0; i < 7; i++)
	{
		if (sha[i].name.compare("circle") == 0)
		{
			cout << sha[i].name << ' ' << sha[i].base << ' ' << sha[i].area << endl;
		}
		else
		{
			cout << sha[i].name << ' ' << sha[i].base << ' ' << sha[i].height << ' ' << sha[i].area << endl;
		}
	}

}

void sortData(Shape *sha, int max)
{
	int i, j, min;
	Shape temp;

	for (i = 0; i < max - 1; i++)
	{
		min = i;
		for (j = i + 1; j < max; j++)
		{
			if (sha[min].name.compare(sha[j].name) < 0) // 사전순 뒤일때
				min = j;
		}
		temp = sha[i];
		sha[i] = sha[min];
		sha[min] = temp;
	}
	return;
}

int main()
{
	ifstream inStream;
	Shape sha[10];

	inStream.open("c:\\data\\flower.txt");
	if (inStream.fail())
	{
		cout << "Opening Failed" << endl;
		return -1;
	}

	for (int i = 0; i < 7; i++)
	{
		inStream >> sha[i].name;
		if (sha[i].name.compare("circle") == 0)
		{
			inStream >> sha[i].base;
			sha[i].height = 0;
			sha[i].area = sha[i].base*sha[i].base*3.14;
		}
		else if (sha[i].name.compare("rectangle") == 0)
		{
			inStream >> sha[i].base >> sha[i].height;
			sha[i].area = sha[i].base*sha[i].height;
		}
		else
		{
			inStream >> sha[i].base >> sha[i].height;
			sha[i].area = sha[i].base*sha[i].height / 2;
		}
	}

	cout << "======================================" << endl << "Before Sorting" << endl << "======================================" << endl;
	printData(sha);
	sortData(sha, 7);
	cout << "======================================" << endl << "After Sorting" << endl << "======================================" << endl;
	printData(sha);

	inStream.close();
	return 0;
}
