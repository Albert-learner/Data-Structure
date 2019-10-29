#pragma once
#include <iostream>
using namespace std;
const int MAX_SIZE = 7;
const int MAX_SIZE1 = 8;

class ShortestPath
{
public:
	int cost[MAX_SIZE][MAX_SIZE] = 
	{
		{100, 2, 4, 5, 100, 100, 100},
		{100, 100, 100, 2, 7, 100, 100},
		{100, 100, 100, 1, 100, 4, 100},
		{100, 2, 1, 100, 4, 3, 100},
		{100, 7, 100, 4, 100, 1, 5},
		{100, 100, 4, 3, 1, 100, 7},
		{100, 100, 100, 100, 7, 5, 100}
	};
	int cost1[MAX_SIZE1][MAX_SIZE1] = 
	{
		{0, 10000, 10000, 10000, 10000, 10000, 10000, 10000},
		{300, 0, 10000, 10000, 10000, 10000, 10000, 10000},
		{1000, 800, 0, 10000, 10000, 10000, 10000, 10000},
		{10000, 10000, 1200, 0, 10000, 10000, 10000, 10000},
		{10000, 10000, 10000, 1500, 0, 250, 10000, 10000},
		{10000, 10000, 10000, 1000, 10000, 0, 900, 1400},
		{10000, 10000, 10000, 10000, 10000, 10000, 0, 1000},
		{1700, 10000, 10000, 10000, 10000, 10000, 10000, 0}
	};

	int found[MAX_SIZE], distance[MAX_SIZE];
	int found1[MAX_SIZE1], distance1[MAX_SIZE1];

	ShortestPath()
	{

	}
	void print();
	void print1();
	void Shortest_Path(int vertex);
	void Shortest_Path1(int vertex);
	int choose(int *distance);
	int choose1(int *disatnce);
};