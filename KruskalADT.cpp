#include "Kruskal.h"

Kruskal::Kruskal()
{
	head = NULL;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		graph[i] = NULL;
		parent[i] = i;
	}
}

void Kruskal::addData(char start, int cost, char end)
{
	Node *newp = new Node(start, cost, end);

	Node *tmp;
	if (head == NULL)
	{
		head = newp;
	}
	else
	{
		tmp = head;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = newp;
	}

	Node *newp1 = new Node(start, cost, end);
	Node *tmp1;

	//알파벳일 경우 빼는 값을 0나 a로 바꾸기 전부
	if (graph[start - '0'] == NULL)
	{
		newp1->next = graph[start - '0'];
		graph[start - '0'] = newp1;
	}
	else
	{
		tmp1 = graph[start - '0'];
		while (tmp1->next != NULL)
		{
			tmp1 = tmp1->next;
		}
		tmp1->next = newp1;
	}
	Node *newp2 = new Node(end, cost, start);
	Node *tmp2;
	if (graph[end - '0'] == NULL)
	{
		newp2->next = graph[end - '0'];
		graph[end - '0'] = newp2;
	}
	else
	{
		tmp2 = graph[end - '0'];
	}
}

void Kruskal::sortData()
{
	Node *cur;
	Node *tmp;
	Node *min = NULL;

	for (cur = head; cur->next != NULL; cur = cur->next)
	{
		min = cur;
		for (tmp = cur->next; tmp != NULL; tmp = tmp->next)
		{
			if (min->cost > tmp->cost)
			{
				min = tmp;
			}
			else if (cur->cost == tmp->cost)
			{
				if (min->start > tmp->start)
				{
					min = tmp;
				}
			}
		}

		Node tmp1(cur->start, cur->cost, cur->end);

		cur->start = min->start;
		cur->cost = min->cost;
		cur->end = min->end;

		min->start = tmp1.start;
		min->cost = tmp1.cost;
		min->end = tmp1.end;
	}
}

void Kruskal::OutPutKruData()
{
	Node *cur = head;
	int cnt = 0;

	while (cur != NULL)
	{
		cnt += 1;
		if (cnt % 5 == 0)
		{
			cout << cur->start << ' ' << cur->cost << ' ' << cur->end;
			cout << endl;
		}
		else
		{
			cout << cur->start << ' ' << cur->cost << ' ' << cur->end;
			cout << " / ";
		}
		cur = cur->next;
	}
	cout << endl;
}

int Kruskal::get(int x)
{
	if (parent[x] == x)
	{
		return x;
	}
	else
	{
		return parent[x] = get(parent[x]);
	}
}

int Kruskal::Find(int u, int v)
{
	u = get(u);
	v = get(v);

	if (u == v)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void Kruskal::Union(int u, int v)
{
	u = get(u);
	v = get(v);

	if (u < v)
	{
		parent[v] = u;
	}
	else
	{
		parent[u] = v;
	}
}

void Kruskal::SolveKruskal()
{
	int sum = 0;
	Node *cur;
	int cnt = 0;

	for (cur = head; cur != NULL; cur = cur->next)
	{
		if (!Find(cur->start - '0', cur->end - '0'))
		{
			sum += cur->cost;
			cout << "Edge" << ++cnt << ": " << cur->start << ' ' << cur->cost << ' ' << cur->end << endl;
			Union(cur->start - '0', cur->end - '0');
		}
	}
	cout << endl;
	cout << "Total Cost : " << sum << endl;
}