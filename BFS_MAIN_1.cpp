#include "BFS_1.h"
#include <fstream>

int main()
{
	ifstream fin;
	fin.open("bfs.txt");
	if (fin.fail())
	{
		cerr << "Fail to open file" << endl;
		exit(1);
	}
	else
	{
		Graph g;
		g.initGraph();
		g.initializeQ();

		for (int i = 0; i < MAX; i++)
		{
			int count = 0;
			for (int j = 0; j < MAX; j++)
			{
				int cost;
				fin >> cost;
				g.insertGraph(i, j, cost, count);
				count++;
			}
		}
		g.print_matrix();
		cout << endl;
		cout << "***** Breath First Search(BFS) using list" << endl;
		g.bfs(0);
		cout << endl << endl;
		fin.close();
	}
	return 0;
}