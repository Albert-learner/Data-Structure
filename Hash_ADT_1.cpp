#include "Hash_1.h"

int Hash::hashKey(int key)
{
	return key % MAX_SIZE;
}

int Hash::findKey(int key)
{
	bool found = false;
	int idx = hashKey(key);
	bool loop = false;
	int cnt = 0;

	while (found == false && loop == false)
	{
		cnt++;

		if(table[idx]->key == key)
	}
}