#include "Prim.h"
#include <fstream>

int main()
{
	ifstream fin;
	fin.open("Prim.txt");

	if (fin.fail())
	{
		cout << "File open failed." << endl;
		exit(1);
	}
	else
	{
		int vertNum, edgeNum;
		char vChar1, vChar2;
		int cost;

		fin >> vertNum >> edgeNum;
		int **lowCost;
		lowCost = new int*[vertNum];

		for (int i = 0; i < vertNum; i++)
		{
			lowCost[i] = new int[vertNum];
		}

		GraphList graph(vertNum, edgeNum);

		for (int i = 0; i < edgeNum; i++)
		{
			fin >> vChar1 >> vChar2 >> cost;
			graph.addNode(vChar1 - 'A', vChar2 - 'A', cost);
		}

		graph.outputGraph_Arr(lowCost);
		cout << endl;
		graph.primeMethod1(0, lowCost);
		cout << endl;
		graph.primeMethod2(0, lowCost);

		fin.close();
	}
	return 0;
}