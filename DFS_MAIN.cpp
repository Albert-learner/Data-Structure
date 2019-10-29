#include "DFS.h"
#include <fstream>

int main()
{
	Graph g;
	int count;
	ifstream fin;
	fin.open("dfs.dat");
	if (fin.fail())
	{
		cout << "Fail to open file." << endl;
		exit(1);
	}
	else
	{
		for (int i = 0; i < MAX; i++)
		{
			visited[i] = false;
			visited1[i] = false;
		}

		fin >> count;
		for (int i = 0; i < count; i++)
		{
			int numCases;
			fin >> numCases;
			g.graph[i] = new Node();
			for (int j = 0; j < numCases; j++)
			{
				int num;
				fin >> num;
				g.insert(i, j, num);
			}
		}

		//인접 리스트로 할 경우
		cout << "***** Depth First Search(DFS) using Adjacent List" << endl;
		g.dfs(0);
		cout << endl;
		//인접 행렬로 할 경우
		cout << "***** Depth first Search(DFS) using adjacent matrix" << endl;
		g.dfs_arr(0);
		cout << endl;
		g.printNode();
	}
	return 0;
}