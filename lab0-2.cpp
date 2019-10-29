/*
lab02 20153212 ¿Ã¿Á∫Û
*/
#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int>data, int n)
{
	int min = data[0];
	int minPos = 0;

	for (int i = 1; i < n; i++)
	{
		if (data[i] < min)
		{
			min = data[i];
			minPos = i;
		}
		else
		{
			continue;
		}
	}
	return minPos;
}

int findMax(vector<int>data, int n)
{
	int max = data[0];
	int maxPos = 0;

	for (int i = 1; i < n; i++)
	{
		if (data[i] > max)
		{
			max = data[i];
			maxPos = i;
		}
		else
		{
			continue;
		}
	}
	return maxPos;
}

int main()
{
	vector<int>data = { 90, 40, 60, 10, 50, 80, 20, 70 };

	int minPosition = findMin(data, data.size());
	int maxPosition = findMax(data, data.size());

	cout << "Minimum number is " << data[minPosition] << " at Position " << minPosition+1 << "\n";
	cout << "Maximum number is " << data[maxPosition] << " at Position " << maxPosition+1 << "\n";
	return 0;
}