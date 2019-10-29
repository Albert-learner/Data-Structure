#include "BFS.h"
#include <fstream>

int main()
{
	ifstream fin;
	//bfs.dat -> 인접 행렬
	fin.open("bfs.dat");
	if (fin.fail())
	{
		cerr << "Fail to open .dat" << endl;
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
		cout << "***** Breath First Search(BFS) using Adjacent Matrix" << endl;
		g.bfs(0);
		cout << endl << endl;
		fin.close();
	}

	ifstream ins;
	//인접 리스트
	ins.open("bfs.txt");
	if (ins.fail())
	{
		cerr << "Fail to open .txt" << endl;
		exit(1);
	}
	else
	{
		Graph gra;
		gra.initGraph();
		gra.initializeQ();

		int count;
		ins >> count;
		for (int i = 0; i < count; i++)
		{
			int numCases;
			ins >> numCases;
			gra.graph[i] = new Node(0);
			for (int j = 0; j < numCases; j++)
			{
				int cost;
				ins >> cost;
				gra.insertList(i, j, cost);
			}
		}
		cout << "***** Breath First Search(BFS) using Adjacent List"<< endl;
		gra.bfs_list(0);
		cout << endl;
	}
	return 0;
}