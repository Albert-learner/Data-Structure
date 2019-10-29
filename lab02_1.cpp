#include <iostream>
#include <fstream>
using namespace std;

typedef struct
{
	int row;
	int col;
	int value;
}SMarray;

void transpose(SMarray a[], SMarray b[])
{
	int i, j, currentb;
	b[0].row = a[0].col;
	b[0].col = a[0].row;
	b[0].value = a[0].value;

	if (a[0].value > 0)
	{
		currentb = 1;
		for (i = 0; i < a[0].col; i++)
		{
			for (j = 1; j <= a[0].value; j++)
			{
				if (a[j].col == i)
				{
					b[currentb].row = a[j].col;
					b[currentb].col = a[j].row;
					b[currentb].value = a[j].value;
					currentb++;
				}
			}
		}
	}
}

int main()
{
	ifstream fin;
	fin.open("lab02-1t.txt");

	if (fin.fail())
	{
		cout << "File open failed" << "\n";
		exit(1);
	}

	SMarray A[9];
	SMarray TRANS_A[9];

	for (int i = 0; i < 9; i++)
	{
		fin >> A[i].row >> A[i].col >> A[i].value;
		cout << A[i].row << ' ' << A[i].col << ' ' << A[i].value << "\n";
	}

	transpose(A, TRANS_A);
	cout << "\n";

	for (int i = 0; i < 9; i++)
	{
		cout << TRANS_A[i].row << ' ' << TRANS_A[i].col << ' ' << TRANS_A[i].value << '\n';
	}
	return 0;
}