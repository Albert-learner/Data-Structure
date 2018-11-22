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

int main()
{
	ifstream fin;
	Shape sha[10];

	fin.open("lab2-2.txt");
	if (fin.fail())
	{
		cout << "Opening Failed" << endl;
		return -1;
	}

	for (int i = 0; i < 7; i++)
	{
		fin >> sha[i].name;
		if (sha[i].name.compare("circle") == 0)
		{
			fin >> sha[i].base;
			sha[i].height = 0;
			sha[i].area = sha[i].base*sha[i].base*3.14;
		}
		else if (sha[i].name.compare("rectangle") == 0)
		{
			fin >> sha[i].base >> sha[i].height;
			sha[i].area = sha[i].base*sha[i].height;
		}
		else
		{
			fin >> sha[i].base >> sha[i].height;
			sha[i].area = sha[i].base*sha[i].height / 2;
		}
	}

	printData(sha);

	fin.close();
	return 0;
}
