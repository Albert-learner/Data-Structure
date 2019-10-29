#include <iostream>
using namespace std;

void recur_Hanoi(char start, char end, char middle, int size)
{
	if (size == 1)
	{
		cout << "move disk1 from peg "<<start<<" to peg "<<end<<"\n";
		return ;
	}
	else
	{
		recur_Hanoi(start, middle, end, size - 1);
		cout << "Move disk "<<size<<" from peg "<<start<<" to peg "<<end<<"\n";
		recur_Hanoi(middle, end, start, size - 1);
	}
}

bool isEven(int disks)
{
	bool confirm;
	if (disks % 2 == 0)
	{
		confirm = true;
	}
	else
	{
		confirm = false;
	}
	return confirm;
}

int moves(int disks)
{
	int moves = 0;
	for (int i = 1; i <= disks; i++)
	{
		moves = (moves * 2) + 1;
	}
	return moves;
}

int whichDisk(int movement, int disks)
{
	int which;
	int start = 1;
	int incre = 2;

	int movements = moves(disks);
	for (int i = 1; i <= disks; i++)
	{
		for (int j = start; j <= movements; j += incre)
		{
			if (movement == j)
			{
				which = i;
			}
		}
		start *= 2;
		incre *= 2;
	}
	return which;
}

int patronNum(int move, int which, int disks)
{
	int patron = 0;
	int incre = 2;
	int start = 1;

	for (int i = 1; i <= disks; i++)
	{
		if (i == which)
		{
			for (int j = start; j <= move; j += incre)
			{
				patron++;
				if (patron == 3 && j != move)
				{
					patron = 0;
				}
			}
		}
		start *= 2;
		incre *= 2;
	}
	return patron;
}

void MoveSingle(char start, char end)
{
	cout << start << "-->" << end << "\n";
}

void iter_Hanoi(char start, char end, char middle, int size, int numOfMoves)
{
	if (!isEven(size))
	{
		for (int move = 1; move <= numOfMoves; move++)
		{
			switch (patronNum(move, whichDisk(move, size), size))
			{
			case 1:
				if (!isEven(whichDisk(move, size)))
				{
					MoveSingle(start, end);
				}
				else
				{
					MoveSingle(start, middle);
				}
				break;
			case 2:
				if (!isEven(whichDisk(move, size)))
				{
					MoveSingle(end, middle);
				}
				else
				{
					MoveSingle(middle, end);
				}
				break;
			case 3:
				if (!isEven(whichDisk(move, size)))
				{
					MoveSingle(middle, start);
				}
				else
				{
					MoveSingle(end, start);
				}
				break;
			default:
				break;
			}
		}
	}
	else
	{
		for (int move = 1; move <= numOfMoves; move++)
		{
			switch (patronNum(move, whichDisk(move, size), size))
			{
			case 1:
				if (!isEven(whichDisk(move, size)))
				{
					MoveSingle(start, middle);
				}
				else
				{
					MoveSingle(start, end);
				}
				break;
			case 2:
				if (!isEven(whichDisk(move, size)))
				{
					MoveSingle(middle, end);
				}
				else
				{
					MoveSingle(end, middle);
				}
				break;
			case 3:
				if (!isEven(whichDisk(move, size)))
				{
					MoveSingle(end, start);
				}
				else
				{
					MoveSingle(middle, start);
				}
				break;
			default:
				break;
			}
		}
	}
}

int main()
{
	int num, numOfMovesToSolve;

	cout << "Enter the number of disks : ";
	cin >> num;
	cout << "The sequence of moves involved in the Tower of Hanoi are : "<<"\n";
	recur_Hanoi('A', 'C', 'B', num);
	cout << "\n";

	numOfMovesToSolve = moves(num);
	iter_Hanoi('A', 'C', 'B', num, numOfMovesToSolve);
	return 0;
}