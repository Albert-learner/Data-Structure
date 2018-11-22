#include "ShortestPath.h"

ShortestPath::ShortestPath()
{

}

void ShortestPath::print()
{
	int i, j;
	for (i = 0; i < MAX_SIZE; i++)
	{
		for (j = 0; j < MAX_SIZE; j++)
			cout << cost[i][j]<<' ';
		cout << endl;
	}
	cout << "------------------------------------" << endl;
}

void ShortestPath::Shortest_Path(int vertex)
{
	int i, u, w;
	for (i = 0; i < MAX_SIZE; i++)
	{
		found[i] = false;
		distance[i] = cost[vertex][i];
	}

	found[vertex] = true;
	distance[vertex] = 0;
	int ans=0;

	for (i = 0; i < MAX_SIZE - 1; i++)
	{
		u = choose(distance);
		found[u] = true;

		for (w = 0; w < MAX_SIZE; w++)
		{
			if (!found[w])
			{
				if (distance[u] + cost[u][w] < distance[w])
					distance[w] = distance[u] + cost[u][w];
			}
		}
		cout << "Distance-> ";
		for (int k = 0; k < MAX_SIZE; k++)
		{
			cout << distance[k] << ' ';
		}


		cout << "   (Selected Node: ";
		for (int l = 1; l < MAX_SIZE; l++)
		{
			if (found[l] != 0)
				cout << l;
		}
		cout <<")"<< endl;
	}
}

int ShortestPath::choose(int *distance)
{
	int i, min, minnode=0;
	min = 99999;

	for (i = 0; i < MAX_SIZE; i++)
	{
		if (distance[i] < min && !found[i])
		{
			min = distance[i];
			minnode = i;
		}
	}
	return minnode;
}
