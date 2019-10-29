#include "Kruskal.h"
#include <fstream>

int main()
{
	ifstream fin;
	fin.open("KruData1.txt");

	if (fin.fail())
	{
		cout << "File open Error" << "\n";
		exit(1);
	}
	Kruskal k;

	int vNum, cNum;
	fin >> vNum >> cNum;

	for (int t = 0; t < cNum; t++)
	{
		char start, end;
		int cost;
		fin >> start >> cost >> end;

		k.addData(start, cost, end);
	}

	cout << "Original Data : " << endl;
	k.OutPutKruData();
	cout << endl;
	cout << "Sorted Data : " << endl;
	k.sortData();
	k.OutPutKruData();
	cout << endl;

	cout << "Krukal's MST : " << endl;
	k.SolveKruskal();
	return 0;
}