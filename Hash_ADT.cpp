#include "Hash.h"

Hash myHash[NODE_CNT];

int Hash::hashKey(int key)
{
	return key % NODE_CNT;
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

		
	}
}