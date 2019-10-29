#include <iostream>
#include <fstream>
using namespace std;

#define MAX_COL 9

typedef struct
{
	int row;
	int col;
	int value;
}term;

void fast_transpose(term a[], term b[])
{
	int row_terms[MAX_COL], starting_pos[MAX_COL];
	int i, j, num_col = a[0].col, num_terms = a[0].value;

	b[0].row = num_col;
	b[0].col = a[0].row;
	b[0].value = num_terms;

	if (num_terms > 0)
	{
		for (i = 0; i < num_col; i++)
		{
			row_terms[i] = 0;
		}
		for (i = 1; i <= num_terms; i++)
		{
			row_terms[a[i].col]++;
		}

		starting_pos[0] = 1;
		for (i = 1; i < num_col; i++)
		{
			starting_pos[i] = starting_pos[i - 1] + row_terms[i - 1];
		}

		for (i = 1; i <= num_terms; i++)
		{
			j = starting_pos[a[i].col]++;
			b[j].row = a[i].col; 
			b[j].col = a[i].row;
			b[j].value = a[i].value;
		}
	}
}

int main()
{
	ifstream fin;
	fin.open("hw1.txt");
	term A[9];
	term TRANS_A[9];

	if (fin.fail())
	{
		cout << "File open failed" << "\n";
		exit(1);
	}

	for (int i = 0; i < 9; i++)
	{
		fin >> A[i].row >> A[i].col >> A[i].value;
		cout << A[i].row << ' ' << A[i].col << ' ' << A[i].value << "\n";
	}

	fast_transpose(A, TRANS_A);
	cout << "\n";

	for (int i = 0; i < 9; i++)
	{
		cout << TRANS_A[i].row << ' ' << TRANS_A[i].col << ' ' << TRANS_A[i].value << "\n";
	}
	return 0;
}