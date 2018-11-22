#include <iostream>

#define MAX_SIZE 7

using namespace std;

class Hash
{
public:
	int key;
	bool empty;
	Hash() { empty = true; }
};

int findKey(int key);
void finding(int key);
int hashKey(int key);
void insertKey(int key);
void deleteKey(int key);
void printMatrix();

Hash myHash[MAX_SIZE];

int main()
{
	int input;
	int num;
	int finish = 0;
	while (1)
	{
		cout << "1.insert  2.delete   3.print  4.find    5.quit " << endl;
		cin >> input;

		switch (input)
		{
		case 1:
			cout << "�Է��� �����ʹ� ? " << endl;
			cin >> num;
			insertKey(num);
			break;
		case 2:
			cout << "������ �����ʹ� ? " << endl;
			cin >> num;
			deleteKey(num);
			break;
		case 3:
			printMatrix();
			break;
		case 4:
			cout << "ã�� �����ʹ� ? " << endl;
			cin >> num;
			finding(num);
			break;
		case 5:
			finish = 1;
			break;
		default:
			cout << "�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���." << endl;
			break;
		}
		if (finish)
			break;

	}
	printMatrix();
	return 0;
}

int findKey(int key)
{
	bool found = false;
	int index = hashKey(key);
	bool loop = false;
	int count = 0;

	while (found == false && loop == false) //ã�� ���ϰų� ��� Ž������ ������ ���� �ݺ��� ����
	{
		count++;

		if (myHash[index].key == key && myHash[index].empty == false) //������� ������� �ʰ�, �����Ͱ� ��ġ�ؾ� ����
			found = true;
		else
		{
			index = (index + 1) % MAX_SIZE;
			if (count == MAX_SIZE)
				loop = true;
		}
	}
	return found;
}

void insertKey(int key)
{
	int check = findKey(key);
	int index = hashKey(key);
	int count = 0;

	if (check == true)
	{
		cout << "�̹� �����ϴ� �������Դϴ�." << endl;
		return; // no duplicated key
	}

	while (count != MAX_SIZE)
	{
		count++;
		if (myHash[index].empty == false) //������� ������ ����ĭ���� �̵�
		{
			index = (index + 1) % MAX_SIZE;
		}
		else //��������� insert
		{
			myHash[index].key = key;
			myHash[index].empty = false;
			return;
		}
	}
	cout << "Hash Full!!!!!" << endl;
}

void deleteKey(int key)
{
	int check = findKey(key);
	int index = hashKey(key);
	int count = 0;

	if (!check)
	{
		cout << "�������� �ʴ� �������Դϴ�." << endl;
		return;
	}

	while (count != MAX_SIZE)
	{
		count++;
		if (myHash[index].key == key && myHash[index].empty == false)
		{
			myHash[index].empty = true;
			return;
		}
		else
		{
			index = (index + 1) % MAX_SIZE;
		}
	}
}

int hashKey(int key)
{
	return key % MAX_SIZE;
}

void finding(int key)
{
	bool found = false;
	int index = hashKey(key);
	bool loop = false;
	int count = 0;

	while (found == false && loop == false)
	{
		count++;

		if (myHash[index].key == key && myHash[index].empty == false)
			found = true;
		else
		{
			index = (index + 1) % MAX_SIZE;
			if (count == MAX_SIZE)
				loop = true;
		}
	}
	if (found == false)
		cout << "No data!!!" << endl;
	else
		cout << key << "�� ã�ҽ��ϴ�." << endl;
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
