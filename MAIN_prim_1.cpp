#include "prim_1.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
	ifstream inStream;
	inStream.open("Data.txt");
	if (inStream.fail())
	{
		cout << "File open failed." << endl;
		exit(1);
	}


	int vertNum, edgeNum;
	char vchar1;
	char vchar2;
	int cost;

	inStream >> vertNum >> edgeNum;
	int **lowCost;
	lowCost = new int*[vertNum];

	for (int i = 0; i < vertNum; i++)
		lowCost[i] = new int[vertNum];


	GraphList graph(vertNum, edgeNum); // 그래프 초기화

	for (int i = 0; i < edgeNum; i++)
	{
		inStream >> vchar1 >> vchar2 >> cost;
		//cout << vert[0] << ' ' << vert[1] << vert[2];
		graph.addNode(vchar1 - 'A', vchar2 - 'A', cost);
	}

	graph.outputGraph_Array(lowCost);
	graph.primMethod1(0, lowCost);
	graph.primMethod2(0, lowCost);


	inStream.close();

	return 0;

}