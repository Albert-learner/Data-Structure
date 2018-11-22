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
			cout << "입력할 데이터는 ? " << endl;
			cin >> num;
			insertKey(num);
			break;
		case 2:
			cout << "삭제할 데이터는 ? " << endl;
			cin >> num;
			deleteKey(num);
			break;
		case 3:
			printMatrix();
			break;
		case 4:
			cout << "찾을 데이터는 ? " << endl;
			cin >> num;
			finding(num);
			break;
		case 5:
			finish = 1;
			break;
		default:
			cout << "잘못된 입력입니다. 다시 입력하세요." << endl;
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

	while (found == false && loop == false) //찾지 못하거나 모두 탐색하지 못했을 때만 반복문 실행
	{
		count++;

		if (myHash[index].key == key && myHash[index].empty == false) //브로켓이 비어있지 않고, 데이터가 일치해야 존재
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
		cout << "이미 존재하는 데이터입니다." << endl;
		return; // no duplicated key
	}

	while (count != MAX_SIZE)
	{
		count++;
		if (myHash[index].empty == false) //비어있지 않으면 다음칸으로 이동
		{
			index = (index + 1) % MAX_SIZE;
		}
		else //비어있으면 insert
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
		cout << "존재하지 않는 데이터입니다." << endl;
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
		cout << key << "를 찾았습니다." << endl;
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
