#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct triangle
{
	double base;
	double height;
	double wid1;
};

struct rectangle
{
	double side1;
	double side2;
	double wid2;
};

struct circle
{
	double radius;
	double wid3;
};

int main(void)
{
	ifstream fin;
	string line;
	int b[10],bidx = 0;
	struct triangle tr[10];
	struct rectangle re[10];
	struct circle ci[10];

	fin.open("lab3.txt");
	
	if (line == "triangle")
	{
		fin >> tr[bidx].base >> tr[bidx].height;
		tr[bidx].wid1 = (tr[bidx].base*tr[bidx].height) / 2;
		cout << line << ' ' << tr[bidx].base << ' ' << tr[bidx].height <<tr[bidx].wid1<< '\n';
	}
	else if (line == "rectangle")
	{
		fin >> re[bidx].side1 >> re[bidx].side2;
		re[bidx].wid2 = re[bidx].side1*re[bidx].side2;
		cout << line << ' ' << re[bidx].side1 << ' ' << re[bidx].side2 << ' ' << re[bidx].wid2 << '\n';
	}
	else if (line == "circle")
	{
		fin >> ci[bidx].radius;
		ci[bidx].wid3 = ci[bidx].radius*ci[bidx].radius*3.14;
		cout << line << ' ' << ci[bidx].radius << ' ' << ci[bidx].wid3 << '\n';
	}
	cout << bidx<<endl;
	return 0;
}