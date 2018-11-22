#include<iostream>
#include<vector> 
using namespace std;

#define f_pos 0

#define edges 6



struct line 
{
	int from;
	int to;
};

void find(bool visited[edges], line liner[edges], int arr[6][6], int& now_position, int& count, int& f_pos_count, line first_liner[edges], int& i);


int main()
{
	int max = 6;
	int arr[6][6] = 
	{
		{ 0,5,100,12,100,100 },
		{ 5,0,6,10,24,100 },
		{ 100,6,0,17,100,30 },
		{ 12,10,17,0,20,100 },
		{ 100,24,100,20,0,13 },
		{ 100,100,30,100,13,0 },
	
	};
	
	for (int i = 0; i < max; ++i)
	{
		for (int j = 0; j < max; ++j)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;
	
	bool visited[100] = { false ,};

	line liner[edges - 1];
	line first_liner[edges - 1];

	for (int i = 0; i < edges; i++)
		visited[i] = false;
	
	visited[f_pos] = true;
	
	int now_position = f_pos;
	
	int count = 0;
	
	int f_pos_count = 0;

	for (int i = 0; i < edges; i++)
	{
		find(visited, liner, arr, now_position, count, f_pos_count, first_liner, i);
	}

	for (int i = 0; i < count; ++i)
	{
		cout << "(" << liner[i].from + 1 << "," << liner[i].to + 1 << ")" << " ";
	}
}

void find(bool visited[edges], line liner[edges], int arr[6][6], int& now_position, int& count, int& f_pos_count, line first_liner[edges], int & i)
{
	int min = 100;
	int min_pos = 0;

	for (int i = 0; i < edges; ++i)
	{
		if (!visited[i])
		{
			if (arr[f_pos][i] != 100 && now_position == f_pos)
			{
				first_liner[f_pos_count].from = f_pos;
				first_liner[f_pos_count].to = i;
				++f_pos_count;
			}
			if (min > arr[now_position][i])
			{
				min = arr[now_position][i];
				min_pos = i;
			}
		}
	}

	for (int i = 0; i < f_pos_count; ++i)
	{
		if (min > arr[first_liner[i].from][first_liner[i].to] && (first_liner[i].to != liner[0].to))
		{
			now_position = f_pos;
			++i;
			return;
		}
	}
	visited[min_pos] = true;
	liner[count].from = now_position;
	liner[count].to = min_pos;
	now_position = min_pos;
	++count;
}
