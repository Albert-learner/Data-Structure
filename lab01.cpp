#include <iostream>
using namespace std;

char compare(int x, int y)
{
	if (x > y)
		return 1;
	else if (x < y)
		return -1;
	else
		return 0;
}

int recur_BinarySearch(int list[], int searchnum, int left, int right)
{
	int middle;

	if (left <= right)
	{
		middle = (left + right) / 2;
		switch (compare(list[middle], searchnum))
		{
		case -1:
			return recur_BinarySearch(list, searchnum, middle + 1, right);
		case 0:
			return middle;
		case 1:
			return recur_BinarySearch(list, searchnum, left, middle - 1);
		default:
			break;
		}
	}
	return -1;
}

int main()
{
	int list[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
	int cost, way, found, iter_found;

	while (1)
	{
		cout << "Enter an integer to search : ";
		cin >> cost;
		cout << "Enter method of search : (1. BinarySearch  2. Recursive BinarySearch) : ";
		cin >> way;
		
		if (way == 1)
		{
			for (int i = 0; i < 10; i++)
			{
				if (list[i] != cost)
				{
					if (i == 9)
					{
						cout << cost << " is NOT FOUND" << "\n";
						break;
					}
					else
					{
						continue;
					}
				}
				else
				{
					cout << cost << " is at position " << i << "\n";
					break;
				}
			}
		}
		else if (way == 2)
		{
			found = recur_BinarySearch(list, cost, 0, 9);
			if (found == -1)
			{
				cout << cost << " is NOT FOUND" << "\n";
				break;
			}
			else
			{
				cout << cost << " is at position " << found << "\n";
			}
		}
	}
	return 0;
}