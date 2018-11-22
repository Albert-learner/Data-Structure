#ifndef _SHORTESTPATH_H__
#define _SHORTESTPATH_H__
#include <iostream>
using namespace std;
const int MAX_SIZE = 7;

class ShortestPath
{
public:
	int cost[MAX_SIZE][MAX_SIZE] =
	{
		{ 100, 2, 4, 5, 100, 100, 100 },
		{ 100, 100, 100, 2, 7, 100, 100 },
		{ 100, 100, 100, 1, 100, 4, 100 },
		{ 100, 2, 1, 100, 4, 3, 100 },
		{ 100, 7, 100, 4, 100, 1, 5 },
		{ 100, 100, 4, 3, 1, 100, 7},
		{ 100, 100, 100, 100, 7, 5, 100 }
	};

	int found[MAX_SIZE], distance[MAX_SIZE];

	ShortestPath();
	void print();
	void Shortest_Path(int vertex);
	int choose(int *distance);
};

#endif // !_SHORTESTPATH_H__
