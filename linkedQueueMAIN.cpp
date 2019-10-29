#include "linkedQueue.h"

int main()
{
	linkedQueue lq;

	lq.enQueue(30);
	lq.enQueue(60);
	lq.enQueue(40);
	lq.enQueue(80);
	lq.enQueue(100);

	lq.displayQueue();
	lq.searchQueue(40);
	return 0;
}