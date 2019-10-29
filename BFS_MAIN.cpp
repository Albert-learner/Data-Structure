#include "BFS.h"
#include <fstream>

int main()
{
	ifstream fin;
	int count;
	fin.open("bfs.dat");

	if (fin.fail())
	{
		cout << "File open error" << endl;
		exit(1);
	}
	else
	{
		Graph g;
		g.print_matrix();
		g.BFS(0);

		fin >> count;
		for (int i = 0; i < count; i++)
		{
			int cases;
			fin >> cases;
			g.graph[i] = new Node();
			for (int j = 0; j < cases; j++)
			{
				int num;
				fin >> num;
				g.insert(i, j, num);
			}
		}
		//g.BFS_list(0);
	}

	
	return 0;
}