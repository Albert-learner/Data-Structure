#include "KrusKal.h"
#include <fstream>

int main()
{
	ifstream fin;
	fin.open("data.txt");
	KrusKal k;

	int vNum, CNum;
	fin >> vNum >> CNum;
	for(int t=0;t<CNum;t++)
	{
		char start, end;
		int cost;
		fin >> start >> cost >> end;
		
		k.addData(start, cost, end);
	}

	cout << "Original Data : " << endl;
	k.OutPutKRUData();
	cout << endl;
	cout << "Sorted Data : " << endl;
	k.sortData();
	k.OutPutKRUData();

	cout << "KrusKal done" << endl;
	k.SolveKrusKal();
	return 0;
}