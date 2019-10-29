#include <iostream>
using namespace std;


int iter_binarySearch(int list[], int searchnum, int left, int right)
{
	int middle;

	if (left <= right)
	{
		middle = (left + right) / 2;
		if (searchnum < list[middle])
		{
			right = middle - 1;
		}
		else if (searchnum == list[middle])
		{
			return middle;
		}
		else
		{
			left = middle + 1;
		}
	}
	return -1;
}

char compare(int x, int y)
{
	if (x > y)
		return 1;
	else if (x < y)
		return -1;
	else
		return 0;
}

int recur_binarySearch(int list[], int searchnum, int left, int right)
{
	int middle;

	if (left <= right)
	{
		middle = (left + right) / 2;
		switch (compare(list[middle], searchnum))
		{
		case -1:
			return recur_binarySearch(list, searchnum, middle + 1, right);
			break;
		case 0:
			return middle;
			break;
		case 1:
			return recur_binarySearch(list, searchnum, left, middle - 1);
			break;
		default:
			break;
		}
	}
	return -1;
}

int main()
{
	int data[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
	int num, iter_found, recur_found;

	cout << "Enter an integer to search : ";
	cin >> num;

	/*iter_found = iter_binarySearch(data, num, 0, 9);

	if (iter_found == -1)
	{
		cout << "Not in the list" << "\n";
	}
	else
	{
		cout << "Found at position " << iter_found << "\n";
	}*/

	recur_found = recur_binarySearch(data, num, 0, 9);
	if (recur_found == -1)
	{
		cout << "Not in the list" << "\n";
	}
	else
	{
		cout << "Found at position " << recur_found << "\n";
	}
	return 0;
}