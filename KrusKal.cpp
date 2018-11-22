#include "KrusKal.h"

KrusKal::KrusKal()
{
	head = NULL;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		graph[i] = NULL;
		parent[i] = i;
	}
}

void KrusKal::addData(char start, int cost, char end)
{
	Node *newp = new Node(start, cost, end);
	
	Node *temp;
	if (head == NULL)
	{
		head = newp; 
	}
	else
	{
		temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newp;
	}
	
	Node *newp1 = new Node(start, cost, end);
	Node *temp1;
	if (graph[start - 'A'] == NULL)
	{
		newp1->next = graph[start - 'A'];
		graph[start - 'A'] = newp1;
	}
	else
	{
		temp1 = graph[start - 'A'];
		while (temp1->next != NULL)
		{
			temp1 = temp1->next;
		}
		temp1->next = newp1;
	}
	Node *newp2 = new Node(end, cost, start);
	Node *temp2;
	if (graph[end - 'A'] == NULL)
	{
		newp2->next = graph[end - 'A'];
		graph[end - 'A'] = newp2;
	}
	else
	{
		temp2 = graph[end - 'A'];
	}
}


void KrusKal::sortData()
{
	Node *now;
	Node *temp;
	Node *min = NULL;

	for (now = head; now->next != NULL; now = now->next)
	{
		min = now;

		for (temp = now->next; temp != NULL; temp = temp->next)
		{
			if (min->cost > temp->cost)
				min = temp;
		}

		Node temp1(now->start, now->cost, now->end);

		now->start = min->start;
		now->cost = min->cost;
		now->end = min->end;

		min->start = temp1.start;
		min->cost = temp1.cost;
		min->end = temp1.end;
	}
}

void KrusKal::OutPutKRUData()
{
	Node *now = head;

	while (now != NULL)
	{
		cout << now->start << ' ' << now->cost << ' ' << now->end;
		cout << ",   ";
		now = now->next;
	}
	cout << endl;
}

int KrusKal::get(int x)
{
	if (parent[x] == x)
		return x;
	return parent[x] = get(parent[x]);
}

int KrusKal::Find(int u, int v)
{
	u = get(u);
	v = get(v);

	if (u == v)
		return 1;
	else
		return 0;
}

void KrusKal::Union(int u, int v)
{
	u = get(u);
	v = get(v);

	if (u < v)
		parent[v] = u;
	else
		parent[u] = v;
}

void KrusKal::SolveKrusKal()
{
	int sum = 0;
	Node *now;
	int count = 0;

	for (now = head; now != NULL; now = now->next)
	{
		if (!Find(now->start - 'A', now->end - 'A'))
		{
			sum += now->cost;
			cout << "Edge" << ++count << ": " << now->start << ' ' << now->cost << ' ' << now->end << endl;
			Union(now->start - 'A', now->end - 'A');
		}
	}
	cout << endl;
	cout << "Total Cost: " << sum << endl;
}