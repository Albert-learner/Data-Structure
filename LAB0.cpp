#include <iostream>
#include <vector>
#include <fstream>
#include <string>
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
	}
	return maxPos;
}

int main()
{
	vector<int>v;
	ifstream in("Lab0-1.dat");

	while (!in.eof())
	{
		int val;
		in >> val;
		v.push_back(val);
	}

	int maxPos = findMax(v, v.size());
	int minPos = findMin(v, v.size());

	cout << "Minimum number is " << v[minPos] << " at position " << minPos+1 << ", " << endl;
	cout << "Maximum number is " << v[maxPos] << " at position " << maxPos+1 << endl;
	return 0;
}