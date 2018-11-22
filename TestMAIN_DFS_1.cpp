#include "DFS_1.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
	ifstream inStream;
	inStream.open("graphData_1.txt");
	if (inStream.fail())
	{
		cout << "File open failed." << endl;
		exit(1);
	}


	int vertNum, edgeNum;
	char vert[3];
	inStream >> vertNum >> edgeNum;

	GraphList graph(vertNum, edgeNum);

	for (int i = 0; i < edgeNum; i++)
	{
		inStream >> vert;
		cout << vert[0] << ' ' << vert[1] << vert[2];
		graph.addNode(vert[0] - '0', vert[1] - '0');
	}
	cout << endl;
	graph.sortGraph_List(vertNum);
	graph.outputGraph_List();

	cout << endl;

	graph.DFS(0);
	cout << endl;
	return 0;

}