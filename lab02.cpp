#include <iostream>
#include <fstream>
using namespace std;

#define MAX 5

void magic()
{
	int square[MAX][MAX], k, l;

	for (k = 0; k < MAX; k++)
	{
		for (l = 0; l < MAX; l++)
		{
			square[k][l] = 0;
		}
	}

	int key = 2, i = 0, j = MAX / 2, row, col;
	square[i][j] = 1;

	while (key <= MAX * MAX)
	{
		if (i - 1 < 0)
			row = MAX - 1;
		else
			row = i - 1;

		if (j - 1 < 0)
			col = MAX - 1;
		else
			col = j - 1;

		if (square[row][col])
			i = (i + 1) % MAX;
		else
		{
			i = row;
			j = col;
		}
		square[i][j] = key++;
	}

	for (k = 0; k < MAX; k++)
	{
		for (l = 0; l < MAX; l++)
		{
			cout << square[k][l] << ' ';
		}
		cout << "\n";
	}
}

int main()
{
	int cost;
	cout << "크기 입력 : ";
	cin >> cost;

	if (cost == MAX)
	{
		magic();
	}
	return 0;
}