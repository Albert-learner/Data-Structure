#include "ShortestPath.h"

void ShortestPath::print()
{
	int i, j;
	cout << "----- Cost Matrix -----" << endl;
	for (i = 0; i < MAX_SIZE; i++)
	{
		for (j = 0; j < MAX_SIZE; j++)
		{
			cout << cost[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "---------------------------------" << endl;
}

void ShortestPath::print1()
{
	cout << "----- Cost Matrix1 -----" << endl;
	for (int i = 0; i < MAX_SIZE1; i++)
	{
		for (int j = 0; j < MAX_SIZE1; j++)
		{
			cout << cost1[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "---------------------------------" << endl;
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
	int ans = 0;

	for (i = 0; i < MAX_SIZE - 1; i++)
	{
		u = choose(distance);
		found[u] = true;

		cout << "Dist: ";
		for (int k = 0; k < MAX_SIZE; k++)
		{
			cout << distance[k] << ' ';
		}
		cout<<"   ";
		for (w = 0; w < MAX_SIZE; w++)
		{
			if (!found[w])
			{
				if (distance[u] + cost[u][w] < distance[w])
				{
					distance[w] = distance[u] + cost[u][w];
				}
			}
		}
		cout << "    (Selected Node: " << u << ")" << endl;
	}
}

void ShortestPath::Shortest_Path1(int vert)
{
	int i, u, w;
	for (i = 0; i < MAX_SIZE1; i++)
	{
		found1[i] = false;
		distance1[i] = cost1[vert][i];
	}

	found1[vert] = true;
	distance1[vert] = 0;
	int ans = 0;
	
	cout << "Beginning Dist : ";
	for (int k = 0; k < MAX_SIZE1; k++)
	{
		cout << distance1[k] << ' ';
	}
	cout << endl;

	for (i = 0; i < MAX_SIZE1 - 1; i++)
	{
		u = choose1(distance1);
		found1[u] = true;

		for (w = 0; w < MAX_SIZE1; w++)
		{
			if (!found1[w])
			{
				if (distance1[u] + cost1[u][w] < distance1[w])
				{
					distance1[w] = distance1[u] + cost1[u][w];
				}
			}
		}
		cout << "Select : (" << u << ")   dist : ";
		for (int k = 0; k < MAX_SIZE1; k++)
		{
			cout << distance1[k] << ' ';
		}
		cout << endl;
	}
}

int ShortestPath::choose(int *distance)
{
	int i, min, minnode = 0;
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

int ShortestPath::choose1(int *distance1)
{
	int i, min, minnode = 0;
	min = 10000;

	for (i = 0; i < MAX_SIZE1; i++)
	{
		if (distance1[i] < min && !found1[i])
		{
			min = distance1[i];
			minnode = i;
		}
	}
	return minnode;
}
