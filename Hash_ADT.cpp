#include "Hash.h"

Hash myHash[MAX_SIZE];

int hashKey(int key)
{
	return key % MAX_SIZE;
}

int findKey(int key)
{
	bool found = false;
	int idx = hashKey(key);
	bool loop = false;
	int cnt = 0;

	while (found == false && loop == false)
	{
		cnt++;

		if (myHash[idx].key == key && myHash[idx].empty == false)
		{
			found = true;
		}
		else
		{
			idx = (idx + 1) % MAX_SIZE;
			if (cnt == MAX_SIZE)
			{
				loop = true;
			}
		}
	}
	return found;
}

void finding(int key)
{
	bool found = false;
	int idx = hashKey(key);
	bool loop = false;
	int cnt = 0;

	while (found == false && loop == false)
	{
		cnt++;

		if (myHash[idx].key == key && myHash[idx].empty == false)
		{
			found = true;
		}
		else
		{
			idx = (idx + 1) % MAX_SIZE;
			if (cnt == MAX_SIZE)
			{
				loop = true;
			}
		}
	}
	if (found == false)
	{
		cout << "No data!!!" << endl;
	}
	else
	{
		cout << key << "�� ã�ҽ��ϴ�." << endl;
	}
}

void insertKey(int key)
{
	int check = findKey(key);
	int idx = hashKey(key);
	int cnt = 0;

	if (check == true)
	{
		cout << "�̹� �����ϴ� �������Դϴ�." << endl;
		return;
	}
	else
	{
		while (cnt != MAX_SIZE)
		{
			cnt++;
			if (myHash[idx].empty == false)
			{
				idx = (idx + 1) % MAX_SIZE;
			}
			else
			{
				myHash[idx].key = key;
				myHash[idx].empty = false;
				return;
			}
		}
		cout << "Hash Full!!!!" << endl;
	}
}

void deleteKey(int key)
{
	int check = findKey(key);
	int idx = hashKey(key);
	int cnt = 0;

	if (!check)
	{
		cout << "�������� �ʴ� �������Դϴ�." << endl;
		return;
	}
	else
	{
		while (cnt != MAX_SIZE)
		{
			cnt++;
			if (myHash[idx].key == key && myHash[idx].empty == false)
			{
				myHash[idx].empty = true;
				return;
			}
			else
			{
				idx = (idx + 1) % MAX_SIZE;
			}
		}
	}
}

void printMatrix()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (myHash[i].empty == false)
		{
			cout << myHash[i].key << " ";
		}
		else
		{
			cout << "empty" << " ";
		}
	}
	cout << endl;
}